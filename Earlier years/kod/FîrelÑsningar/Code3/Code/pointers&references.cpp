/***************************************************************************
* TNG033, Fö 6                                                             *
* Program to illustrate the differences between pointers and references    *
* Read the code and understand the output                                  *
* **************************************************************************/

#include <iostream>
#include <iomanip>
#include <new>

using namespace std;

int main()
{

    int n = 10;

    int &ref1 = n;

    cout << "ref1 points to var. n = 10" << endl << endl;
    cout << "ref1 : " << setw(8) << ref1 << endl;
    cout << "&n : " << setw(13) << &n << endl;
    cout << "&ref1 : " << setw(10) << &ref1 << endl;

    int *pt = new int(6);
    int* &ref2 = pt;  //ref is a reference pointing to a pointer

    cout << endl;

    cout << "ref2 points to pointer pt" << endl << endl;
    cout << "*pt" << setw(10) << *pt << endl;
    cout << "ref2 : " << setw(10) << ref2 << endl;
    cout << "pt : " << setw(12) << pt << endl;
    cout << "*ref2 : " << setw(5) << *ref2 << endl;

    return 0;
}
