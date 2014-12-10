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

   //Constructor
   List (int A[], int n);

   //destructor
   ~List ();

   bool repeated_member(int i);

   const List& operator-= (int i);

   friend ostream& operator << (ostream& os, const List& L);


private:
   Node *header;
};

/*****************************************************
* Class List member functions implementation         *
******************************************************/

List::List (int A[], int n)
{
  if (!n)
    header = NULL; //create an empty list
  else {
      header = new Node (A[0], NULL);
      Node *temp = header;

      for (int i = 1; i < n; i++){
        temp->next = new Node(A[i],NULL);
        temp = temp->next;
        }
  }
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

bool List::repeated_member(int i)
{
    Node *temp = header;
    bool found = false;

    while (temp){
        if (temp->value == i)
            if (found)
                return true;
            else
                found = true;

         temp = temp->next; //go to the next node
    }

    return false;
}


const List& List::operator-= (int i)
{
    if (!repeated_member(i))
        return *this;

    //find first node with i
    Node *temp = header;

    while (temp->value != i)
        temp = temp->next;

    //delete all nodes after temp with i
    while (temp->next){
        if (temp->next->value == i){ //delete
            Node *p = temp->next;
            temp->next = temp->next->next;
            delete p;
            }
        else temp = temp->next;

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
    int A1[5] = {1, 4, 5, 1, 4};
    int A2[4] = {8,8,8,8};

    List L1(0,0); //create an empty list
    List L2(A1, 5);
    List L3(A2, 4);

    cout << "List L1: ";
    cout << L1;

    cout << "List L2: ";
    cout << L2;

    cout << "List L3: ";
    cout << L3;

    if (L1.repeated_member(3))
        cout << "Value 3 repeated in list L1."  << endl;
    else
        cout << "Value 3 not repeated in list L1."  << endl;

    cout << endl;

    L1 -= 3;
    cout << "List L1 after deleting repeated 3s: ";
    cout << L1;

    L2 -= 0;
    cout << "List L2 after deleting repeated 0s: ";
    cout << L2;

    L2 -= 1;
    cout << "List L2 after deleting repeated 1s: ";
    cout << L2;

    L2 -= 4;
    cout << "List L2 after deleting repeated 4s: ";
    cout << L2;

    L3 -= 8;
    cout << "List L3 after deleting repeated 8s: ";
    cout << L3;

    return 0;
}
