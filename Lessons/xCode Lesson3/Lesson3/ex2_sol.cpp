/******************************
* TNG033: Lesson 3            *
* Exercise 3                  *
*******************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*******************************
* Class Instrument             *
********************************/

class Instrument
{
public:

    //Constructor
    Instrument(string b);


protected:
    string brand;

};


/**********************************
* Class Instrument                *
* Member functions implementation *
***********************************/


//Cosntructor
Instrument::Instrument(string b)
    : brand(b)
{

};


/*******************************
* Class Piano                  *
********************************/


class Piano : public Instrument
{
public:

    Piano(string b) : Instrument(b)
    { };

};

/*******************************
* Class Flute                  *
********************************/


class Flute : public Instrument
{
public:

    Flute(string b) : Instrument(b)
    { };

};

/*******************************
* Class Violin                 *
********************************/


class Violin : public Instrument
{
public:

    Violin(string b) : Instrument(b)
    { };

};


/*******************************
* Main                         *
********************************/


void do_nothing(Piano P)
{
    cout << "\nDo nothing piano ..." << endl;

    //call display_brands()
}

void do_nothing(Flute F)
{
    cout << "\nDo nothing flute..." << endl;

   //call display_brands()
}

void do_nothing(Violin V)
{
    cout << "\nDo nothing violin..." << endl;

   //call display_brands()
}


int main()
{
    Piano P1("Yamaha");
    do_nothing(P1);

    Flute F1("PureTone");
    do_nothing(F1);

    Instrument *ptr_I = new Violin("Stradivarius");

    Piano P2("Bach");
    do_nothing(P2);

    //call display_brands()

    delete ptr_I;

    Flute F2("PureTone");
    do_nothing(F2);

   //call display_brands()

    return 0;
}

