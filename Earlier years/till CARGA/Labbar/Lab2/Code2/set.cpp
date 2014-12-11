#include "set.h"

//Default constructor
Set::Set ()
{
    //skapar en dummy node, pekar på nullptr
    Node *newNode = new Node;
    new

}

//Constructor creating a set
//from n integers in a non-sorted array a
Set::Set (int a[], int n)
{
    //skapar en dummy node

    //loopar igenom listan
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
    Set c;
    return c;
}

//Set intersection
Set Set::operator* (const Set& b) const
{
    //Add code
    Set c;
    return c;
}

//Set difference
Set Set::operator- (const Set& b) const
{
    //Add code
    Set c;
    return c;
}

//set union with set {x}
Set Set::operator+(int x) const
{
    //Add code
    Set c;
    return c;
}

//set difference with set {x}
Set Set::operator-(int x) const
{
    //Add code
    Set c;
    return c;
}

//Assignment operator
const Set& Set::operator=(const Set &s)
{
    //Add code
    Set c;
    return c;
}

ostream& operator<< (ostream& os, const Set& theSet)
{
    //Add code
    return os;
}

