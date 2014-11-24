/***************************************************************************
* TNG033, Fö 7                                                             *
* Implementation of class Clock                                            *
* source file clock.cpp                                                    *
* **************************************************************************/

#include <iostream>

#include "clock.h"

using namespace std;

Clock::Clock(int h, int m, int s)
//for built in data types there is no guarantee of initilization prior
//entering the body of the constructor
{
    hh = h;
    mm = m;
    ss = s;
}

//Copy constructor
//Not needed - compiler generated copy constructor does the same
 Clock::Clock(const Clock &c)
  : hh(c.hh), mm(c.mm), ss(c.ss)
 {
     //shallow copy (done also by default)
//     hh = c.hh;
//     mm = c.mm;
//     ss = c.ss;
 }


//Assignment operator
//Not needed - compiler generated assignment operator does the same
Clock Clock::operator=(const Clock &C)
{
    //shallow copy (done also by default)
    hh = C.hh;
    mm = C.mm;
    ss = C.ss;

    return *this;
}

int Clock::get_hours() const
{
    return hh;
}


int Clock::get_minutes() const
{
    return mm;
}

int Clock::get_seconds() const
{
    return ss;
}

void Clock::display(bool write_sec) const
{
    if (write_sec)
        cout << hh << ":" << mm << ":" << ss << endl;
     else
        cout << hh << ":" << mm << endl;
}


void Clock::reset()
{
    hh = mm = ss = 0;
}

/*
void Clock::tick() //used in Fö 7
{
    ss = (ss+1) % 60;

    if (ss == 0){ //(!ss)
        mm = (mm+1)%60;

        if (mm == 0)
            hh = (hh+1) % 24;
    }
}
*/

Clock& Clock::tick() //allows cascading (discussed in Fö 8&9)
{
    ss = (ss+1) % 60;

    if (ss == 0){ //(!ss)
        mm = (mm+1)%60;

        if (mm == 0)
            hh = (hh+1) % 24;
    }

    return (*this);
}


