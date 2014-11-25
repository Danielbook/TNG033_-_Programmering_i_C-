/***************************************************************************
* TNG033, Fö 9                                                             *
* Simple test program for class Clock                                      *
* **************************************************************************/

#include <iostream>

#include "clock.h"

using namespace std;


int main()
{
    Clock c1(120); //conversion constructor
    Clock c2(10,20,0); //constructor called

    cout << "Clock 1: "  << c1 << endl;
    cout << "Clock 2: "  << c2 << endl;

    cout << "c1 + c2 = " << c1 + c2 << endl;
    cout << "c2 + 7200 = " << c2 + 7200 << endl;
    cout << "7200 + c2 = " << 7200 + c2 << endl;

    if (c1 + c2 == c2 + c1)
        cout << "Addition is commutative" << endl;

    if (c2 + 120 < 7200 + c2)
        cout << "c2 + 120 < 7200 + c2" << endl;

    if (c2 + 7200 > 120 + c2)
        cout << "c2 + 7200 > 120 + c2" << endl;

    if (c2 + 7200 != 120 + c2)
        cout << "c2 + 7200 != 120 + c2" << endl;

    c1 = ++(++c2);

    cout << "\nc1 = " << c1 << endl;  //10:20:2
    cout << "c2 = " << c2 << endl;    //10:20:2

    c1++;

    cout << "\c1 = " << c1 << endl;  //10:20:3

    c1 += c2;

    cout << "c1 = " << c1 << endl;  //20:40:5

    c1 += 60;

    cout << "c1 = " << c1 << endl;  //20:41:5


    return 0;
}


