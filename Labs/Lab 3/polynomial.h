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
    Polynomial(const Polynomial& P);

    //Destructor
    ~Polynomial();

    //Assignment
    const Polynomial& operator=(const Polynomial P);

    //Evaluate
    double operator()(double d) const;

    friend Polynomial operator+(const Polynomial& P1, const Polynomial& P2);

    //operator[] coefficient...
    double& operator[](const int index);
//    Polynomial* clone() const;

    void print(ostream &os)const;
protected:
    int degree;
    double* coef; //Array of coefficients


};


#endif
