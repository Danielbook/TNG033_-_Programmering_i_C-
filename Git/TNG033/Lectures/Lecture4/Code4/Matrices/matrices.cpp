/**********************************************************************************
* TNG033, Fö 4                                                                    *
* Source file defining the function declared in matrix.h                          *
* The number of lines and colunms of a matrix is user defined                     *
* Thus, pointers and dynamic memory allocation is used!!                          *
* ********************************************************************************/

#include "matrices.h"
#include <new>

//Create a matrix M with l lines and c columns
//Allocate an array for l*c doubles
void create_matrix(Matrix& M, int l, int c)
{
    if ( !(l && c) )  //create an empty Matrix
    {
        M.lines = M.cols = 0;
        M.p_table = nullptr;
        return;
    }

    M.lines = l; //set number of lines
    M.cols = c;  //set number of columns
    M.p_table = new (nothrow) double [l*c]; //allocate explicitly memory

    if (!M.p_table) //not possible to allocate memory!!
      M.lines = M.cols = 0;

    cout << "Matrix created\n";
}


//Deallocate the space occupied by the table of the matrice
//A becomes an empty matrice
void empty_matrix(Matrix& A)
{
    A.lines = A.cols = 0;

    delete [] A.p_table; //deallocate memory

    A.p_table = nullptr;
}


//Return value stored in line i and column j of M, i.e. M[i,j]
//Assume M is not empty
double get(const Matrix& M, int i, int j)
{
    return M.p_table[i*M.cols+j];
}


//Store value v in line i and column j of M, i.e. M[i,j] = v
void set(Matrix& M, int i, int j, double v)
{
    M.p_table[i*M.cols+j] = v;
}

//Display Matrix A to stream out
ostream& operator<<(ostream& out, const Matrix& A)
{
    cout << "[" << endl;

    for(int i = 0; i < A.lines; i++)
    {
        for(int j = 0; j < A.cols; j++)
            out << setw (8) << fixed << setprecision(2)
                <<  get(A,i,j) << " ";

        cout << endl;
    }

    cout << "]" << endl;

    return out;
}


//Read a Matrix from stream in
istream& operator>>(istream& in, Matrix& A)
{
    for(int i = 0; i < A.lines; i++)
        for(int j = 0; j < A.cols; j++)
        {
            //in >> val;
            //set(A,i,j,val);

            in >>  A.p_table[i*A.cols+j];
        }

    return in;
}
