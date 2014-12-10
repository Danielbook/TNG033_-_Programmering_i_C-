
#ifndef LOG_H
#define LOG_H

#include <iostream>

using namespace std;

#include "expression.h"

//Define class Logarithm
class Logarithm : public Expression{
public:
    //constructors
    Logarithm (); //default constructor
    Logarithm (const Expression& E, const double c1, const double c2, const int b); //causes polynomial problems
    Logarithm (Logarithm& L);

    double eval(double) const; //returnerar värde för y
    const Logarithm& operator= (const Logarithm& L);
    void print(ostream &os) const;
    Logarithm* clone() const;

protected:
    //c1 x Logb(E) + c2
    double c1, c2; //c1 = *log, c2= sista konstant
    int b; // b= konstant som vid logaritmering
    Expression *E; //värdet att logaritmera

};

#endif
