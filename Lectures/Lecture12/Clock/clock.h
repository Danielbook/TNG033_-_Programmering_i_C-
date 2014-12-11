/***************************************************************************
* TNG033, Fö 9                                                             *
* Defines a class Clock to represent a clock as hh:mm:ss                   *
* Examples of overloaded operators                                         *
* header file clock.h                                                      *
* **************************************************************************/

#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED

#include <iostream>
#include <utility>  //operator>, operator!=, etc

using namespace std;
using namespace std::rel_ops;  //read pag. 276 of course book

class Clock
{
    public:
        //constructors
        Clock(int s = 0); //default constructor and conversion constructor int -> Clock
        Clock(int h, int m, int s);

        int get_hours()   const;
        int get_minutes() const;
        int get_seconds() const;

        void reset(); //resets the clock to 00:00:00

        //Operator overloading
        bool operator==(const Clock& c) const;
        bool operator<(const Clock& c) const;
        Clock& operator++(); //pre-increment of one second
        const Clock operator++(int); //pos-increment of one second, pag. 278 of course book
        const Clock& operator+= (const Clock &K);

        //Supports mixed-mode arithmetic with Clocks and ints
        friend const Clock operator+(const Clock& c1, const Clock& c2);
        friend ostream& operator<<(ostream& out, const Clock& c);

     private:
            //represent time as hh:mm:ss
            int hh;  //0-23
            int mm;  //0-59
            int ss;  //0-59

};

#endif // CLOCK_H_INCLUDED
