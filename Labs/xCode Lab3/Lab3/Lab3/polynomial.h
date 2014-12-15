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
//// CONSTRUCTORS
    Polynomial(); //Default constructor, måste vara med, annars är klassen abstract!
    Polynomial(int d, double *C);
    Polynomial(double d);
    Polynomial(const Polynomial& P); //Copy constructor
    ~Polynomial(); //Destructor

////OPERATORS
    const Polynomial& operator=(const Polynomial P); //Assignment operator
    double operator()(double d) const; //Evaluate operator
    friend Polynomial operator+(const Polynomial& P1, const Polynomial& P2); //Operator +
    double& operator[](const int index); //Operator[]
    
////FUNCTIONS
    Polynomial* clone() const; //Clone function
    void print(ostream &os)const; //Print function
    
protected:
    int degree; //Degree of expression
    double* coef; //Array of coefficients
};


#endif
