/********************************************************************
* TNG033, Fö 2                                                      *
* source file salesman.cpp                                          *
* Implements the functions declared in salesman.h                   *
* *******************************************************************/

#include <iomanip>
#include "salesman.h"

/*******************************
* Functions implementation     *
********************************/


ostream& operator<<(ostream &out, const Salesman &S)
{
    cout << setw(20) << left << S.name;
    cout << setw(20) << fixed << left
         << setprecision(2) << S.sales << endl;

    return out;
}


istream& operator>>(istream &in, Salesman &S)
{
    in >> S.sales >> ws;
    getline(in, S.name);

    //cout << S.name << endl;

    return in;
}

//Compare salesman names using lexicographical order
bool operator>(const Salesman& S1, const Salesman& S2)
{
    return (S1.name > S2.name); //string comparison
}

