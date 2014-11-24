/*************************************************
* TNG033, Fö 5                                   *
* Definition of functions declared in node.h     *
* ************************************************/

#include "list.h"
#include <new>


//Return an empty list, i.e. a list with a dummy node
List empty_list()
{
    List L = new Node;  //dummy node

    L->next = nullptr;

    return L;
}


//Insert n in the beginning of the list L
void insert(List L, int n)
{
    Node *newNode = new Node;

    newNode->value = n;
    newNode->next = L->next; //link the new node to the node after the dummy node

    //Insert after the dummy node
    L->next = newNode; //update L to point to the new node
}


//Insert a value n after node pointed by p
void insert(List L, Node* p, int n)
{
    //Insert new node after p
    Node* newNode = new Node;
    newNode->value = n;
    newNode->next = p->next;
    p->next = newNode;
}



//Remove the node storing n from list L
//If n is not in the list L then L is not modified
void remove(List L, int n)
{
    Node *p = L;

    //1. Find the node before the node to be removed
    while( (p->next != nullptr) && (p->next->value != n) )
        p = p->next;

    //for(p = L; p->next && p->next->value < n; p = p->next) ;

    if (!p->next)  //n not found in list L
        return;

    //2. Remove
    Node *node = p->next;

    p->next = node->next;

    //3. Deallocate the node's memory
    delete node;
}


//Search for a value n in the list
//Return a pointer to the node storing n, if n found
//otherwise, return nullptr
Node* search(List L, int n)
{
    Node *p = L->next;  //skip the dummy node

    while( (p != nullptr) && (p->value != n) )
        p = p->next;

    //for(p = L; p && (p->value != n); p = p->next) ;

    return p;
}


//overloaded operator<<
ostream& operator<<(ostream& out, const List L)
{

    if (!L->next)
        cout << "List is empty!!" << endl;
    else
    {
        for(Node *p = L->next; p; p = p->next)
            out << p->value << "->";

        out << endl;
    }

    return out;
}


