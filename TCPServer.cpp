//
//  TCPServer.cpp: TCP/IP INET Server.
//  (c) Eric Lecolinet - Telecom ParisTech - 2013.
//  http://www.telecom-paristech.fr/~elc
//

#include "TCPServer.h"
#include <unistd.h>
#include <iostream>
#include <sstream>
using namespace std;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Hook for TCPServer::startReadMessages() (see TCPServer::run())

struct TCPServerHook {
  TCPServerHook(TCPServer* _server, Socket* _sock)
  : server(_server), sock(_sock) {}
  TCPServer* server;
  Socket* sock;
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

TCPServer::TCPServer() : servsock() {
  pthread_rwlock_init(&lock, NULL);
  intrusive_ptr<Gestion> g=NULL;
}

TCPServer::~TCPServer() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int TCPServer::run(int port)
{
  // lier le ServerSocket a ce port
  int status = servsock.bind(port);
  
  if (status < 0) {
    cerr << "TCPServer: can't bind on port: "<<port<<" status="<<status<< endl;
    return status;  // valeur negative, voir Socket::bind()
  }

  // ignorer le signal SIGPIPE qui avorterait le serveur en cas d'erreur reseau
  servsock.ignoreSigPipe();
  
  while (true) {
    Socket* sock = servsock.accept();

    if (sock == NULL) {
      cerr << "TCPServer: accept() failed" << endl;
      continue;  // continue va a la prochaine iteration de while()
    }

    // lancer la lecture des messages de ce socket dans un thread.
    // pthread_create() cree un thread qui appelle la methode statique
    // startReadMessages() avec un argument de type (void*) qui est en fait
    // un TCPServerHook*. Ceci permet a startReadMessages() d'appeller la
    // methode d'instance readMessages() avec les argument adequats.

    TCPServerHook* hook = new TCPServerHook(this, sock);
    pthread_t tid;
    
    int status = pthread_create(&tid, NULL, startReadMessages, hook);
    if (status < 0)
      cerr << "TCPServer: pthread_create() failed" << endl;
  }
  
  pthread_exit(NULL);
  return 0;  // OK
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// called by pthread_create()

void* TCPServer::startReadMessages(void* _hook)
{
  TCPServerHook* hook = static_cast<TCPServerHook*>(_hook);
  hook->server->readMessages(hook->sock);
  delete hook;
  return NULL;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void TCPServer::readMessages(Socket* sock)
{
  SocketBuffer sockbuf(sock);
  
  while (true) {
    string message, response;
    
    // lire les données envoyées par le client
    // SocketBuffer::readLine() lit jusqu'au premier '\n' (qui est supprimé)
    ssize_t received = sockbuf.readLine(message);
    
    if (received < 0) {
      closeSocketAndThread(sock, "read error");
      continue;
    }
    
    if (received == 0) {
      closeSocketAndThread(sock, "connection closed by client");
      continue;
    }
    
    // traiter le message et retourner la reponse
    // ferme la connection si la valeur de retour est false
    if (! processMessage(message, response)) {
      closeSocketAndThread(sock, "closing connection with client");
      continue;
    }
    
    // toujours envoyer une reponse au client (sinon il va se bloquer)
    // SocketBuffer::writeLine() envoie tout et rajoute '\n'
    ssize_t sent = sockbuf.writeLine(response);
    
    if (sent < 0) {
      closeSocketAndThread(sock,"write error");
      continue;
    }
    
    if (sent == 0) {
      closeSocketAndThread(sock, "connection closed by client");
      continue;
    }
  }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void TCPServer::closeSocketAndThread(Socket* sock, const char* msg)
{
  cerr << "TCPServer: " << msg << " on socket: "<< sock << endl;
  delete sock;          // detruit le socket (NB: le destr fait sock.close())
  pthread_exit(NULL);   // termine le thread
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Traite le message 'message' et retourne la reponse 'response' ainsi qu'un
// booleen (par return) qui indique si la connection avec le client doit se
// poursuivre (true) ou etre fermée (false).
//
// Cette fonction peut etre executee en parallele par plusieurs threads sauf si
// le verrou 'lock' est bloqué en mode WRITE

bool TCPServer::processMessage(const string& message, string& response)
{
  // cette variable indique si la commande modifie les donnees du programme
  // par defaut on suppose que non
    string command;
    string text;
    stringstream ss(message);
    ss>>command>>text;
    cout<<command<<endl;
    cout<<text<<endl;
  if (command=="search")
  {
      string name=text;
      g->searchm(name,response);
  }
  else if(command=="play")
  {
      string name=text;
      g->play(name);
      response=name+"est joue";
  }
  else
  {
      response = "OK: ";
      response += message;
  }





  bool change_data = false;
  
  // supposons que la commande "deletePhotos" modifie les donnees
  if (message == "deletePhotos") change_data = true;
  
  // suivant le cas, bloquer le verrou en mode WRITE ou en mode READ
  if (change_data)
    pthread_rwlock_wrlock(&lock);  // bloque en mode WRITE
  else
    pthread_rwlock_rdlock(&lock);  // bloque en mode READ
  
  
  // executer la commande et calculer la reponse
  // pour l'instant on se contente de prefixer le message par "OK: "
  cout << "TCPServer: message: " << message << endl;

  // sleep(8);                    // sert uniquement a tester le verrou
  cout << "TCPServer:TCPServer response: " << response << endl;
  
  
  // debloque le verrou (attention ne pas oublier cette ligne !)
  pthread_rwlock_unlock(&lock);

  // retourner false pour fermer la connexion
  return true;
}

void TCPServer::createData(){

    g=new Gestion();
    string n1="photo1";
    string n2="photo2";
    string n3="video1";
    string n4="video2";
    string n5="film1";
    string n6="film2";
    intrusive_ptr<Media> p1=NULL;
    intrusive_ptr<Media> p2=NULL;
    intrusive_ptr<Media> p3=NULL;
    intrusive_ptr<Media> p4=NULL;
    intrusive_ptr<Media> p5=NULL;
    intrusive_ptr<Media> p6=NULL;
    g->creatPhoto(n1,p1);
    g->creatPhoto(n2,p2);
    g->creatVideo(n3,p3);
    g->creatVideo(n4,p4);
    g->creatFilm(n5,p5);
    g->creatFilm(n6,p6);
    p1->setDate(100);
    p1->setFicher("inf224");
    p1->setLieu("Marseille");
    p3->setDate(100);
    p3->setFicher("inf224");
    p3->setDuree(200);
    p5->setDate(600);
    p5->setFicher("inf224");
    p5->setDuree(1000);


    string ng1="famille";
    intrusive_ptr<Groupe> pg=NULL;
    g->creatGroupe(ng1,pg);

    pg->push_back(p1);
    pg->push_back(p2);
    pg->push_back(p3);

    string ng2="travail";
    intrusive_ptr<Groupe> pg2=NULL;
    g->creatGroupe(ng2,pg2);

    pg2->push_back(p4);
    pg2->push_back(p5);
    pg2->push_back(p6);

}

