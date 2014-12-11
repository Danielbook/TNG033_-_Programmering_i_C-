/***************************************************************************
* TNG033, Fö 7                                                             *
* Simple test program for class Clock                                      *
* **************************************************************************/

#include <iostream>
#include <iomanip>

#include "clock.h"

using namespace std;


int main()
{
    Clock c1;
    Clock c2(10,20,0);

    c2.tick().tick().tick();
    cout << "Clock 2: ";
    c2.display();

    Clock *c3 = new Clock(12,31,50);
    Clock c4(c2);

    cout << "Clock 1: ";
    c1.display();

    cout << "Clock 2: "
         << c2.get_hours() << " hours and "
         << c2.get_minutes() << " minutes and "
         << c2.get_seconds() << " seconds" << endl;


    for(int i = 1; i <= 120; i++)
            c2.tick();

    cout << "Clock 2: ";
    c2.display();

    c2.reset();
    c2.tick().tick().tick(); //add 3 seconds

    cout << "Clock 2: ";
    c2.display();

    for(int i = 1; i <= 20; i++)
            c3->tick();

    cout << "Clock 3: ";
    c3->display();

    cout << "Clock 4: ";
    c4.display();

    Clock array[4];

    cout << "\nAll clocks: default constructor called for each of them" << endl;
    for(int i = 0; i < 4; i++)
        array[i].display();

    array[0] = c1;
    array[1] = c2;
    array[2] = *c3;
    array[3] = c4;

    cout << "\nAll clocks ..." << endl;
    for(int i = 0; i < 4; i++)
        array[i].display();

   return 0;
}


