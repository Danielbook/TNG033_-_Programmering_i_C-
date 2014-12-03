/*************************
* Class Log              *
* TNG033: Lab 3          *
**************************/


#ifndef LOG_H
#define LOG_H

#include <iostream>

using namespace std;

#include "expression.h"

class Log : public Expression{
public:
////CONSTRUCTORS
    Log(); //Default constructor
    Log(const Expression& E, const double c1, const double c2, const int b); //Standrard constructor
    Log(Log& L); //Copy constructor
    ~Log(); //Destructor

////OPERATORS
    double operator()(double d) const;
    
////FUNCTIONS
    Log* clone() const;
    void print(ostream& os) const;

protected:
    double k1, k2; //Constants
    int base; //Base of logarithm
    Expression *exp; //Expression inside logarithm
};

#endif
