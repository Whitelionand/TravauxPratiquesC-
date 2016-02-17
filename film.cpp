/*
 *
 *\file
 *class film
 *
 */
#include "film.h"

inline void skipnl(std::ifstream& f) {
    f.ignore(numeric_limits<streamsize>::max(),'‘\n’');
}

Film::Film(){
    tab=NULL;
    num=1;
}

Film::Film(string _nom,int _date,string _ficher,int _duree,int _num):Video(_nom,_date,_ficher,_duree){
    tab=NULL;
    num=_num;
}

Film::Film(const Film& f):Video(f){
    num=f.num;
/*    if(tab!=NULL){
        delete tab;
    }*/
    tab=new int[num];
    for(int k=0;k<num;k++){
        tab[k]=f.tab[k];
    }

}

Film& Film::operator=(const Film& f){
    Video::operator=(f);//implicite
    num=f.num;
    if(tab!=NULL){
        delete [] tab;
    }
    tab=new int[num];
    if(f.tab!=NULL){
        for(int k=0;k<num;k++){
            tab[k]=f.tab[k];
        }
    }
    else tab=NULL;
    return *this;

}

Film::~Film(){
    delete [] tab;
}

/**
 * @brief set the tableau de duree of a film
 * @param _tab a string of int (a pointer of int)
 * @param _num specifies the length of the table
 */
void Film::setTab(int* _tab,int _num){
    num=_num;
    if(tab!=NULL){
        delete tab;
    }
    tab=new int[num];
    for(int k=0;k<num;k++){
        tab[k]=_tab[k];
    }

}

/**
 * @brief get the tableau de duree of a film
 * @param _tab a pointer of int
 * @return int the length of the table
 */
int Film::getTab(int* _tab)const{
    _tab=tab;
    return num;
}

/**
 * @brief display all the parameters of a film
 */
void Film::show()const{
    cout<<"Nom du video est:"<<nom<<endl;
    cout<<"Date d'aquisation est:"<<date<<endl;
    cout<<"Nom du ficher est:"<<ficher<<endl;
    showDuree();
    cout<<"Numbre du chqpitre:"<<num<<endl;
    /*cout<<"Le tableau de duree:"<<endl;
    for(int k=0;k<num;k++){
        cout<<tab[k]<<"\t";
    }*/
    cout<<endl;
}

/**
 * @brief get all the parameters of a film
 * @param s a reference of a string
 */
void Film::get(string & s) const{

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
    stream<<num;
    stream>>str2;
    s=s+"Numbre du chqpitre:";
    s=s+str2;
}

/**
 * @brief play a film
 */
void Film::play()const{

    cout<<"Le contenu du film"<<'\t'<<nom<<'\t'<<"est:"<<endl;

}

void Film::write(std::ofstream &f){
    if (f.is_open())
      {
        f<<num;
         int i;
         Media::write(f);
         for (i=0;i<num-1;i++)
             f<<tab[i]<<'\n';
         f.close();
      }
      else
      {
        std::cout << "Error opening file";
      }
}

void Film::read(std::ifstream &f){
    int i;
    Media::read(f);
    f>>num; skipnl(f);
    for (i=0;i<num-1;i++)
        f>>tab[i];skipnl(f);
}
