/*********************************************************
* Class Log member functions implementation              *
* TNG033: Lab 3                                          *
**********************************************************/

//ADD implementation of the member functions for class Log
#include "logarithm.h"
#include "polynomial.h"
#include "math.h"


    //Constructors
    Log::Log()
    {
        k1 = 0.0;
        k2 = 1.0;
        base = 2;
        //Creates new polynimial of degree 1 and a basic coefficient
        double c[2] = {0, 1};
        exp = new Polynomial(1,c);
    }

    Log::Log(const Expression& E, const double c1,const double c2, const int b)
    {
        k1 = c1;
        k2 = c2;
        base = b;
        exp = E.clone();
    }

    Log::Log(Log& L)     //Copy constructor
    {
        k1 = L.k1;
        k2 = L.k2;
        base = L.base;
        exp = L.exp->clone();
    }

    //DESTRUCTOR
    Log::~Log(){}


    double Log::operator()(double d) const
    {
        double sum = 0;
        sum = k2 *( log10( (*exp)(d) ) / log10(base) ) + k1;
        return sum;
    }

    Log *Log::clone() const
    {
        Log *newClone = new Log(*this->exp, this->k1, this->k2, this->base);
        return newClone;
    }

   void Log::print(ostream& os) const
   {
        os /*<< "k1 = "*/ << k1 /*<< "k2 = "*/ << " + " << k2 << " * Log_ " << base << "(" << *exp << " )";
   }
