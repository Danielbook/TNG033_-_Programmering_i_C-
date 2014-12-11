/***************************************************************************
* TNG033, Lesson 2                                                         *
* Defines a class Set represented as an array of booleans                  *
* header file set.h                                                        *
* **************************************************************************/


#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

#include <iostream>

using namespace std;

class Set
{
    public:

        //constructors
        Set(int n);        //conversion constructor
        Set(const Set& s); //copy constructor

        ~Set();

        const Set& operator=(const Set& s);

        Set operator+(const Set &s) const;
        Set operator-(const Set &s) const;

        //indexing operators
        bool& operator[](int index);
        bool operator[] (int index) const; //a copy of the bool value stored in the Set is returned

        //Note:It is ok to have two different member functions for a class whose
        //declaration differs only in whether they are declared const or not
        //the first operator[] is called for a Set s(...);
        //while the second operator[] is called for const Set s(...);

        friend ostream& operator<<(ostream& os, const Set& s);

    private:
        int capacity;
        bool* V;

};

#endif // SET_H_INCLUDED
