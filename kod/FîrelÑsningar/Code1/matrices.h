/********************************************************************
* TNG033, Fö 1                                                      *
* header file matrices.h                                            *
* Declares functions to perform operations over matrices            *
* Matrices have N_COL columns                                       *
* *******************************************************************/

#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

const int N_COL = 3;
const int N_LINES = N_COL;

//Define a new type Matrice as a table
//with 3 columns and 3 lines
typedef double Matrice[N_LINES][N_COL];


//Res = A + B
void add(Matrice A, Matrice B, Matrice Res, int n_lines);


//Res = A * B
void mult(Matrice A, Matrice B, Matrice Res, int n_lines);


//Res = c * A
void mult(double c, Matrice A, Matrice Res, int n_lines);


//Display a matrice
void display(Matrice A, int n_lines);


//Read a matrice
void read(Matrice A, int n_lines);


//Return true if A is a symmetric matrice
//If COL != n_lines then A is not symmetric
bool symmetric(Matrice A, int n_lines);


#endif // MATRICES_H_INCLUDED
