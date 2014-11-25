/***************************************************************************
* TNG033, Fö 7                                                             *
* Implementation of class Clock                                            *
* source file clock.cpp                                                    *
* **************************************************************************/

#include <iostream>

#include "clock.h"

using namespace std;

Clock::Clock()
{
    hh = mm = ss = 0;
}

Clock::Clock(int h, int m, int s)
{
    hh = h;
    mm = m;
    ss = s;
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

void Clock::tick()
{
    ss = (ss+1) % 60;

    if (ss == 0){ //(!ss)
        mm = (mm+1)%60;

        if (mm == 0)
            hh = (hh+1) % 24;
    }
}



