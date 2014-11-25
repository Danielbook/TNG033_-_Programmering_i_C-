/***************************************************************************
* TNG033, Fö 8                                                             *
* Implementation of class Clock                                            *
* source file clock.cpp                                                    *
* **************************************************************************/

#include "clock.h"

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


void Clock::reset()
{
    hh = mm = ss = 0;
}


ostream& operator<< (ostream& os, const Clock& c)
{
     os << c.hh << ":" << c.mm << ":" << c.ss;

     return os;
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


