/*****************************************************************************
* TNG033, Fö 5                                                               *
* Header file defining a List of nodes                                       *
* each node stores an int and a pointer to the next node                     *
* Pointers and dynamic memory allocation are used!!                          *
* Dummy nodes are used in the implementation of the lists                 *
* ****************************************************************************/

#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node* next; //points to the next node in the list
};

typedef Node* List; //pointer to the first node in a list
                    //nullptr represents an empty list
                    //Dummy nodes are used in the implementation of the lists

//Return an empty list, i.e. a list with a dummy node
List empty_list();

//Insert n in the beginning of the list L
void insert(List L, int n);
//Question for dugga: why is it not needed to used "List &L"  as argument?


//Insert a value n after node pointed by p
void insert(List L, Node* p, int n);


//Remove the node storing n from list L
//If n is not in the list L then L is not modified
void remove(List L, int n);


//Search for a value n in the list
//Return a pointer to the node storing n, if n found
//otherwise, return nullptr
Node* search(List L, int n);


//overloaded operator<<
ostream& operator<<(ostream& out, const List L);


#endif
