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
    Log(Expression *E, double c1, double c2, int b){
        base = b;
        k1 = c1;
        k2 = c2;
                
        exp = E->clone();
    }
    
    /*virtual*/ Log* clone();
    
    
private:
    double k1, k2;
    int base;
    Expression *exp;
};

#endif
