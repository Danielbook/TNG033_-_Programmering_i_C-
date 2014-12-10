
#ifndef POL_H
#define POL_H

#include <iostream>


using namespace std;

#include "expression.h"

class Polynomial : public Expression
{
public:
    //Constructorer
    Polynomial(); // default constructor
    Polynomial(int d, double a[]);
    Polynomial(double a);
    Polynomial(const Polynomial& P);
    ~Polynomial();

    double eval(double) const;
    Polynomial operator+ (const Polynomial P) const;
    const Polynomial& operator= (const Polynomial P);
    double& operator[] (const int index);
    Polynomial* clone() const;
    void print(ostream &os) const;

protected:
    int degree;
    double* coef; //pekare som pekar på array

};


#endif
