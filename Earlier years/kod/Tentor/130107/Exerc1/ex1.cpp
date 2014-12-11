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
   List (int A[], int n=0);

   //destructor
   ~List ();

    //copy constructor
   List (const List &source);

   int which_order() const;

   List list_interval_values(int i, int j) const;

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


List::List (const List &source)  //copy constructor
{
   if (!source.header)
   {
	    header = NULL;
   }
   else
   {
	  header = new Node(source.header->value, NULL);
	  Node *newNode = header;
	  Node *sourcePtr = source.header->next;

	  while (sourcePtr)
	  {
        newNode->next = new Node(sourcePtr->value, NULL);
        newNode = newNode->next;
        sourcePtr = sourcePtr->next;
	  }
   }
}


int List::which_order() const
{
    Node *temp = header;
    int prev;
    bool inc = false, dec = false;

    if (temp)
    {
        prev = temp->value;
        temp = temp->next;
    }

    while (temp){
        if (prev < temp->value)
            inc = true;
        if (prev > temp->value)
            dec = true;

         prev = temp->value;
         temp = temp->next; //go to the next node
    }

    if (inc && dec) return 2;
    if (inc && !dec) return 1;
    if (!inc && dec) return -1;

    return 0;
}


List List::list_interval_values(int i, int j) const
{
    List L(0,0); //create empty list

    if (!header)
        return L;

    Node* temp1 = header;
    Node* temp2 = L.header;

    while(temp1)
    {
        //cout << temp1->value << endl;
        if (temp1->value >= i && temp1->value <= j)
        {
            if (!L.header)
            {
                //add first node to list L
                L.header = new Node(temp1->value, NULL);
                temp2 = L.header;
            }
            else
            {
                temp2->next = new Node(temp1->value, NULL);
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }

    return L;
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
    int A1[6] = {1, 4, 3, 2, 4, 7};
    int A2[4] = {8,8,8,8};
    int A3[5] = {1, 4, 5, 6, 7};
    int A4[5] = {5, 3, 2, -1, -4};

    List L1(0,0); //create an empty list
    const List L2(A1, 6);
    List L3(A2, 4);
    List L4(A3, 5);
    List L5(A4, 5);

    cout << "List L1: ";
    cout << L1;

    cout << "List L2: ";
    cout << L2;

    cout << "List L3: ";
    cout << L3;

    cout << "List L4: ";
    cout << L4;

    cout << "List L5: ";
    cout << L5;

    if (L1.which_order() == 0)
        cout << "\nAll elements of List L1 are equal." << endl;

    if (L2.which_order() == 2)
        cout << "List L2 is neither increasing nor decreasing." << endl;

    if (L3.which_order() == 0)
        cout << "All elements of List L3 are equal." << endl;

    if (L4.which_order() == 1)
        cout << "All elements of List L4 are increasing." << endl;

    if (L5.which_order() == -1)
        cout << "All elements of List L5 are decreasing." << endl;

    cout << "\nL2.list_interval_values(0,4): ";
    cout << L2.list_interval_values(3,4);

    cout << "\nL1.list_interval_values(0,4): ";
    cout << L1.list_interval_values(0,4);

    return 0;
}
