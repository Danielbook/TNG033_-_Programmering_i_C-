/***************************************************************************
* TNG033, Fö 9                                                             *
* Implementation of class Clock                                            *
* source file clock.cpp                                                    *
* **************************************************************************/

#include <iostream>
#include <iomanip>

#include "clock.h"

using namespace std;

int Clock::n_clocks = 0;  //initialize a static class data member


//convertion constructor int to Clock
Clock::Clock(int s)
{
    hh = s/3600;

    s -= hh*3600;
    mm = s/60;

    ss = s - mm*60;

    n_clocks++;
}

Clock::Clock(int h, int m, int s)
 : hh(h), mm(m), ss(s)
{
    n_clocks++;
}

//copy constructor
Clock::Clock(const Clock &K)
 : hh(K.hh), mm(K.mm), ss(K.ss)
{
    n_clocks++;
}


//Destructor
Clock::~Clock()
{
    n_clocks--;
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


//Conversion operator
//Converts a clock to an int -- number of seconds represented by the clock
Clock::operator int() const
{
    return (hh*60*60 + mm*60 + ss);
}

//Friend functions are not memeber functions of class Clock
ostream& operator<<(ostream& os, const Clock& K)
{
    os << setw(2) << setfill('0')
       << K.hh << ":"
       << setw(2) << K.mm  << ":"
       << setw(2) << K.ss << endl;

    os << setfill(' ');

    return os;
}


int Clock::number_of_clocks() //Static member function
{
    return n_clocks;
}




