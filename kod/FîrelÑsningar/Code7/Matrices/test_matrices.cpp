/***************************************************************************
* TNG033, Fö 7                                                             *
* Simple test program for class Matrice                                    *
* **************************************************************************/


//Simple test class matrice

#include <iostream>
#include <iomanip>

using namespace std;

#include "matrices.h"


int main()
{
    int lines = 0, col = 0;

    cout << "Enter number of lines: ";
    cin >> lines;
    cout << "Enter number of columns: ";
    cin >> col;

    Matrice M1(lines, col), M2(lines, col);

    cout << "Enter matrice M1: ";
    cin >> M1;

    cout << "Enter matrice M2: ";
    cin >> M2;

    //cin >> M1 >> M2;

    Matrice M3(M2); //copy constructor is called

    cout << "\nMatrice M1" << endl;
    cout << M1 << endl;

    cout << "\nMatrice M3" << endl;
    cout << M3 << endl;

    cout << "M2[1,2] = " << M2.get(1,2) << endl;

    M2.set(1, 2, 5656); //M2[1,2] = 5656
    cout << "M2[1,2] = " << M2.get(1,2) << endl;


   return 0;
}


