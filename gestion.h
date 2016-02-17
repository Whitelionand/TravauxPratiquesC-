#ifndef GESTION_H
#define GESTION_H
#include<map>
#include<string>
#include "boost/variant.hpp"
#include"intrusive_ptr.h"
#include"media.h"
#include"photo.h"
#include"video.h"
#include"film.h"
#include"groupe.h"

class Gestion:public Pointable
{
private:
    map<string,intrusive_ptr<Media> > tablem;
    map<string,intrusive_ptr<Groupe> > tableg;

public:
    Gestion();
    ~Gestion();

    void creatPhoto(const string&, intrusive_ptr<Media>&);
    void creatVideo(const string&,intrusive_ptr<Media>&);
    void creatFilm(const string&,intrusive_ptr<Media>&);
    void creatGroupe(const string&,intrusive_ptr<Groupe>&);
    void supprimeg(const string&);
    void supprimem(const string&);
    void searchg(const string&);
    void searchm(const string&, string&);
    void play(const string&);
};

#endif // GESTION_H
