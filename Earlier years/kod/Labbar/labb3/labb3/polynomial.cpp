//Implement member functions of class Polynomial

#include "polynomial.h"
#include "math.h"

using namespace std;

Polynomial::Polynomial()
{
    degree = 0;
}

Polynomial::Polynomial(int d, double a[])
{
    degree = d;
    //pekar på hela ny array
    coef = new double[d+1]; //deklareratin av sizen: polynom + 1
    for (int i=0; i<d+1; i++)
        coef[i]=a[i];
}

Polynomial::Polynomial(double a)
{
    //om vi endast får med en konstant
    degree = 0;
    coef = new double [1];
    coef[0]=a;
}

//Copy constructor
Polynomial::Polynomial(const Polynomial& P)
{
    degree = P.degree;
    coef = new double[degree+1];
    for (int i=0; i<degree+1; i++)
    {
        coef[i]=P.coef[i];
    }
}

//deconstructor- deletar
Polynomial::~Polynomial()
{
    delete [] coef;
    delete &degree;
}

//räknar ut polynomet med givet x
double Polynomial::eval(double x) const
{
    double sum=0;
    for (int i=0; i<=this->degree; i++)
    {
        sum+= this->coef[i] * pow(x, i);
    }
    return sum;
}

//skriver ut polynomet
void Polynomial::print(ostream &os) const
{

    for(int i = 0; i <= degree; i++)
    {
        if(coef[i] != 0) //om 1:a coef är skild från noll
        {
            if (i != 0) //om grad är större än noll
            {
                if(coef[i] > 0) // om 1:a coef är större än noll, skriver ut polynom
                os << " + ";

                os << coef[i] << " * x^" << i;
            }
            else
                os << coef[i]; //skriver bara ut konstant
        }
    }
}

//adderar två polynom
Polynomial Polynomial::operator+ (const Polynomial P) const
{
    //sätter newdegreee till största givna degreen
    int newdegree = degree;
    if (P.degree > degree)
        newdegree = P.degree;

    //skapar ny pekare som oekar på array
    double *newcoeff =  new double[newdegree+1];

    for (int i = 0; i < newdegree+1; i++)   // 5x^2 + 2x^2 =7(newcoeff)x^2
    {
        newcoeff[i] = 0; //undvik skräpvärden

        //plussar ihop
        if (i <= degree)
            newcoeff[i] += coef[i];

        if (i <= P.degree)
            newcoeff[i] += P.coef[i];
    }

    //skickar tillbaka ett nytt polynom
    return Polynomial(newdegree, newcoeff);
}

//kan sätta polunom lika med ett annat
const Polynomial& Polynomial::operator= (const Polynomial P)
{
    if (this != &P) // om den inta har samma adress som P (samma polynom)
    {
        //raderar och sätter this-objektet lika med P
        delete[] coef;
        int nr = P.degree + 1;
        coef = new double[nr];
        degree = P.degree;

        for (int i = 0; i < P.degree + 1; i++)
        {
            coef[i] = P.coef[i];
        }
    }
    //Returnerar detta objekt
    return *this;
}

//returnerar värdet (för given grad) framför x i givet polynom
double& Polynomial::operator[] (const int index)
{
    assert(index >=0 || index <= degree); // assert: verifiera vettiga argument, skriver ut om något blir fel.
    return coef[index];
}

//klonar polynom
Polynomial *Polynomial::clone() const
{
    Polynomial *cloned = new Polynomial(this->degree, this->coef);
    return cloned;
}


















