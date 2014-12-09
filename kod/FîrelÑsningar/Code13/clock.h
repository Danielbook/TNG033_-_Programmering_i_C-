/***************************************************************************
* TNG033, Fö 13                                                            *
* Defines a class Clock to represent a clock as hh:mm:ss                   *
* Class Clock is equipped with overloaded operators                        *
* header file clock.h                                                      *
* **************************************************************************/

#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED

#include <iostream>

using namespace std;

class Clock{
    public:
        //constructors
        Clock(); //default constructor
        Clock(int h, int m, int s = 0);
        Clock(const Clock& K); //copy constructor

        int get_hours()   const;
        int get_minutes() const;
        int get_seconds() const;

        void reset(); //resets the clock to 00:00:00

        //Operator overloading
        Clock operator+(const Clock& K) const;
        Clock& operator++(); //pre-increment of one second
        bool operator==(const Clock& K) const;
        bool operator!=(const Clock& K) const;
        bool operator<(const Clock& K) const;

        friend ostream& operator<<(ostream& os, const Clock& K);
        friend istream& operator>>(istream& in, Clock& k);

     private:
        int hh, mm, ss; //represent time as hh:mm:ss
};


#endif // CLOCK_H_INCLUDED
