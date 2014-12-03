/*************************
* Class Polynomial       *
* TNG033: Lab 3          *
**************************/

#ifndef POL_H
#define POL_H

#include <iostream>

using namespace std;

#include "expression.h"


class Polynomial : public Expression{
public:
    
    //Constructors
    Polynomial(int d, double *C);

    Polynomial(double d);
    
    //Copy constructor
    
    //Destructor
    
    //Assignment
    
    friend Polynomial operator+(const Polynomial& P1, const Polynomial& P2);
    
    //operator[] coefficient...
    
    virtual Polynomial* clone();
        
protected:
    int degree;
    double* coef; //Array of coefficients
    
    void display(ostream &os);
};


#endif
