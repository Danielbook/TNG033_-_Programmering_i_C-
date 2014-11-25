/***************************************************************************
* TNG033, Fö 9                                                             *
* Defines a class Matrice to represent a matrix                            *
* Function operator is overloaded to allow subscript M(i,j)                *
* header file matrice.h                                                    *
* **************************************************************************/


#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <iostream>

using namespace std;


class Matrice
{
    public:

    static const int INIT_VALUE = 0;

    //constructors
    Matrice() = default;  //default constructor

    Matrice(int l, int n, int init = INIT_VALUE);

    Matrice(const Matrice& M); //copy constructor

    //destructor
    ~Matrice();

    //Assignment operator
    const Matrice& operator=(const Matrice& rhs);

    //overload functions operator
    //To be used as subscript operators, M(i,j) same as M[i,j]
    double& operator()(int l, int c);
    const double& operator()(int l, int c) const;

    //overloaded operators
    friend ostream& operator<<(ostream&, const Matrice&);
    friend istream& operator>>(istream&, Matrice&);

    private:
        int lines {0};
        int cols {0};
        double *table {nullptr};

};


#endif // MATRICES_H_INCLUDED
