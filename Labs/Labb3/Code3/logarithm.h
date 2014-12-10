/*************************
* Class Log              *
* TNG033: Lab 3          *
**************************/


#ifndef LOG_H
#define LOG_H

#include <iostream>

using namespace std;

#include "expression.h"

class Log : public Expression
{
public:

    //Constructors
    Log();      //Default
    Log(const Expression& E, const double c1,const double c2, const int b);
    Log(Log& L);    //Copy constructor
    ~Log();         //Destructor

    //Operator
    double operator() (double d) const;

    //Functions
    void print(ostream& os) const;
    Log* clone() const;

protected:
    double k1, k2;
    int base;
    Expression *exp;
};

#endif
