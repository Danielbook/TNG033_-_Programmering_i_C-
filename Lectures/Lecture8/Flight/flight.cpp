/***************************************************************************
* TNG033, Fö 8                                                             *
* Implementation of class Flight                                           *
* source file flight.cpp                                                   *
* **************************************************************************/


#include "flight.h"


Flight::Flight(int n)
 : number(n)
 {  };


Flight::Flight(int n, int dh, int dm, int ah, int am)
 : number(n),
   dep {dh, dm, 0}, //dep(Clock(dh,dm,0)),
   arr {ah, am, 0}  //arr(Clock(ah,am,0))
{  }

/*
//less efficient
Flight::Flight(int n, int dh, int dm, int ah, int am)
//default constructor for Clocks dep and arr are automatically called
//before the body of the function is executed
{
    number = n;

    dep = Clock(dh,dm,0);
    arr = Clock(ah,am,0);
}
*/

ostream& operator<< (ostream &os, const Flight& f)
{
    os << "Flight " << f.number
        << " departes at " << f.dep
        << " and arrives at " << f.arr << endl;

    return os;
}
