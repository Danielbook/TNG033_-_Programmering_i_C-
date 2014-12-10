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

//Default constructor
Clock::Clock()
{
    hh = mm = ss = 0;

    n_clocks++;
}

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
{
    hh = h;
    mm = m;
    ss = s;

    n_clocks++;
}

//copy constructor
Clock::Clock(const Clock &K)
 : hh(K.hh), mm(K.mm), ss(K.ss)
{
//    hh = K.hh;
//    mm = K.mm;
//    ss = K.ss;

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


//pre-increment of one second
//Read section 8.4.3 of course book for pos-increment
//Clock& is returned, so that ++(++K); compiles
Clock& Clock::operator++()
{
    ss = (ss+1) % 60;

    if (!ss)
    {
        mm = (mm+1)%60;

        if (!mm)
            hh = (hh+1) % 24;
    }

    return (*this);
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


Clock& Clock::operator+= (const Clock &K)
{
    int temp_s = ss + K.ss;
    ss = temp_s % 60;

    int temp_m = mm + K.mm + temp_s/60;
    mm = temp_m % 60;

    hh = (hh + K.hh + temp_m/60) % 24;

    return *this;
}

//Convertion operator
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

/*
//Non-friend operator<<
ostream& operator<<(ostream& os, const Clock& K)
{
    os << setw(2) << setfill('0')
       << K.get_hours() << ":"
       << setw(2) << K.get_minutes() << ":"
       << setw(2) << K.get_seconds() << endl;

    os << setfill(' ');

    return os;
}
*/




