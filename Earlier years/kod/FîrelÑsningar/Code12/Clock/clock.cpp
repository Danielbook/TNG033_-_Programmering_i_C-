/***************************************************************************
* TNG033, Fö 12                                                            *
* Implementation of class Clock                                            *
* source file clock.cpp                                                    *
* **************************************************************************/

#include <iostream>
#include <iomanip>

#include "clock.h"

using namespace std;

//Default constructor
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

//copy constructor
Clock::Clock(const Clock& K)
{
    hh = K.hh;
    mm = K.mm;
    ss = K.ss;
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


//Overloaded operator+
Clock Clock::operator+(const Clock& K) const
{
    Clock temp;

    temp.ss = (ss + K.ss) % 60;
    temp.mm = (mm + K.mm) + (ss + K.ss) / 60;
    temp.hh = (temp.mm / 60 + (hh + K.hh)) % 24;
    temp.mm %= 60;

    return temp; //copy constructor is called
}


//pre-increment of one second
Clock& Clock::operator++()
{
    ss = (ss+1) % 60;

    if (!ss){
        mm = (mm+1)%60;

        if (!mm)
            hh = (hh+1) % 24;
    }

    return (*this);
}

bool Clock::operator==(const Clock& K) const
{
    return( (hh == K.hh) &&
            (mm == K.mm) &&
            (ss == K.ss) );
}


bool Clock::operator!=(const Clock& K) const
{
    return ( !(*this == K) );
}

bool Clock::operator<(const Clock& K) const
{
    if (hh < K.hh) return true;

    if (hh == K.hh && mm < K.mm) return true;

    if (hh == K.hh && mm == K.mm && ss < K.ss) return true;

    return false;
}


//Friend functions are not memeber functions of class Clock
ostream& operator<<(ostream& os, const Clock& K)
{
    os << setw(2) << setfill('0')
       << K.hh << ":"
       << setw(2) << K.mm  << ":"
       << setw(2) << K.ss;

    os << setfill(' ');

    return os;
}
