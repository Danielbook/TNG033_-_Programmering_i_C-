/***************************************************************************
* TNG033, Fö 9                                                             *
* Defines a class Clock to represent a clock as hh:mm:ss                   *
* Static data member is used to count number of clocks                     *
* header file clock.h                                                      *
* **************************************************************************/

#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED

#include <iostream>

using namespace std;

class Clock
{
    public:
        //constructors
        Clock(int s = 0); //conversion constructor int to Clock
        Clock(int h, int m, int s);
        Clock (const Clock&);

        ~Clock(); //destructor

        int get_hours()   const;
        int get_minutes() const;
        int get_seconds() const;

        void reset(); //resets the clock to 00:00:00

        //Conversion operator
        //To convert a clock to an int -- number of seconds represented by the clock
        operator int() const;

        //static member function
        static int number_of_clocks();

        friend ostream& operator<<(ostream& os, const Clock& K);

     private:
        int hh, mm, ss; //represent time as hh:mm:ss

        static int n_clocks; //count number of Clock objects

};


#endif // CLOCK_H_INCLUDED
