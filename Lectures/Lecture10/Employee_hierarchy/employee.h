/*******************************************
* TNG033: Fö 10                            *
* Class Employee                           *
* ******************************************/

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <iostream>

using namespace std;

class Employee
{
public:

    //constructor
    explicit Employee(string s = "") //works as a default constructor
        : name(s)
    {  };

    //~Employee() { };  //not needed

    void set_name(const string s)
    {
        name = s;
    };

    void display() const
    {
        cout << "Name: " << name << endl;
    } ;

protected:  //data members are accessible to the memeber functions of derived classes
    string name;
};


#endif // EMPLOYEE_H_INCLUDED
