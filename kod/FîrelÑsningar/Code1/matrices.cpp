/********************************************************************
* TNG033, Fö 1                                                      *
* Source file matrices.cpp                                          *
* Defines all functions declared in matrices.h                      *
* *******************************************************************/


#include <iostream>
#include <iomanip>

#include "matrices.h"

using namespace std;

//Res = A + B
void add(Matrice A, Matrice B, Matrice Res, int n_lines)
//See pag. 191 of course book
{
    for(int i = 0; i < n_lines; i++)
        for(int j = 0; j < N_COL; j++)
            Res[i][j] = A[i][j] + B[i][j];
}


//Res = A * B
void mult(Matrice A, Matrice B, Matrice Res, int n_lines)
{
     for(int i = 0; i < n_lines; i++)
        for(int j = 0; j < N_COL; j++)
            Res[i][j] = A[i][j] * B[i][j];
}

//Res = c * A
void mult(double c, Matrice A, Matrice Res, int n_lines)
{ for(int i = 0; i < n_lines; i++)
        for(int j = 0; j < N_COL; j++)
            Res[i][j] = c * A[i][j];
}


//Display a matrice
void display(Matrice A, int n_lines)
{
    for(int i = 0; i < n_lines; i++)
        for(int j = 0; j < N_COL; j++)
            cout << fixed << setprecision(2)
                 << "A[" << i <<"][" << j << "]= "
                 <<  A[i][j] << endl;
}


//Read a matrice
void read(Matrice A, int n_lines)
{
    for(int i = 0; i < n_lines; i++)
        for(int j = 0; j < N_COL; j++)
        {
            cout << "A[" << i <<"][" << j << "]= ";
            cin >>  A[i][j];
            cout << endl;
        }
}


//Return true if A is a symmetric matrice
bool symmetric(Matrice A, int n_lines)
{
   //If N_COL != n_lines then A is not symmetric
   if (n_lines != N_COL)
    return false;

   for(int i = 0; i < n_lines; i++)
        for(int j = 0; j < N_COL; j++)
            if (A[i][j] != A[j][i])
                return false;

   return true;
}
