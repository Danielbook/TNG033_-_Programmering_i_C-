/**********************************************************************************
* TNG033, Fö 3                                                                    *
* To illustrate pointers                                                          *
* Read the program and then understand its output                                 *
* *********************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;


void swap(int *x, int *y)
{
   int temp = *x;

   *x = *y;
   *y = temp;
}


int main()
{
    int k = 15, *p = nullptr;

    if (!p)
    {
        cout << "Pointer p is pointing nowhere!!" << endl << endl;
    }

    p = &k; //pointer p points to variable k


    cout << "p stores address " << p << endl;

    cout << "Variable k address (&k) is " << &k << endl;

    cout << "variable pointed by p (*p) stores " << *p << endl;

    cout << "Address of pointer p is " << &p << endl;

    *p *= 2; //k *= 2;

    cout << "*p *= 2;   p stores " << *p << endl;



    int i = 0;

    cout << "\nk = " << k << "  " << "i = " << i << endl;
    swap(&k, &i);
    cout << "k = " << k << "  " << "i = " << i << endl;


    return 0;
}
