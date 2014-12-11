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
   friend ostream& operator <<(ostream &os, const List& L);
   friend List operator+(const List &L1, const List &L2);

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

   //Constructor: create a list with a node storing value k repeated n times
   //Conversion constructor int -> list
   List (int k, int n=1);

   //destructor
   ~List ();

    //copy constructor
   List (const List &source);


  //Create a new list L1+L2
  friend List operator+(const List &L1, const List &L2);

  //Display a list L to an ostream os
  friend ostream& operator <<(ostream& os, const List& L);


private:
   Node *head;
};

/*****************************************************
* Class List member functions implementation         *
******************************************************/

const int UNDEFINED = -1;

//Default constructor to create an empty list
//Empty list has a dummy node
List::List()
{
    head = new Node(0,0,0); //dummy node
}

//Exercise 2a
//Constructor: create a list with a node storing value k repteated n times
//Conversion constructor int -> list
List::List (int k, int n)
{
    head = new Node(0,0,0); //create an empty list

  if (n > 0)
    head->next = new Node (k, n, NULL);
}


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


//Exercise 2b
ostream& operator<< (ostream& os, const List& L)
{
    if (!L.head->next)
    {
        os << "The list is empty!!" << endl;
        return os;

    }

    Node *ptr = L.head->next;
    while (ptr)
    {
        for(int i = 0; i < ptr->howMany; i++)
            os << ptr -> value << " ";

        ptr = ptr -> next;
    }
	  os << endl;

   return os;
}


//Exercise 2c
 //Create a new list L1+L2
List operator+(const List &L1, const List &L2)
{
    List res;
    Node *ptr_res = res.head;

    Node *ptr1 = L1.head->next, *ptr2 = L2.head->next;

    //Lab 2
    //Go simultaneously through the  nodes of both lists
    //another solution possible is to use an insert function
    while (ptr1 && ptr2)
    {
        if (ptr1->value < ptr2->value)
        {
            ptr_res->next = new Node(ptr1->value, ptr1->howMany, 0);
            ptr_res = ptr_res->next;
            ptr1 = ptr1->next;
        }

        else if (ptr1->value > ptr2->value)
        {
            ptr_res->next = new Node(ptr2->value, ptr2->howMany, 0);
            ptr_res = ptr_res->next;
            ptr2 = ptr2->next;
        }

        else // (ptr1->value == ptr2->value)
        {
            ptr_res->next = new Node(ptr1->value, ptr1->howMany+ptr2->howMany, 0);
            ptr_res = ptr_res->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    //If there are still nodes in list L1
    while (ptr1)
    {
        ptr_res->next = new Node(ptr1->value, ptr1->howMany, 0);
        ptr_res = ptr_res->next;
        ptr1 = ptr1->next;
    }

     //If there are still nodes in list L2
    while (ptr2)
    {
        ptr_res->next = new Node(ptr2->value, ptr2->howMany, 0);
        ptr_res = ptr_res->next;
        ptr2 = ptr2->next;
    }

    return res;
}


/**************************************
* Main function  -- test              *
* DO NOT CHANGE                       *
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
