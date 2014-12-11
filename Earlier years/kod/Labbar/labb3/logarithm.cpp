//Implement member functions of class Logarithm

#include "logarithm.h"
#include "polynomial.h"
#include "math.h"

using namespace std;

Logarithm::Logarithm () //default constructor
{
    c1 = 1;
    c2 = 0;
    b = 2; //minsta f�r logaritm
    double coef[2] = {0, 1}; // = x
    E = new Polynomial(1,coef); //nytt polynom med grad 1 --> x
}

//deklarerar
Logarithm::Logarithm (const Expression& E_, const double c1_, const double c2_, const int b_)
{
    c1 = c1_;
    c2 = c2_;
    b = b_;
    E = E_.clone(); //klonar polynom til this-objekt
}

//copy constructor
Logarithm::Logarithm (Logarithm& L)
{
    c1 = L.c1;
    c2 = L.c2;
    b = L.b;
    E = L.E->clone();
}

//r�knar ut y, precis som i poly
double Logarithm::eval(double x) const
{
    double sum;

    return sum = c1 * (log10(E->eval(x)) / log10(b)) + c2; //kallar p� eval f�r polynomet
}

//s�tter en this-logarithmobjekt lika med ett L
const Logarithm& Logarithm::operator= (const Logarithm& L)
{
    if (this != &L)
    {
        c1 = L.c1;
        c2 = L.c2;
        b = L.b;

        E = L.E->clone();
    }
    return *this;
}

//skriver ut logarithm genom ostream f�r expressions
void Logarithm::print(ostream &os) const
{
    os << c2 << "+" << c1 << "*Log_" << b << "(" << *E << ")" ;
}

//klon
Logarithm *Logarithm::clone() const
{
    Logarithm *cloned = new Logarithm(*this->E, this->c1, this->c2, this->b);
    return cloned;
}








