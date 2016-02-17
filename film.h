#ifndef FILM_H
#define FILM_H
#include<string>
#include<iostream>
#include<sstream>

#include"video.h"

class Film : public Video
{
private:
    int* tab;
    int num;
public:
    Film();
    Film(string,int,string,int,int);
    virtual ~Film();

    void setTab(int* _tab,int _num);
    int getTab(int* _tab)const;
    void show()const;
    void get(string&)const;

    Film(const Film& );
    Film& operator=(const Film&);

    virtual void play()const;
    virtual void write(std::ofstream &f);
    virtual void read(std::ifstream &f);

};

#endif // FILM_H
