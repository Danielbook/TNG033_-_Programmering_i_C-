/***************************************************************************
* TNG033, Fö 7                                                             *
* Defines a class Matrice to represent a matrix                            *
* header file matrice.h                                                      *
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

    //Assignment operator should be added -- see Fö 8

    //get valued in line l and column c to val
    double get(int l, int c) const;

    //set valued in line l and column c to val
    void set(int l, int c, int val);


    //overloaded operators
    friend ostream& operator<<(ostream&, const Matrice&);
    friend istream& operator>>(istream&, Matrice&);

    private:
        int lines {0};
        int cols {0};
        double *table {nullptr};

};


#endif // MATRICES_H_INCLUDED
