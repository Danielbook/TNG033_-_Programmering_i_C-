/********************************************************************
* TNG033, Fö 1                                                      *
* Simple test program for matrice operations                        *
* *******************************************************************/

#include <iostream>
#include <iomanip>

#include "matrices.h"

using namespace std;

//Display the menu
void display_menu()
{
    cout << endl << setw(35) << setfill('*') << '*' << endl;
    cout << "1. Add matrices" << endl;
    cout << "2. Multiply matrices" << endl;
    cout << "3. Multiply a matrice by a scalar" << endl;
    cout << "4. Test symmetry" << endl;
    cout << "5. Quit" << endl;
    cout << setw(35) << setfill('*') << '*' << endl;
    cout << setfill(' ');
}


int main()
{
    Matrice M1, M2, M3;
    double k;

    int option;

    do{
        display_menu();

        cout << "Option ? ";
        cin >> option;
        cin.ignore();

        switch (option)
        {
            case 1: cout << endl << "Enter first matrice:" << endl;
                    read(M1, N_LINES);
                    cout << endl << "Enter second matrice:" << endl;
                    read(M2, N_LINES);
                    add(M1, M2, M3, N_LINES);
                    cout << endl << "M1 + M2 = " << endl;
                    display(M3, N_LINES);
                    break;
            case 2: cout << endl << "Enter first matrice:" << endl;
                    read(M1, N_LINES);mult(M1, M2, M3, N_LINES);
                    cout << endl << "Enter second matrice:" << endl;
                    read(M2, N_LINES);
                    mult(M1, M2, M3, N_LINES);
                    cout << endl << "M1 * M2 = " << endl;
                    display(M3, N_LINES);
                    break;
            case 3: cout << endl << "Enter first matrice:" << endl;
                    read(M1, N_LINES);
                    cout << endl << "Enter constant k:" << endl;
                    cin >> k;
                    mult(k, M1, M3, N_LINES);
                    cout << endl << "k * M2 = " << endl;
                    display(M3, N_LINES);
                    break;
            case 4: cout << endl << "Enter first matrice:" << endl;
                    read(M1, N_LINES);
                    if (symmetric(M1, N_LINES))
                        cout << "Matrice is symmetric." << endl;
                    else
                        cout << "Matrice is not symmetric." << endl;
                    break;
            case 5: break;
            default: cout << "Wrong option!!" << endl;
        }
   } while (option != 5);

   cout << "GoodBye." << endl;

   return 0;
}


