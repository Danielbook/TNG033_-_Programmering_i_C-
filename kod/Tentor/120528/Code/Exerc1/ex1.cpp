#include <iostream>

using namespace std;

class List;

/********************************
* Class Node definition         *
*********************************/

class Node {
public:
   // Constructor
   Node (int i, Node* ptr):  value (i), next (ptr)
   { };


private:
   int value;
   Node* next;

   friend class List;
   friend ostream& operator <<(ostream &os, const List& L);
};



/********************************
* Class List definition         *
*********************************/

class List {
public:

   //Constructors
   List() { header = NULL; }
   List (int i);

   //destructor
   ~List ();

   List& operator+ (const List& L);

   friend ostream& operator << (ostream& os, const List& L);


private:
   Node *header;
};

/*****************************************************
* Class List member functions implementation         *
******************************************************/

List::List(int i)
{
  header = new Node (i, NULL);
}


List::~List()
{
    if (header)
	  {
		 Node *temp = header -> next;
		 while (temp != NULL)
		 {
			delete header;
			header = temp;
			temp = temp -> next;
		 }
		 delete header;
	  }
}


List& List::operator+ (const List& L)  //append
{
    Node* temp2 = L.header;

    if (!L.header)
        return *this;

    if (!header)
    {
        header = new Node(L.header->value, NULL);
        temp2 = L.header->next;
    }

    Node *temp1 = header;

    while (temp1->next) //walk until the last node of the list
        temp1 = temp1->next;

    Node* end = temp1;

    while (temp2 && temp2 != end) //avoid looping with self-appending
    {
        //cout << temp2->value << " " << temp1->value << endl;
        temp1->next = new Node(temp2->value,NULL);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (this == &L) // if self-appending
    {
        //copy last node
        temp1->next = new Node(end->value,NULL);
    }

    return *this;
}



ostream& operator<< (ostream& os, const List& L)
{
    if (!L.header)
    {
        os << "The list is empty!!" << endl;
        return os;

    }

    Node *temp = L.header;
    while (temp)
    {
        os << temp -> value << " ";
        temp = temp -> next;
    }
	  os << endl;

   return os;
}


/**************************************
* Main function  -- test              *
* DO NOT CHANGE                       *
***************************************/

int main()
{
    List L1, L2;
    List L3(3), L4(4), L5(5), L6(6);

    cout << "List L1: " << L1 << endl;
    cout << "List L2: " << L2 << endl;
    cout << "List L3: " << L3 << endl;
    cout << "List L4: " << L4 << endl;
    cout << "List L5: " << L5 << endl;
    cout << "List L6: " << L6 << endl;
    cout << "List L1+L2: " << L1+L2 << endl;

    L3+L4+L5+L6;
    cout << "List L3+L4+L5+L6: " << L3 << endl;

    L1+L3;
    cout << "List L1+L3: " << L1 << endl;

    L3+L2;
    cout << "List L3+L2: " << L3 << endl;

    L3+L3; //self-appending
    cout << "Self-appending L3+L3: " << L3 << endl;

    return 0;
}
