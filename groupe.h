#ifndef GROUPE_H
#define GROUPE_H

#include<string>
#include<iostream>
#include<list>
//#include"intrusive_ptr.h"
#include"media.h"


//class Groupe : public list<Media*>
//template <class T>
class Groupe : public list<intrusive_ptr<Media> >,public Pointable
{
private:
   string nom;
public:
    Groupe();
    Groupe(const string&);
    ~Groupe();
    string getNom()const;
    void supprime(const string&);
    void showNom()  const;
    void show()const;

};

#endif // GROUPE_H
