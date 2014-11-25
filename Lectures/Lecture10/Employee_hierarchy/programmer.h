/*******************************************
* TNG033: Fö 10                            *
* Class Programmer                         *
* ******************************************/

#ifndef PROGRAMMER_H_INCLUDED
#define PROGRAMMER_H_INCLUDED

#include <iostream>

#include "teacher.h"

using namespace std;

class Programmer : public Teacher
{
public:

    //constructor
    Programmer(string s = "", string *c = nullptr, int n = 0, string f = "C++");


    //Provide by the compiler
    //Thus, no need to program copy constructor for class Programmer
    Programmer(const Programmer &p);


    //Provide by the compiler
    //Thus, no need to program operator= for Programmer
    const Programmer& operator=(const Programmer &p);


    void display() const;

protected:
    string fav_lang;  //favourite programming language
};


#endif // PROGRAMMER_H_INCLUDED
