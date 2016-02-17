/*
 *
 * \file
 * class groupe
 *
 */
#include "groupe.h"


Groupe::Groupe():list<intrusive_ptr<Media> >(),Pointable()
{
    //nom="Paris";
}

Groupe::Groupe(const string& n):list<intrusive_ptr<Media> >(),Pointable()
{
   nom=n;
}

Groupe::~Groupe()
{
}

/**
 * @brief get the name of a groupe
 * @return string, the name of a groupe
 */
string Groupe::getNom()const{
    return nom;
}

/**
 * @brief display the name of a groupe
 */
void Groupe::showNom()const{
    cout<<"Le nom du groupe est:"<<nom<<endl;

}

/**
 * @brief delete a member of a group with the given name
 * @param n string, the name of the member to be deleted
 */
void Groupe::supprime(const string& n)
{
    for (Groupe::iterator it=this->begin();it!=this->end();it++){
        if((*it)->getNom()==n)
        {
            erase(it);
            it--;

        }

    }
}

/**
 * @brief display all the members of a groupe
 */
void Groupe::show()const{


    for (Groupe::const_iterator it=this->begin();it!=this->end();++it){
        (*it)->show();
        cout<<endl;
         }

}



