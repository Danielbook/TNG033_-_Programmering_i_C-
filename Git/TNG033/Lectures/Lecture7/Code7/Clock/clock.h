/***************************************************************************
* TNG033, Fö 7                                                             *
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
        Clock() = default; //request compiler to generate the default constructor
        Clock(int h, int m, int s);

        Clock(const Clock &c); //copy constructor -- not needed

        Clock operator=(const Clock &C); //assignment operator -- not needed

        int get_hours()   const;
        int get_minutes() const;
        int get_seconds() const;

        void display(bool write_sec = true) const;

        void reset(); //resets the clock to 00:00:00

        //To add 1s more to the clock
        //void tick(); //does not allow cascading
        Clock& tick(); //allows cascading

     private:
            //represent time as hh:mm:ss
            //by default all fields are initialized to zero
            int hh {0};  //0-23
            int mm {0};  //0-59
            int ss {0};  //0-59

};



#endif // CLOCK_H_INCLUDED
