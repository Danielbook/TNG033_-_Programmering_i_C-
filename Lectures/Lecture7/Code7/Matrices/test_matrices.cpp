/***************************************************************************
* TNG033, Fö 7                                                             *
* Simple test program for class Matrice                                    *
* **************************************************************************/

//Simple test of class Mtrice

#include <iostream>

using namespace std;

#include "matrices.h"


int main()
{
    int lines = 0, col = 0;

    Matrice M0;

    cout << "Matrice M0" << endl;
    cout << M0 << endl;


    while (true)
    {
        cout << "Enter number of lines: ";
        cin >> lines;
        cout << "Enter number of columns: ";
        cin >> col;

        if ( !(lines&&col) )  //lines==0 OR col==0
            break; //exit the loop

        Matrice M1(lines, col);

        cout << "Enter matrice M1: ";
        cin >> M1;

        cout << "Creating a copy M2 of M1 ...." << endl;

        Matrice M2(M1); //copy constructor is called

        cout << "\nMatrice M1" << endl;
        cout << M1 << endl;

        cout << "\nMatrice M2" << endl;
        cout << M2 << endl;

        int i, j;

        cout << "Enter i and j: ";
        cin >> i >> j;

        cout << "M2[" << i << "," << j << "] = "
             << M2.get(i,j) << endl;

        cout << "Change M2[" << i << "," << j << "] to 12.12"  << endl;
        M2.set(i, j, 12.12); //M2[i,j] = 12.12

        cout << "M2[" << i << "," << j << "] = "
             << M2.get(i,j) << endl;

//        cout << "\nMatrice M1" << endl;
//        cout << M1 << endl;
//
//        cout << "\nMatrice M2" << endl;
//        cout << M2 << endl;
    }

       return 0;
}


