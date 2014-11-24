/***************************************************************************
* TNG033, Fö 6                                                             *
* Defines a class Clock to represent a clock as hh:mm:ss                   *
* header file clock.h                                                      *
* **************************************************************************/

//Read sec. 7.1, 7.2, 7.3.1-7.3.4, 7.4 of course book

#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED


class Clock
{
    public:
        //constructors
        Clock(); //default constructor
        Clock(int h, int m, int s);

        int get_hours()   const;
        int get_minutes() const;
        int get_seconds() const;

        void display(bool write_sec = true) const;

        void reset(); //resets the clock to 00:00:00

        //To add 1s more to the clock
        void tick(); //does not allow cascading

     private:
            int hh, mm, ss; //represent time as hh:mm:ss

};



#endif // CLOCK_H_INCLUDED
