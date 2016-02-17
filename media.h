/*
 *
 *class media
 */
#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#include<iostream>
#include<fstream>
#include <limits>

#define SMART_PTR_DEBUG
#define SMART_PTR_DEBUG_MESSAGES
#include"intrusive_ptr.h"
using namespace std;

class Media:public Pointable
{
protected:
    string nom;
    int date;
    string ficher;
public:
    Media();
    Media(string nom,int date,string ficher);
    Media(const Media&);
    Media& operator=(const Media&);
    virtual ~Media();
    virtual string getNom()   const;
    virtual int    getDate()  const;
    virtual string getFicher()const;
    virtual void setNom(const string& nom);
    virtual void setDate(int date);
    virtual void setFicher(string ficher);
    virtual void showNom()  const;
    virtual void showDate() const;
    virtual void showFicher()const;
    virtual void show()const;
    virtual void play()const=0;
    virtual void get(string&)const;

    virtual void setLieu(string);
    virtual void setDuree(int);

    virtual void write(std::ofstream &f);
    virtual void read(std::ifstream &f);

};

#endif // MEDIA_H
/*! \Multimedia player
 *
 *
 *
 *
 *
 *
 *
 *
 */
