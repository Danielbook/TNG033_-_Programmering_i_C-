/**********************************************************************************
* TNG033, Fö 3                                                                    *
* To illustrate pointers pre/pos increment                                        *
* Read the program and then understand its output                                 *
* *********************************************************************************/

#include <iostream>
#include <iomanip>

//Program to display the contents of an array

using namespace std;


int main()
{
    const int SIZE = 10;

    double V[SIZE] = {2,3,4,5,6,7,8,9,10,11};

    double *p = &V[1];

    cout << "V: ";
    for (int i = 0; i < SIZE; i++)
        cout << V[i] << " ";

    cout << endl << endl;

    double d = 0;

    cout << "*p" << setw(10) << *p << endl;

    d = *p++; //what value is store in d?
    cout << "*p++" << setw(8) << d << endl;
    cout << "*p" << setw(10) << *p << endl;

    cout << "----------------" << endl << endl;

    p = &V[1];

     cout << "*p" << setw(10) << *p << endl;

    d = *++p; //what value is store in d?
    cout << "*++p" << setw(8) << d << endl;
    cout << "*p" << setw(10) << *p << endl;


    return 0;
}
