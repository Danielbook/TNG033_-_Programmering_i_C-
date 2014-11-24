#include "set.h"

//Default constructor
Set::Set ()
{
    //Add code
    
}

//Constructor creating a set
//from n integers in a non-sorted array a
Set::Set (int a[], int n)
{
    //Add code
    if(n <= 0) //Check if user inputted n larger than 0
    {
        return;
    }
    
    for(int i = 0; i < n; i++) //Init the slots of the array
    {
        
    }
}

//copy constructor
Set::Set (const Set &source)
{
   //Add code
}

//Destructor: deallocate all nodes
Set::~Set ()
{
    //Add code
}

//Test if set is empty
bool Set::empty () const
{
    //Add code
    return false;
}

//Return number of elements in the set
int Set::cardinality() const
{
    //Add code
    return 0;
}

//Test if x is an element of the set
bool Set::member (int x) const
{
    //Add code
    return false;
}

bool Set:: operator<=(const Set& b) const
{
    //Add code
    return false;
}


bool Set:: operator==(const Set& b) const
{
    //Add code
    return false;
}

bool Set:: operator<(const Set& b)  const
{
    //Add code
    return false;
}


//Set union
//Repeated values are not allowed
Set Set::operator+ (const Set& b) const
{
    //Add code
    return *this; //to be deleted
}

//Set intersection
Set Set::operator* (const Set& b) const
{
    //Add code
   return *this; //to be deleted
}

//Set difference
Set Set::operator- (const Set& b) const
{
    //Add code
    return *this; //to be deleted
}

//set union with set {x}
Set Set::operator+(int x) const
{
    //Add code
    return *this; //to be deleted
}

//set difference with set {x}
Set Set::operator-(int x) const
{
    //Add code
    return *this; //to be deleted
}

//Assignment operator
const Set& Set::operator=(const Set &s)
{
    //Add code
    return *this; //to be deleted
}

ostream& operator<< (ostream& os, const Set& theSet)
{
    //Add code
    return os;
}

