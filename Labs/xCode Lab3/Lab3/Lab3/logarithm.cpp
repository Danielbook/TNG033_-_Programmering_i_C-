/*********************************************************
* Class Log member functions implementation              *
* TNG033: Lab 3                                          *
**********************************************************/

#include "logarithm.h"
#include "polynomial.h"
#include "math.h"
#include <iomanip>

using namespace std;

////CONSTRUCTORS
    //Default constructor
    Log::Log()
    {
        k1 = 0;
        k2 = 1;
        base = 2; //Smallest logarithm
        double coef[2] = {0, 1}; // = x
        exp = new Polynomial(1, coef); //New poly with degree 1 --> x
    }

    //Standard constructor
    Log::Log(const Expression& E, const double c1, const double c2, const int b)
    {
        base = b;
        k1 = c1;
        k2 = c2;
        exp = E.clone();
    }

    //Copy constructor
    Log::Log(Log& L)
    {
        k1 = L.k1;
        k2 = L.k2;
        base = L.base;
        exp = L.exp->clone();
    }

    //DESTRUCTOR
    Log::~Log(){
    }

////OPERATORS
    double Log::operator()(double d) const
    {
        double sum;
        
        sum = k2 * ( log10( (*exp)(d) ) / log10(base) ) + k1;
        
        return sum;
    }

////FUNCTIONS
    //Clone function
    Log *Log::clone() const
    {
        Log *newClone = new Log(*this->exp, this->k1, this->k2, this->base);
        return newClone;
    }

    //Print function
    void Log::print(ostream &os) const
    {
        os << fixed << setprecision(2) << k1 << " + " << k2 << " * Log_ " << base << "( " << *exp << " )" ;
    }















