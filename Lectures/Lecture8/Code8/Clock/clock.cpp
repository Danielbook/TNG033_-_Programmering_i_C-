/***************************************************************************
* TNG033, Fö 8                                                             *
* Implementation of class Clock                                            *
* source file clock.cpp                                                    *
* **************************************************************************/

#include "clock.h"

Clock::Clock(int h, int m, int s)
//for built in data types there is no guarantee of initilization prior
//entering the body of the constructor
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


Clock& Clock::tick() //allows cascading (discussed in Fö 8)
{
    ss = (ss+1) % 60;

    if ( !ss )
    {
        mm = (mm+1)%60;

        if ( !mm )
            hh = (hh+1) % 24;
    }

    return (*this);
}


ostream& operator<<(ostream& out, const Clock& c)
{
     if (c.ss)
        out << c.hh << ":" << c.mm << ":" << c.ss << endl;
     else
        out << c.hh << ":" << c.mm << endl;

     return out;
}




