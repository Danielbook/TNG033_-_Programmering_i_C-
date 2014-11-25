/***************************************************************************
* TNG033, Fö 9                                                             *
* Simple test program for class Matrice                                    *
* **************************************************************************/

//Simple test of class Matrice

#include <iostream>

using namespace std;

#include "matrices.h"


int main()
{
    Matrice M0;
    Matrice M1(5,5, -1);

    cout << "Matrice M0 = " << M0 << endl;
    cout << "Matrice M1 = \n" << M1 << endl;

    M0 = M1; //assignment operator

    for(int i = 0; i < 5; i++)
        M0(i,i) = 8.8;  //modify diagonal

    cout << "Matrice M0 = \n" << M0 << endl;

    Matrice M2(M0); //copy constructor

      for(int i = 0; i < 5; i++)
        ++M2(i,i);  //modify diagonal

    cout << "Matrice M2 = \n" << M2 << endl;


    return 0;
}


