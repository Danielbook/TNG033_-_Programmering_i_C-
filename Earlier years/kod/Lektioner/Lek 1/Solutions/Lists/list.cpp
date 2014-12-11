/*************************************************
* TNG033, Fö 5                                   *
* Definition of functions declared in node.h     *
* ************************************************/

#include "list.h"


//Insert n in the beginning of the list L
void insert(List& L, int n)
{
    Node *newNode = new Node;

    newNode->value = n;
    newNode->next = L; //link the new node to the first node of list L
    L = newNode; //update L to point to the new node
}


//Insert n in a sorted list L
//No dummy nodes are used in the list
void insert_sorted(List& L, int n)
{
    //insert in an empty list or as first node of the list
    if ( !L || L->value >= n )
    {
        Node *newNode = new Node;

        newNode->value = n;
        newNode->next = L;
        L = newNode;
    }
    else
    {
        Node* node = L; //L is not empty

        //1. find the node after which insertion should occur
        while( (node->next != nullptr) && (node->next->value < n) )
            node= node->next;

        //for(p = L; p->next && p->next->value < n; p = p->next) ;

        //2. insert new node after p
        Node* newNode = new Node;
        newNode->value = n;
        newNode->next = node->next;
        node->next = newNode;
    }
}



//Remove the node storing n from list L
//If n is not in the list L then L is not modified
void remove(List& L, int n)
{
    if (!L) //empty list
        return;

    //remove first node of the list
    if (L->value == n )
    {
        Node* node = L; //point to first node
        L = L->next;

        delete node; //delete first node
    }
    else
    {
        Node *node = L;  //L is not empty

        //1. Find the node before the node to be removed
        while( (node->next != nullptr) && (node->next->value != n) )
            node = node->next;

        if (!node->next)  //n not found
            return;

        //2. Remove
        Node *p = node->next;

        node->next = p->next;
        delete p; //deallocate
    }
}


//Search for a value n in the list
//Return a pointer to the node storing n, if n found
//otherwise, return nullptr
Node* search(List L, int n)
{
    Node *p = L;

    while( (p != nullptr) && (p->value != n) )
        p = p->next;

    //for(p = L; p && (p->value != n); p = p->next) ;

    return p;
}


//overloaded operator<<
ostream& operator<<(ostream& out, const List L)
{

    if (!L)
        cout << "List is empty!!" << endl;
    else
    {
        for(Node *p = L; p; p = p->next)
            out << p->value << "->";

        out << endl;
    }

    return out;
}

/*
//Insert n in the end of the list
//Return  the new updated list
void insert_last(List& L, int n)
{
    if (!L) //if (L == nullptr) -- empty list
        return( insert(L, n) ); //return a pointer to the first node
    else
    {
        Node *p;

        //Go until end of thelist
        for(p = L; p->next; p = p->next);

        //now, p points to the last node in the list
        insert(p->next,n); //insert new node after p
    }
}

*/

//Insert n in the end of the list
//Return  the new updated list
void insert_last(List& L, int n)
{
    if (!L) //if (L == nullptr) -- empty list
    {
        L = new Node;

        L->value = n;
        L->next = nullptr;
    }
    else
    {
        Node *p;

        //Go until end of thelist
        for(p = L; p->next; p = p->next);

        //now, p points to the last node in the list
        p->next = new Node; //add a new node to the end of the list

        p->next->value = n;
        p->next->next = nullptr;
    }
}



