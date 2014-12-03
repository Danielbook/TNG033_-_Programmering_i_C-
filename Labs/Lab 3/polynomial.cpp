/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 3                                          *
**********************************************************/

#include "polynomial.h"
#include <cmath>
#include <assert.h>

//Constructor
Polynomial::Polynomial(int d, double *C)
{
    degree = d;
    coef = new (nothrow) double[degree+1];

    for (int i = 0; i < degree+1; i++)
    {
        coef[i] = C[i];
    }
}

Polynomial::Polynomial(double d)
{
    degree = 0;
    coef = new (nothrow) double [degree+1];

    coef[0] = d;
}

//Copy constructor
Polynomial::Polynomial(const Polynomial& P)
{
    degree = P.degree;
    coef = new (nothrow) double [degree+1];

    for (int i = 0; i < degree+1; i++)
    {
        coef[i] = P.coef[i];
    }
}

//Destructor
Polynomial::~Polynomial()
{
    delete [] coef;
    delete &degree;
}

void Polynomial::print(ostream& os)const
{
    for(int i = 0; i <= degree; i++)
    {
        if (coef[i] != 0)
        {
            if(i != 0)
            {
                if(coef[i] > 0)
                {
                    os << " + " << coef[i] << "*x^"<< i;
                }
            }
            else
            {
                os << coef[i];
            }
        }
    }
}

const Polynomial& Polynomial::operator=(const Polynomial P)
{
    if (this != &P) //Checks if it's already the same
    {
        //Replaces it with P
        coef = new (nothrow) double[P.degree+1];
        degree = P.degree;

        for (int i = 0; i < P.degree+1; i++)
        {
            coef[i] = P.coef[i];
        }
    }
    //Returnerar detta objekt
    return *this;
}


double& Polynomial::operator[](const int index)
{
assert(index >= 0 || index <= degree); // assert: verifiera vettiga argument, skriver ut om något blir fel.
    return coef[index];
}

//Polynomial *Polynomial::clone() const
//{
//    Polynomial *newClone = new Polynomial(this->degree, this->coef);
//    return newClone;
//}

double Polynomial::operator()(double d) const
{
    double sum = 0;
        for(int i = 0; i <= this->degree; i++)
        {
            sum += this->coef[i] * pow(d,i);
        }
    return sum;
}

Polynomial operator+(const Polynomial& P1, const Polynomial& P2)
{
    int newDegree = P1.degree;

    if(newDegree < P2.degree)
    {
        newDegree = P2.degree;
    }

    double* newCoef = new (nothrow) double[newDegree];

        for(int i = 0; i <= newDegree; i++)
        {
            newCoef[i] = 0; //undvik skräpvärden

            //plussar ihop
        if (i <= P1.degree)
            newCoef[i] += P1.coef[i];

        if (i <= P2.degree)
            newCoef[i] += P2.coef[i];

        }
    return Polynomial(newDegree, newCoef);
}
