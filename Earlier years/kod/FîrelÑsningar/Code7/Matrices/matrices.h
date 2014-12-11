/***************************************************************************
* TNG033, Fö 7                                                             *
* Defines a class Clock to represent a clock as hh:mm:ss                   *
* header file clock.h                                                      *
* **************************************************************************/


#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <iostream>

using namespace std;

class Matrice
{
    public:

    //constructors
    Matrice(int l = 0, int n = 0, int init = 0); //default constructor

    Matrice(const Matrice &M); //copy constructor

    //destructor
    ~Matrice();

    //Assignment operator should be added -- Fö 8

    //get valued in line l and column c to val
    double get(int l, int c) const;

    //set valued in line l and column c to val
    void set(int l, int c, int val);

    friend ostream& operator<<(ostream&, const Matrice&);
    friend istream& operator>>(istream&, Matrice&);

    private:
        int lines;
        int cols;
        double *table;

};


#endif // MATRICES_H_INCLUDED
