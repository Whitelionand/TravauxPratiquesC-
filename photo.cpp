/*
 *
 * \file
 * class photo
 */
#include "photo.h"
#include <cstdlib>

inline void skipnl(std::ifstream& f) {
    f.ignore(numeric_limits<streamsize>::max(),'‘\n’');
}

Photo::Photo(string _nom, int _date, string _ficher, string _lieu):Media(_nom,_date,_ficher){

    lieu=_lieu;
}

//Photo::~Photo(){}
Photo::Photo(const Photo& p):Media(p){
    lieu=p.lieu;
}

Photo& Photo::operator=(const Photo& p){
    Media::operator=(p);
    lieu=p.lieu;
    return *this;
}

/**
 * @brief get lieu of a photo
 * @return string
 */
string Photo::getLieu()  const{
    return lieu;
}

/**
 * @brief set lieu of a photo
 * @param string _lieu
 */
void Photo::setLieu(string _lieu){
    lieu=_lieu;
}

/**
 * @brief display lieu of a photo
 */
void Photo::showLieu()const{
    cout<<"Lieu est:"<<lieu<<endl;
}

/**
 * @brief display all parameters of a photo
 */
void Photo::show()const{
    cout<<"Nom du photo est:"<<nom<<endl;
    cout<<"Date d'aquisation est:"<<date<<endl;
    cout<<"Nom du ficher est:"<<ficher<<endl;
    cout<<"Lieu est:"<<lieu<<endl;
}

/**
 * @brief get all parameters of a photo
 * @param s, string, receive all parameters of a photo, passage by reference
 */
void Photo::get(string & s) const{
    string str;
    stringstream stream;
    stream<<date;
    stream>>str;
    s="Nom du photo est:";
    s=s+string(nom);
    s=s+"Date d'aquisation est:";
    s=s+str;
    s=s+"Nom du ficher est:";
    s=s+string(ficher);
    s=s+"Lieu est:";
    s=s+string(lieu);
}

/**
 * @brief display a photo
 */
void Photo::play()const{
    string temp="myplayer ";
    temp+=nom;
    temp+=" &";
    const char* ch=temp.c_str();
    system(ch);
    cout<<"Le contenu du photo"<<'\t'<<nom<<'\t'<<"est"<<endl;
}

/**
 * @brief write a photo in a file
 * @param f ofstream
 */
void Photo::write(std::ofstream &f){
    if (f.is_open())
      {
        Media::write(f);
        f<<lieu<<'\n';
        f.close();
      }
      else
      {
        std::cout << "Error opening file";
      }

}

/**
 * @brief read parameters of a photo from a file
 * @param f ifstream
 */
void Photo::read(std::ifstream &f){
    Media::read(f);
    f>>lieu; skipnl(f);
}
