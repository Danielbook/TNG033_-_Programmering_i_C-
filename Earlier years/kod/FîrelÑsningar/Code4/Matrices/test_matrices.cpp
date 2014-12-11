/**********************************************************************************
* TNG033, Fö 4                                                                    *
* Simple test program for Matrix                                                  *
* The number of lines and columns is decided by the user                          *
* ********************************************************************************/

#include <iostream>
#include <iomanip>

#include "matrices.h"

using namespace std;


int main()
{
    Matrix A;
    int lines = 0, cols = 0;

    char svar;

    while(true)
    {
        cout << "\nNumber of lines? ";
        cin >> lines;

        cout << "Number of columns? ";
        cin >> cols;

        create_matrix(A, lines, cols);

        cout << "Enter " << lines << "*" << cols << " values: ";
        cin >> A;

        cout << "\Matrix A: " << endl;
        cout << A;

        cout << "\Continue (y/n)? ";
        cin >> svar;

        if (svar == 'n') break;  //exit the loop

        empty_matrix(A); //dealocate the memory for A
    }

   cout << "\nGoodBye" << endl;

   return 0;
}


