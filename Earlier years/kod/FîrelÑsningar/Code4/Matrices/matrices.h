/**********************************************************************************
* TNG033, Fö 4                                                                    *
* Header file declaring                                                           *
* 1. A new data type Matrix                                                       *
* 2. Functions create_matrix, empty_matrix, get, and set                                        *
* 3. Overloaded operator<< and operator>>                                         *
* The number of lines and colunms of a matrix is user defined                     *
* Thus, pointers and dynamic memory allocation is used!!                          *
* ********************************************************************************/


#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <iostream>
#include <iomanip>

using namespace std;

struct Matrix
{
    int lines;       //number of lines
    int cols;        //number of columns
    double *p_table; //pointer to an array with lines*col doubles
                     //Matrix[i,j] is table[i*cols+j]
};

//Create a matrix M with l lines and c columns
//Allocate an array for l*c doubles
void create_matrix(Matrix& M, int l = 0, int c = 0);

//Deallocate the space occupied by the table of the matrice
//A becomes an empty matrice
void empty_matrix(Matrix& A);


//Return value stored in line i and column j of M
//Assume M is not empty
double get(const Matrix& M, int i, int j);


//Store value v in line i and column j of M
void set(Matrix& M, int i, int j, double v);


//Display Matrix A to stream out
ostream& operator<<(ostream& out, const Matrix& A);


//Read a Matrix from stream in
istream& operator>>(istream& in, Matrix& A);


#endif // MATRICES_H_INCLUDED
