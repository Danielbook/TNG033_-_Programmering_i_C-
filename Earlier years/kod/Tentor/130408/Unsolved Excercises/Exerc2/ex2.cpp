// =======================================================
// Ex2
// Name:
// Personal number:
// =======================================================


#include <iostream>

using namespace std;

class List;

/********************************
* Class Node definition         *
*********************************/

class Node {
public:
   // Constructor
   Node (int val, int repeat, Node* ptr)
    :  value(val), howMany(repeat), next(ptr)
   { };


private:
   int value;
   int howMany; //how many times the value is repeated
   Node* next;

   friend class List;

};



/********************************
* Class List definition         *
*********************************/

//Nodes
class List {
public:

   //Default constructor to create an empty list
   //Empty list has a dummy node
   List();

   //destructor
   ~List ();

    //copy constructor
   List (const List &source);

   //a) ADD Constructor:
   //create a list storing value k repeated n times

   //b) ADD operator<<

   //c) ADD operator+


private:
   Node *head;
};

/*****************************************************
* Class List member functions implementation         *
******************************************************/

//Default constructor to create an empty list
//Empty list has a dummy node
List::List()
{
    head = new Node(0,0,0); //dummy node
}

//Destructor
List::~List()
{
    Node *temp = head -> next;

    while (temp)
    {
        delete head;
        head = temp;
        temp = temp -> next;
    }
    delete head;
}


//copy constructor
List::List (const List &source)
{
   head = new Node(0,0,0); //dummy node

    Node *newNode = head;
    Node *sourcePtr = source.head->next;

    while (sourcePtr) //copy the nodes from source list
    {
        newNode->next = new Node(sourcePtr->value, sourcePtr->howMany, 0);
        newNode = newNode->next;
        sourcePtr = sourcePtr->next;
    }
}



/**************************************
* Main function  -- test              *
* DO NOT MODIFY                       *
***************************************/

int main()
{

    /**********************************************/
    /*Test Phase 0: constructors                  */
    /**********************************************/
    cout << "***Phase 0" << endl << endl;

    List L1;             //create an empty list
    const List L2(6, 4); //list with value 6 repeated 4 times
    List L3(2);          //list with value 2 only once
    List L4(3, 2);       //list with value 3 repeated 2 times


    /**********************************************/
    /*Test Phase 1: constructors + operator<<     */
    /**********************************************/
    cout << "***Phase 1" << endl << endl;

    cout << "List L1: ";
    cout << L1;

    cout << "List L2: ";
    cout << L2;

    cout << "List L3: ";
    cout << L3;

    cout << "List L4: ";
    cout << L4;

    cout << endl;


    /**********************************************/
    /*Test Phase 2: operator+                     */
    /**********************************************/
    cout << "***Phase 2" << endl << endl;

    cout << "L1 + L2: ";
    cout << L1 + L2;

    cout << "L2 + L3 + L4: ";
    cout << L2 + L3 + L4;

    cout << "L4 + 2: ";
    cout << L4 + 2;

    cout << "3 + L4: ";
    cout << 3 + L4;

    const List L6(L4 + 8 + L2);

    cout << "List L6: ";
    cout << L6;

    cout << "6 + L6: ";
    cout << 6 + L6;

    return 0;
}
