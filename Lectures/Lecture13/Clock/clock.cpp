/***************************************************************************
* TNG033: Fö 14                                                             *
* Implementation of class Clock                                            *
* source file clock.cpp                                                    *
* **************************************************************************/

#include "clock.h"

//default constructor and conversion constructor int -> Clock
Clock::Clock(int s)
{
    int m = s / 60;

    hh = m / 60;
    ss = s % 60;
    mm = m % 60;
}


Clock::Clock(int h, int m, int s)
 : hh(h), mm(m), ss(s)
{

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

bool Clock::operator==(const Clock& c) const
{
    return( (hh == c.hh) &&
            (mm == c.mm) &&
            (ss == c.ss) );
}


bool Clock::operator<(const Clock& c) const
{
    if (hh < c.hh) return true;
    if (hh == c.hh && mm < c.mm) return true;
    if (hh == c.hh && mm == c.mm && ss < c.ss) return true;

    return false;
}

//Pre-increment
Clock& Clock::operator++() //allows cascading (discussed in Fö 8)
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

//Pos-increment
const Clock Clock::operator++(int)
//returns a const Clock to avoid to compile (K++)++;
//(i++)++; does not compile either
{
    Clock temp(*this);

    ++(*this);  //call pre-increment function

    return temp; //return the old value before the increment
}

const Clock& Clock::operator+= (const Clock &c)
{
    int temp_s = ss + c.ss;
    ss = temp_s % 60;

    int temp_m = mm + c.mm + temp_s/60;
    mm = temp_m % 60;

    hh = (hh + c.hh + temp_m/60) % 24;

    return *this;
}


const Clock operator+(const Clock& c1, const Clock& c2)
{
    Clock temp;

    temp.ss = (c1.ss + c2.ss) % 60;
    temp.mm = (c1.mm + c2.mm) + (c1.ss + c2.ss) / 60;
    temp.hh = (temp.mm / 60 + (c1.hh + c2.hh)) % 24;
    temp.mm %= 60;

    return temp; //copy constructor is called
}

ostream& operator<<(ostream& out, const Clock& c)
{
     if (c.ss)
        out << c.hh << ":" << c.mm << ":" << c.ss << endl;
     else
        out << c.hh << ":" << c.mm;

     return out;
}


istream& operator>>(istream& in, Clock& k)
{
    in >> k.hh >> k.mm;

    return in;
}




