/*
 * Base class
 */
#include "media.h"
#include<iostream>
inline void skipnl(std::ifstream& f) {
    f.ignore(numeric_limits<streamsize>::max(),'‘\n’');
}

Media::Media():nom("media1"),date(0),ficher("inf224"){}

Media::Media(string _nom,int _date,string _ficher){
    nom=_nom;
    date=_date;
    ficher=_ficher;
}

Media::~Media(){
    cout<<endl;
    cout<<nom<<'\t'<<"est detruit"<<endl;
}

/**
 * @brief copy constructor
 * @param m a objet of class media
 */
Media::Media(const Media& m){
    nom=m.nom;
    date=m.date;
    ficher=m.ficher;
}

Media& Media::operator=(const Media& m){
    nom=m.nom;
    date=m.date;
    ficher=m.ficher;
    return *this;
}

/**
 * @brief get the name of a media
 * @return string, the name of a media
 */
string Media::getNom() const {
    return nom;
}

/**
 * @brief get the date of a media
 * @return int,the date of a media
 */
int Media::getDate()  const {
    return date;
}

/**
 * @brief get the path of a media
 * @return string,the path of a media
 */
string Media::getFicher() const {
    return ficher;
}

/**
 * @brief set the name of a media
 * @param string _nom
 */
void Media::setNom(const string& _nom){
    nom=_nom;
}

/**
 * @brief set the name of a media
 * @param int _date
 */
void Media::setDate(int _date){
    date=_date;
}

/**
 * @brief set the path of a media
 * @param string _ficher
 */
void Media::setFicher(string _ficher){
    ficher=_ficher;
}

/**
 * @brief display the name of a media
 */
void Media::showNom()  const {
    cout<<"Nom du media est:"<<nom<<endl;
}

/**
 * @brief display the date of a media
 */
void Media::showDate() const{
    cout<<"Date d'aquisation est:"<<date<<endl;
}

/**
 * @brief display the path of a media
 */
void Media::showFicher()const{
    cout<<"Nom du ficher est:"<<ficher<<endl;
}

/**
 * @brief display all parameters of a media
 */
void Media::show()const{
    cout<<"Nom du media est:"<<nom<<endl;
    cout<<"Date d'aquisation est:"<<date<<endl;
    cout<<"Nom du ficher est:"<<ficher<<endl;
}

/**
 * @brief get all parameters of a media
 * @param s, string receive all parameters of a media, passage by reference
 */
void Media::get(string& s)const{
    s="Nom du media est:";
    s=s+string(nom);
    s=s+"Date d'aquisation est:";
    //s=s+string(date);
    s=s+"Nom du ficher est:";
    s=s+string(ficher);
}

/**
 * @brief set the lieu of a media
 */
void Media::setLieu(string)
{

}

/**
 * @brief set the duree of a media
 */
void Media::setDuree(int)
{
}

/**
 * @brief write an objet of media in a file
 * @param f ofstream
 */
void Media::write(std::ofstream& f){
    if (f.is_open())
      {
        f<<nom<<'\n'<<date<<'\n'<<ficher<<'\n';
        f.close();
      }
      else
      {
        std::cout << "Error opening file";
      }
}

/**
 * @brief read parameters of an objet from a file
 * @param f ifstream
 */
void Media::read(std::ifstream &f){
    f>>nom; skipnl(f);

    f>>date; skipnl(f);

    f>>ficher; skipnl(f);

}


