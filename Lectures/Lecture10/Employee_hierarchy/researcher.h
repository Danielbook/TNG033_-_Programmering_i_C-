/*******************************************
* TNG033: Fö 10                            *
* Class Reseracher                         *
* ******************************************/


#ifndef RESEARCHER_H_INCLUDED
#define RESEARCHER_H_INCLUDED

#include <iostream>

using namespace std;

class Researcher : public Employee
{
public:

    //constructor
    Researcher(string s = "", string a = "")
        : Employee(s) //call constructor of base class
    {
        area = a;
    };


    void display() const
    {
        Employee::display(); //call display function from class Employee

        cout << "Area of research: " << area << endl;
    } ;

protected:
    string area;  //area of research
};

#endif // RESEARCHER_H_INCLUDED
