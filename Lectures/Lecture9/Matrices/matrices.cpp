/***************************************************************************
* TNG033, Fö 9                                                             *
* Implementation of class Matrice                                          *
* Source file matrices.cpp                                                 *
* **************************************************************************/

#include "matrices.h"

#include <iomanip>
#include <new>


//Allocate space for a matrice l*c and initializes it with init
Matrice::Matrice(int l, int c, int init)
{
    if (!(l&&c))  //l == 0 OR c == 0
    {
        lines = cols = 0;
        table = nullptr;
        return;
    }

    lines = l;
    cols = c;

    table = new (nothrow) double [l*c]; //reserve memory

    if (!table) //no memory available
    {
        lines = cols = 0;
        return;
    }

    //Initialized all slots of the matrix
    for(int i = 0; i < l*c; i++)
        table[i] = init;
}


Matrice::Matrice(const Matrice &M) //copy constructor
{
    lines = M.lines;
    cols = M.cols;

    if (!lines) // if M is empty matrice
    {
        table = nullptr;
        return;
    }

    table = new (nothrow) double [lines*cols];  //allocate memory

    if (!table) //no memory available
    {
        lines = cols = 0;
        return;
    }


    //initialize matrix
    for(int i = 0; i < lines*cols; i++)
        table[i] = M.table[i];
}



//destructor
Matrice::~Matrice()
{
    cout << "Destructor ..." << endl;

    if (!table) return; //if empty matrice

    delete [] table; //deallocate the table

    lines = cols = 0;
    table = nullptr;
}


//Assignment operator
//copy and swap
const Matrice& Matrice::operator=(const Matrice& rhs)
{
    if (this != &rhs) //self assignment
    {
        //Copy constructor performs a deep copy
        Matrice copy(rhs);

        swap(table, copy.table); //swap the pointers
        swap(lines, copy.lines);
        swap(cols, copy.cols);
    }

    return *this;
    //destructor is called for copy and deallocates old memory
}


//subscript operators
double& Matrice::operator()(int l, int c) const
{
    return table[l*cols+c];
}


const double& Matrice::operator()(int l, int c) const
{
    return table[l*cols+c];
}


ostream& operator<<(ostream& out, const Matrice& A)
{
    if (!A.table)
    {
        out << "Empty matrix!!" << endl;
        return out;
    }

    out << "[ " << endl;

    for(int i = 0; i < A.lines; i++)
    {
        for(int j = 0; j < A.cols; j++)
        {
            out << fixed << setprecision(2) << setw(6)
                << A(i,j);
        }
        out << endl;
    }

    out << "]" << endl;

    return out;
}



istream& operator>>(istream& in, Matrice& A)
{
    if (!A.table) return in;

    //Read user given values
    for(int i = 0; i < A.lines; i++)
    {
        for(int j = 0; j < A.cols; j++)
        {
            in >> A(i,j);
        }
    }

    return in;
}





