#include "set.h"
#include "node.h"
#include <iostream>


//int value;
using namespace std;
//constructor
Set::Set ()
{
   //default constructor
 //deklarerar en ny Node med v�rden 0 0 - en tom Node
    head = new Node(0, 0);
}

Set::Set (const Set& b)
{

    head = new Node(0, 0);

    Node* temp = head;
    Node* tempSet = b.head->next;

    while(tempSet)
    {
        temp->next = new Node(tempSet->value, 0);
        temp = temp->next;
        tempSet = tempSet->next;
    }
}

Set::Set (int a[], int b)
{
    head = new Node(0, 0);
    //Stoppar in den medskickade arrayen in i Noden genom insert
    for(int i = 0; i < b; ++i)
    {
        insert(a[i]);
    }

}


Set::~Set()
{
    Node* n = head -> next;
    //deallocatea v�rden
    while(n)
    {
        delete head;
        head = n;
        n = n -> next;
    }
    delete head;
}

const Set& Set::operator=(const Set& b)
{
    //deallocatea this - Set b
    this->~Set();

    head = new Node(0, 0);

    Node* temp = head;
    Node* tempSet = b.head->next;

    while(tempSet)
    {
        temp->next = new Node(tempSet->value, 0);
        temp = temp->next;
        tempSet = tempSet->next;
    }

    return *this;
}


bool Set::empty() const
{
    //om det omdisktuerade setet �r tomt skickar den true.
    if(head->next) return false;
    else return true;
}

int Set::cardinality() const
{
    //ber�kna hur m�nga element det finns i "head" - returnera antalet elemnt
    int i = 0;

    Node* n = head;

    while(n = (n->next))
    {
        //s� l�nge det finns en n�sta plussa en! yeah!
        ++i;
    }

    return i;
}

bool Set::member (int x) const
{
    Node* n = head;
    //kollar om x finns i head (n)
    //retunerar true om det st�mmer annars false
    while(n = n -> next)
    {
        if(n->value == x)
        {
            return true;
        }
    }

    return false;
}

Set Set::operator+ (const Set& b) const
{
    Set s(*this);
//s�tt ihop b med s
    Node *temp = b.head->next;
    while(temp)
    {
        //om tv� �r likadana s� l�gg bara till en
        s.insert(temp->value);
        temp = temp->next;
    }
    return s;
}

Set Set::operator* (const Set& b) const
{
    //ta bara ut de v�rden som finns i b�da Setsen
    Set s;
    Node *n = b.head;

    while(n)
    {
        //om v�rdena �r samma, stoppa in dem i s
        if(member(n->value))
            s.insert(n->value);

        n = n -> next;
    }

    return s;
}

Set Set::operator- (const Set& b) const
{
    //returnera ett set med de v�rden som bara finns i en.
    Set s;
    Node* n = head;

    while(n = n -> next)
    {
        if(!b.member(n->value))
            s.insert(n->value);
    }

    return s;
}

Set Set::operator+ (int x) const
{
    //l�gg till x p� s(?)
    Set s(*this);

    if(!s.member(x))
        s.insert(x);

    return s;
}

Set Set::operator- (int x) const
{
    //subtraherar x fr�n s(?)
    Set s(*this);

    if(s.member(x))
        s.del(x);

    return s;
}

bool Set::operator<=(const Set& b) const
{
//om nn �r v�rden i b, returnera true!
    Node *nn = head->next;

    while(nn)
    {
        if(!b.member(nn->value)) return false;

        nn = nn -> next;
    }

    return true;
}

bool Set::operator==(const Set& b) const
{
    //om b�da setten �r likadana, returnera true!
    if(*this <= b && b <= *this) return true;
    return false;
}

bool Set::operator<(const Set& b) const
{
    //FR�GA LITE OM DENNA HEJ. VAD VILL AIDA?!

    if(*this <= b && b.cardinality() > cardinality())
        return true;

    return false;
}



void Set::insert (int val)
{
    Node* n = head;
    bool found = false;

    while(n -> next){
        if(val == n->next->value){
            found = true;
            break;
        }
        else if(val < n->next->value){
            n -> next = new Node(val, n->next);
            found = true;
            break;
        }

        n = n -> next;
    }

    if(!found) n -> next = new Node(val, 0);
}

void Set::del (int value)
{
    Node* n = head;

    if(member(value))
    {
        while(n->next)
        {
            if(n->next->value == value)
            {
                Node* i = n->next->next;

                delete n->next;

                n->next = i;
                break;
            }

            n = n->next;
        }
    }
}

ostream& operator << (ostream& os, const Set& b)
{
    //skriv ut saker
    int counter = 0;
    Node* n = b.head;
    os << "{ ";

    while(n = (n -> next))
    {
        os << n -> value << " ";
        counter++;
    }
    os << "}";
    if (counter == 0)
        os << "Set is empty";

    return os;
}
