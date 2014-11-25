/*******************************************
* TNG033: Fö 10                            *
* Class Teacher                            *
* ******************************************/

#ifndef TEACHER_H_INCLUDED
#define TEACHER_H_INCLUDED

#include <iostream>

#include "employee.h"

using namespace std;

class Teacher : public Employee
{
public:

    //constructor
    //s is teacher's name
    //c is a "list" (an array) of courses offered by the teacher
    //n is the number of courses offered
    Teacher(string s="", string *c = nullptr, int n = 0);

    //copy constructor
    Teacher(const Teacher &T);

    //destructor
    ~Teacher();

    //assignment operator
    const Teacher& operator=(const Teacher &T);

    bool gives_course(string code) const;

    void display() const;

protected:
    string *courses;  //array of course codes given by the teacher
    int n_courses;    //number of courses given by the teacher
};

#endif // TEACHER_H_INCLUDED
