/***************************************************************************
* TNG033, Lesson 2                                                         *
* Source file set.cpp                                                      *
* **************************************************************************/

#include "set.h"

#include <iomanip>
#include <new>
#include <cassert>

//constructors
Set::Set(int n)
{
    capacity = (n < 0)? 10 : n;

    V = new bool[capacity+1];

    for(int i = 0; i <= capacity; i++)
        V[i] = false;

    if (n >= 0)
        V[n] = true;

}


Set::Set(const Set& s)
 : capacity(s.capacity)
{
    V = new bool[s.capacity+1];

    for(int i = 0; i <= capacity; i++)
        V[i] = s.V[i];
}

Set::~Set()
{
    delete [] V;
}

const Set& Set::operator=(const Set& s)
{
    if (this != &s) //test self-assignment
    {
      //1. Deallocate old memory
      delete [] V;

      //2. Allocate new memory
      V = new bool[s.capacity+1];

      //3. Copy matrix M
      capacity = s.capacity;

      for(int i = 0; i <= capacity; i++)
          V[i] = s.V[i];
    }

    return *this;
}


Set Set::operator+(const Set &s) const
{
    int m = 0;

    if (capacity < s.capacity)
        m = s.capacity;
    else
        m = capacity;

    Set temp(m);

    for(int i = 0; i <= capacity; i++)
        temp.V[i] = V[i];

    for(int i = 0; i <= s.capacity; i++)
        temp.V[i] = (s.V[i] || temp.V[i]);

    return temp; //copy constructor is called
}


//Set difference
//Return a new set S1-S2
Set Set::operator-(const Set &S) const
{
    Set temp(*this);

    //remove the elements of S
    for(int i = 0; i <= capacity; i++)
      if ( (i <= S.capacity) && (S.V[i]) ) //short-circuit evaluation is important here
          temp.V[i] = false;

    return temp;
}


//indexing operators
bool& Set::operator[](int index) //set capacity does not grow
{
    assert (index >= 0 && index <= capacity); //can be ignored

    return V[index]; //return a reference
}


bool Set::operator[] (int index) const
{
    if (index < 0 || index > capacity)
        return false;

        cout << index << endl;

    return V[index]; //return a copy
}



ostream& operator<<(ostream& os, const Set& s)
{
    os << "{ ";

    for(int i = 0; i <= s.capacity; i++)
      if (s.V[i])
          os << i << " ";

      os << "}";

     return os;
}



