/***************************************************************************
* TNG033, Fö 8                                                             *
* Simple test program for class Clock                                      *
* **************************************************************************/

#include <iostream>

#include "clock.h"

using namespace std;


int main()
{
    Clock c1; //default constructor is called
    Clock c2(10,20,0); //constructor called

    cout << "Clock 1: "  << c1 << endl;;

    cout << "Clock 2: "
         << c2.get_hours() << " hours and "
         << c2.get_minutes() << " minutes and "
         << c2.get_seconds() << " seconds" << endl;

    Clock *c3 = new Clock(12,31,50);  //constructor called
    const Clock c4(c2); //copy constructor is called
    //only const member functions can be applied to c4

    cout << "Clock 3: " << *c3 << endl;

    cout << "Clock 4: " << c4 << endl;;

    for(int i = 1; i <= 120; i++)
        c2.tick();

    cout << "Clock 2: " << c2 << endl;

    c2.reset();
    c2.tick().tick().tick(); //add 3 seconds

    cout << "Clock 2: " << c2 << endl;

    for(int i = 1; i <= 20; i++)
        c3->tick();

    cout << "Clock 3: " << *c3 << endl;

    Clock array[4];

    cout << "\nAll clocks: default constructor called for each of them" << endl;
    for(int i = 0; i < 4; i++)
        cout << array[i] << endl;

    array[0] = c1;
    array[1] = c2;
    array[2] = *c3;
    array[3] = c4;

    cout << "\nAll clocks ..." << endl;
    for(int i = 0; i < 4; i++)
        cout << array[i] << endl;

    Clock c6;

    c6 = c2 = c1;  //assignment operator is called
    //c6 = (c2 = c1);

    cout << "\nClock 2: " << c2 << endl;

    cout << "Clock 6: " << c6 << endl;;

    return 0;
}


