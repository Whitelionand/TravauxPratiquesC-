/*
 *
 * \file
 * The main file, to run the server
 * \author
 * CHANG Kaiwen kaiwen.chang@telecom-paristech.fr
 */
#include"media.h"
#include<iostream>
#include"photo.h"
#include"video.h"
#include<string>
#include"film.h"
#include"groupe.h"
#include<list>
#include"intrusive_ptr.h"
#include"gestion.h"
#include"TCPServer.h"
#include<fstream>
int main(){


    /*intrusive_ptr<Gestion> g=new Gestion();
    string n="Paris";
    string n2="Marseille";
    intrusive_ptr<Media> p=NULL;
    g->creatPhoto(n,p);
    intrusive_ptr<Media> v=NULL;
    g->creatVideo(n2,v);

    string n3="famille";
    intrusive_ptr<Groupe> pg=NULL;
    g->creatGroupe(n3,pg);
    intrusive_ptr<Media> m1=new Video("video1",100,"inf224",200);
    intrusive_ptr<Media> m2=new Photo("photo1",300,"inf224","Marseille");
    pg->push_back(m1);
    pg->push_back(m2);
    pg->push_back(p);

    string n4="travaille";
    intrusive_ptr<Groupe> pg2=NULL;
    g->creatGroupe(n4,pg2);
    intrusive_ptr<Media> m3=new Film("f1",600,"inf224",1000,10);
    intrusive_ptr<Media> m4=new Video("video2",100,"inf224",300);
    pg2->push_back(m3);
    pg2->push_back(m4);
    pg2->push_back(v);

    string r;
    g->searchm(n2,r);
    cout<<r<<endl;
    g->supprimem(n);
    g->searchg(n3);
    g->supprimeg(n4);

    g->play(n2);*/

    //13test

    TCPServer server;
    server.createData();
   server.run(3331);

    /*14 test
   Photo photo1("photo1",100," inf224"," Paris");
   std::ofstream of;
   of.open("test.txt");
   photo.write(of);
   std::ifstream ifs;
   ifs.open("test.txt");*/

return 0;

}
