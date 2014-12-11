/***************************************************************************
* TNG033, Fö 9                                                             *
* Defines a class Clock to represent a clock as hh:mm:ss                   *
* Class Clock is equipped with overloaded operators and                    *
* Conversion operators are also given: int to Clock and Clock to int       *
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
        Clock(); //default constructor
        Clock(int s); //convertion constructor int to Clock
        Clock(int h, int m, int s);
        Clock(const Clock &K); //copy constructor

        ~Clock(); //destructor

        int get_hours()   const;
        int get_minutes() const;
        int get_seconds() const;

        void reset(); //resets the clock to 00:00:00

        //Operator overloading
        Clock& operator++(); //pre-increment of one second
        Clock operator+(const Clock& K) const;
        bool operator==(const Clock& K) const;
        bool operator!=(const Clock& K) const;
        Clock& operator+= (const Clock &K);

        //Convertion operator
        //Converts a clock to an int -- number of seconds represented by the clock
        operator int() const;

        //static member function
        static int number_of_clocks();

        friend ostream& operator<<(ostream& os, const Clock& K);

     private:
        int hh, mm, ss; //represent time as hh:mm:ss

        static int n_clocks; //count number of Clock objects

};

//Non-friend operator<<
//ostream& operator<<(ostream& os, const Clock& K)


#endif // CLOCK_H_INCLUDED
