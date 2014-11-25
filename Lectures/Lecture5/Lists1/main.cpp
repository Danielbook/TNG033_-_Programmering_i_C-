//Test the List and functions available for Lists

#include <iostream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "list.h"


int main()
{
   List L = nullptr; //empty list

   cout << "L:  " << L << endl;

   cout << "\nInserting ..." << endl;

    insert(L,30);
    insert(L,20);
    insert(L,15);
    insert(L,10);

    //Display the list
    cout << "L: " << L;

    /* ****************************** */

//    cout << "\nSearching ..." << endl;
//
//    //search for values in the list
//    Node *p1 = search(L,10); //first value
//    Node *p2 = search(L,30); //last value
//    Node *p3 = search(L,40); //does not exist
//    Node *p4 = search(L,15);
//
//
//    if (p1)
//        cout << "Found " << p1->value << endl;
//    else
//        cout << "10 not found!!" << endl;
//
//
//    if (p2)
//        cout << "Found " << p2->value << endl;
//    else
//        cout << "30 not found!!" << endl;
//
//
//    if (p3)
//        cout << "Found " << p3->value << endl;
//    else
//        cout << "40 not found!!" << endl;
//
//
//    if (p4)
//        cout << "Found " << p4->value << endl;
//    else
//        cout << "15 not found!!" << endl;

    /* ****************************** */

    int n, k;

    cout << "\nEnter new value to insert: ";
    cin >> n;

    cout << "Insert " << n << " after? ";
    cin >> k;

    cout << "Insert " << n
         << " after " << k
         << "..." << endl;

    Node* p_node = search(L, k);

    if ( !p_node )
    {
        cout << k << " not found in the list!!" << endl;
    }
    else
    {
        insert(L, p_node, n);
    }

    //Display the list
    cout << "L: " << L << endl;

    /* ****************************** */

    cout << "\nRemoving 8 and 20..." << endl;

    remove(L, 8);
    remove(L, 20);

    //Display the list
    cout << "L: " << L << endl;

    return 0;
}
