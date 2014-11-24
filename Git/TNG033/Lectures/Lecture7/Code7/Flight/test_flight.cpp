/***************************************************************************
* TNG033, Fö 7                                                             *
* Simple test program for class Flight                                     *
* **************************************************************************/

#include <iostream>

#include "flight.h"

using namespace std;


int main()
{
    Flight F(112, 10, 30, 18, 30);
    //Flight F {112, 10, 30, 18, 30};

    cout << F << endl;

    return 0;
}


