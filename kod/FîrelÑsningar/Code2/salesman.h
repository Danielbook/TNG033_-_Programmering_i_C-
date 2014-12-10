/********************************************************************
* TNG033, Fö 2                                                      *
* header file salesman.h                                            *
* Operator overloading is used                                      *
* *******************************************************************/

#ifndef SALESMAN_H_INCLUDED
#define SALESMAN_H_INCLUDED

#include <iostream>     //basic input output
#include <string>

using namespace std;

/*******************************
*    Declarations              *
********************************/

struct Salesman
{
    string name;
    double sales;  //total of sales
};

ostream& operator<<(ostream &out, const Salesman &S);

istream& operator>>(istream &in, Salesman& S);

//Compare salesman names using lexicographical order
bool operator>(const Salesman& S1, const Salesman& S2);


#endif // SALESMAN_H_INCLUDED
