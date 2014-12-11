/***************************************************************************
* TNG033, Fö 9                                                             *
* Simple test program for class Clock                                      *
* **************************************************************************/

#include <iostream>
#include <iomanip>

#include "clock.h"

using namespace std;

int main()
{
    Clock c1;
    const Clock c2(2,30,0);

    Clock c3(12,31,50);
    Clock c4(c2);

    cout << "Clock 1: " << c1 << endl;
    cout << "Clock 2: " << c2 << endl;
    cout << "Clock 3: " << c3 << endl;
    cout << "Clock 4: " << c4 << endl;

    cout << "Number of clocks: "
         << Clock::number_of_clocks() << endl << endl << endl;

    Clock *p_K = new Clock;

    cout << "Number of clocks: "
         << Clock::number_of_clocks() << endl << endl << endl;

    delete p_K;

    cout << "Number of clocks: "
         << Clock::number_of_clocks() << endl << endl << endl;

   /* ************************************** */

    cout << "++c1: " << ++c1 << endl;
    cout << "++(++c1): " << ++(++c1) << endl;

   /* ************************************** */

    c1 = c2 + c3;

    cout << "c1 = c2+c3 :" << c1 << endl;
    cout << "++c3+c4: " << ++c3 + c4 << endl;
    cout << "c3: " << c3 << endl;

    /* ************************************** */

    c1 += c2;
    cout << "c1 += c2: " << c1 << endl;

    /* ************************************** */

    //if (c4 != c2)
    if (c4 == c2)
        cout << "c4 and c2 have same time." << endl << endl;
    else
       cout << "c4 and c2 have different times." << endl << endl;

    /* ************************************** */

    int seconds = c2;

    cout << "C2 converted to seconds: " << seconds << endl << endl;

     /* ************************************** */

     c1 = seconds; //conversion constructor is called

     cout << "c1: " << c1 << endl << endl;

   return 0;
}


