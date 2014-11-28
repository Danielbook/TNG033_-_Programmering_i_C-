#include "set.h"


//Default constructor
Set::Set()
{
    head = new Node(0, 0);
}

//Constructor creating a set
//from n integers in a non-sorted array a
Set::Set (int a[], int n)
{
    head = new Node(0, 0);

    //Check if user inputted n larger than 0
    if(n <= 0) { return; }

    for(int i = 0; i < n; i++) { insert(a[i]); }
}

//copy constructor
Set::Set(const Set &source)
{
    head = new Node(0,0);

    Node* temp = head;
    Node* tempSet = source.head->next;

    while(tempSet)
    {
        temp->next = new Node(tempSet->value, 0);
        temp = temp->next;
        tempSet = tempSet->next;
    }
}

//Destructor: deallocate all nodes
Set::~Set()
{
    Node* listPtr = head->next;

    while (listPtr)
    {
        delete head;
        head = listPtr;
        listPtr = listPtr->next;
    }
    delete head;
}

//Test if set is empty
bool Set::empty() const
{
    if(!head->next) { return true; }
    return false;
}

//Return number of elements in the set
int Set::cardinality() const
{
    int counter = 0;
    Node* listPtr = head;
    while ((listPtr = listPtr->next)) { counter ++; }
    return counter;
}

//Test if x is an element of the set
bool Set::member(int x) const
{
    Node* listPtr = head;

    while( (listPtr = listPtr->next) )
    {
        if(listPtr->value == x) { return true; }
    }
    return false;
}

bool Set::operator<=(const Set& b) const
{
    Node* listPtr = head->next;

    while(listPtr)
    {
        if(!(b.member(listPtr->value))) { return false; }
        listPtr = listPtr->next;
    }
    return true;
}


bool Set::operator==(const Set& b) const
{
    if(*this <= b && b <= *this) { return true; }
    return false;
}

bool Set::operator<(const Set& b)  const
{
    if( (*this <= b) && (cardinality() < b.cardinality()) ) { return true; }
    return false;
}

//Set union
//Repeated values are not allowed
Set Set::operator+(const Set& b) const
{
    Set uni(*this);
    Node *temp = b.head->next;

    while(temp)
    {
        if(!member(temp->value)) { uni.insert(temp->value); }
        temp = temp->next;
    }
    return uni;
}

//Set intersection
Set Set::operator*(const Set& b) const
{
    Set newSet;
    Node* listPtr = b.head;

    while(listPtr)
    {
        if(this->member(listPtr->value)) { newSet.insert(listPtr->value); }
        listPtr = listPtr->next;
    }

    return newSet;
}

//Set difference
Set Set::operator-(const Set& b) const
{
    Set newSet;
    Node* listPtr = head;

    while( (listPtr = listPtr->next) )
    {
        if(!b.member(listPtr->value)) { newSet.insert(listPtr->value); }
    }
    return newSet;
}

//set union with set {x}
Set Set::operator+(int x) const
{
    Set newSet(*this);

    if(!newSet.member(x)) { newSet.insert(x); }
    return newSet;
}

//set difference with set {x}
Set Set::operator-(int x) const
{
    Set newSet(*this);
    if(newSet.member(x)){ newSet.deleteNode(x); }
    return newSet;
}

//Assignment operator
const Set& Set::operator=(const Set &s)
{
    if(this != &s){
        this->~Set();
        head = new Node (0,0);

        Node *temp = head;
        Node *tempSet = s.head->next;

        while(tempSet)
        {
            temp->next = new Node(tempSet->value, 0);
            temp = temp->next;
            tempSet = tempSet->next;
        }
    }
    return *this; //to be deleted
}

void Set::insert(int value)
{
    Node *listPtr = head;

    while(listPtr->next)
    {
        if(!member(value) && value < listPtr->next->value)
        {
            listPtr->next = new Node(value, listPtr->next);
            break;
        }
        listPtr = listPtr->next;
    }

    //If the value is the largest one and not a
    //member of the list, add to the end of the list
    if(!member(value))
    {
        listPtr->next = new Node(value, 0);
    }
}

void Set::deleteNode(int value)
{
    Node* listPtr = head;

    if(member(value))
    {
        while(listPtr->next)
        {
            if(listPtr->next->value == value)
            {
                delete listPtr->next;
                listPtr->next = listPtr->next->next;
                break;
            }
            listPtr = listPtr->next;
        }
    }
}

ostream& operator<<(ostream& os, const Set& theSet)
{
    Node *listPtr = theSet.head;

    if( theSet.empty() )
    {
        os << "Set is empty!" << endl;
        return os;
    }

    os << "{ ";
    while((listPtr = listPtr->next))
    {
        os << listPtr->value << " ";
    }
    os << "}" << endl;
    return os;
}

