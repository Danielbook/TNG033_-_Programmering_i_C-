/*************************
* Class Expression       *
* TNG033: Lab 3          *
**************************/

#ifndef EXP_H
#define EXP_H

#include <iostream>

using namespace std;

const double EPSILON = 1.0e-5;


class Expression{
public:
    //Abstract destructor
    virtual ~Expression(){  };
    
    //Evaluate
    virtual double operator()(double d) const = 0;
    
    //Test if root
    bool isRoot(double d) const;
    
    friend ostream& operator<<(ostream& os, const Expression& E);
    
    //Return a clone of the Expression
    virtual Expression* clone() = 0;

protected:
    virtual void display(ostream &os) = 0;
};

#endif