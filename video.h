#ifndef VIDEO_H
#define VIDEO_H
#include<string>
#include<iostream>
#include<sstream>

#include"media.h"

class Video : public Media
{
private:
    int duree;
public:
    Video();
    Video(string,int,string,int);
    Video(const Video&);
    virtual ~Video(){}
    Video& operator=(const Video&);

    virtual void show()const;
    virtual void get(string&)const;

    virtual int getDuree()  const;
    virtual void setDuree(int);
    virtual void showDuree()const;

    virtual void play()const;
    virtual void write(std::ofstream &f);
    virtual void read(std::ifstream &f);
};

#endif // VIDEO_H
