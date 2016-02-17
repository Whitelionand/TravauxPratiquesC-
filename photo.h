#ifndef PHOTO_H
#define PHOTO_H
#include<string>
#include<iostream>
#include<sstream>
#include"media.h"

class Photo : public Media
{
private:
    string lieu;
public:
    Photo():Media(){ lieu = "paris"; }
    Photo(string,int,string,string);
    Photo(const Photo&);
    virtual ~Photo(){}
    Photo& operator=(const Photo&);

    virtual void show() const;
    virtual void get(string &) const;

    virtual string getLieu()  const;
    virtual void setLieu(string);
    virtual void showLieu()const;

    virtual void play()const;
    virtual void write(std::ofstream &f);
    virtual void read(std::ifstream &f);

};

#endif // PHOTO_H
