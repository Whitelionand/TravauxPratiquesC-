/*
 *
 * \file
 * class gestion
 */
#include "gestion.h"

Gestion::Gestion():Pointable()
{

}

Gestion::~Gestion()
{
}

/**
 * @brief create a photo
 * @param n the name of a photo
 * @param p a smart pointer of media, passage by reference
 */
void Gestion::creatPhoto(const string& n,intrusive_ptr<Media>& p )
{
    p=new Photo();
    p->setNom(n);
    tablem.insert(std::make_pair(p->getNom(),p));

}

/**
 * @brief create a video
 * @param n the name of a video
 * @param p a smart pointer of media, passage by reference
 */
void Gestion::creatVideo(const string& n,intrusive_ptr<Media>& p)
{
    p=new Video();
    p->setNom(n);
    tablem.insert(std::make_pair(p->getNom(),p));

}

/**
 * @brief create of a film
 * @param n the name of a film
 * @param p a smart pointer of media, passage by reference
 */
void Gestion::creatFilm(const string& n,intrusive_ptr<Media>& p)
{
    p=new Film();
    p->setNom(n);
    tablem.insert(std::make_pair(p->getNom(),p));

}

/**
 * @brief create a groupe
 * @param n the name of a groupe
 * @param p a smart pointer of Groupe, passage by reference
 */
void Gestion::creatGroupe(const string& n,intrusive_ptr<Groupe>& p)
{
    p=new Groupe(n);
    tableg.insert(std::make_pair(p->getNom(),p));
   /* for (Groupe::iterator it=p->begin();it!=p->end();it++){
        creat(*it)->getNom()
    }*/

}

/**
 * @brief delete a groupe with the given name
 * @param k string the name of the groupe to be deleted
 */
void Gestion::supprimeg(const string& k)
{
    map<string,intrusive_ptr<Groupe> >::iterator it=tableg.find(k);
    if (it==tableg.end()) cout << "pas trouvé" << endl;
    else
    {
        tableg.erase(k);
        cout<<"Le groupe"<<'\n'<<k<<'\n'<<"est supprimee"<<endl;
    }
}

/**
 * @brief delete a member of media with the given name
 * @param k string the name of the member to be deleted
 */
void Gestion::supprimem(const string& k)
{
    for(map<string,intrusive_ptr<Groupe> >::iterator it=tableg.begin();it!=tableg.end();++it)
    {
        it->second->supprime(k);

    }
    tablem.erase(k);
}

/**
 * @brief search a groupe with the given name
 * @param k string, the name of the groupe
 */
void Gestion::searchg(const string& k){
    map<string,intrusive_ptr<Groupe> >:: iterator it=tableg.find(k);
    if (it==tableg.end())
        cout << "pas trouvé" << endl;
    else
    {   cout<<"Le groupe est:";
        it->second->showNom();
        it->second->show();
    }
}

/**
 * @brief search a member with the given name
 * @param k string, the name of the member
 * @param r return all parameters of the member found
 */
void Gestion::searchm(const string& k,string& r){
    map<string,intrusive_ptr<Media> >::iterator it=tablem.find(k);
    if (it==tablem.end())
        r="pas trouvé";
    else
    {
        it->second->show();
        it->second->get(r);
    }
}

/**
 * @brief play a media with the given name
 * @param k the name of the media to be played
 */
void Gestion::play(const string& k)
{
    map<string,intrusive_ptr<Media> >::iterator it=tablem.find(k);
    if (it==tablem.end()) cout << "pas trouvé" << endl;
    else it->second->play();
}

