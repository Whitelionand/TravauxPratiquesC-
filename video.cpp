/*
 *
 *\file
 *class video
 */
#include "video.h"

inline void skipnl(std::ifstream& f) {
    f.ignore(numeric_limits<streamsize>::max(),'‘\n’');
}

Video::Video(){
    duree=0;
}


Video::Video(string _nom,int _date,string _ficher,int _duree):Media(_nom,_date,_ficher){

    duree=_duree;
}

Video::Video(const Video& v):Media(v){
  //  Media::Media(v);
    duree=v.duree;
}

Video& Video::operator=(const Video& v){
    Media::operator=(v);
    duree=v.duree;
    return *this;
}

/**
 * @brief get the duree of a video
 * @return int,the duree of a video
 */
int Video::getDuree()  const{
    return duree;
}

/**
 * @brief set the duree of a video
 * @param int _duree
 */
void Video::setDuree(int _duree) {
    duree=_duree;
}

/**
 * @brief display the duree of a vedio
 */
void Video::showDuree()const{
    cout<<"Duree est:"<<duree<<endl;
}

/**
 * @brief display all parameters of a video
 */
void Video::show()const{

    cout<<"Nom du video est:"<<nom<<endl;
    cout<<"Date d'aquisation est:"<<date<<endl;
    cout<<"Nom du ficher est:"<<ficher<<endl;
    cout<<"Duree est:"<<duree<<endl;
}

/**
 * @brief get all parameters of a video
 * @param s string, passage by reference
 */
void Video::get(string & s) const{
    /*string str,str2;
    sprintf(str,"%d",date);
    sprintf(str2,"%d",duree);*/
    stringstream stream;
    string str,str2;
    stream<<date;
    stream>>str;
    s="Nom du video est:";
    s=s+string(nom);
    s=s+"Date d'aquisation est:";
    s=s+str;
    s=s+"Nom du ficher est:";
    s=s+string(ficher);
    stream.clear();
    stream<<duree;
    stream>>str2;
    s=s+"Duree est:";
    s=s+str2;
}

/**
 * @brief play a video
 */
void Video::play()const{

    cout<<"Le contenu du video"<<'\t'<<nom<<'\t'<<"est:"<<endl;

}

void Video::write(std::ofstream &f){
    if (f.is_open())
      {
        Media::write(f);
        f<<duree<<'\n';
        f.close();
      }
      else
      {
        std::cout << "Error opening file";
      }
}

/**
 * @brief read parameters of a video from a file
 * @param f ifstream
 */
void Video::read(std::ifstream &f){
    Media::read(f);
    f>>duree; skipnl(f);
}
