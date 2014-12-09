/***************************************************************************
* TNG033, Fö 7                                                             *
* Implementtaion of class Matrice                                          *
* Source file clock.cpp                                                    *
* **************************************************************************/

#include "matrices.h"

#include <iomanip>
#include <new>


//Allocate space for a matrice l*c and initializes it with init
Matrice::Matrice(int l, int c, int init)
{
  if (!(l&&c))
  {
      lines = cols = 0;
      table = nullptr;
      return;
  }

  lines = l;
  cols = c;

  table = new (nothrow) double [l*c]; //reserve memory

   if (!table) //no memory available
        return;

  //Initialized all slots of the matrix
  for(int i = 0; i < l*c; i++)
    table[i] = init;
}


Matrice::Matrice(const Matrice &M) //copy constructor
{
    lines = M.lines;
    cols = M.cols;

    if (!lines){// if M is empty matrice
        table = nullptr;
        return;
    }

    table = new (nothrow) double [lines*cols];  //allocate memory

    if (!table) //no memory available
        return;

    //initialize matrix
    for(int i = 0; i < lines*cols; i++)
        table[i] = M.table[i];
}


//destructor
Matrice::~Matrice()
{
    if (!table) return; //if empty matrice

    delete [] table; //deallocate the table
}

//set valued in line l and column c to val
void Matrice::set(int l, int c, int val)
{
    table[l*cols+c] = val;
}


//get valued in line l and column c to val
double Matrice::get(int l, int c) const
{
    return (table[l*cols+c]);
}

ostream& operator<<(ostream& out, const Matrice& A)
{
    if (!A.table)
    {
        out << "Empty matrice!!" << endl;
        return out;
    }

    out << "[ ";
    for(int i = 0; i < A.lines*A.cols; i++)
    {
         if  ( !(i%A.cols) )
            out << endl;

         out << fixed << setprecision(2) << setw(6)
             << A.table[i];
    }
    out << " ]" << endl;

    return out;
}



istream& operator>>(istream& in, Matrice& A)
{
    if (!A.table) return in;

    //Read user given values
    for(int i = 0; i < A.lines*A.cols; i++)
           in >> A.table[i];

    return in;
}





