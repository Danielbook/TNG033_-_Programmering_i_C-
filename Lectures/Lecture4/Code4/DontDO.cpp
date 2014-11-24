/*******************************************************************************************
* TNG033, Fö 4                                                                             *
* To illustrate a common mistake when using pointers                                       *
* Functions should not return pointers to local variables,                                 *
* i.e. variables allocated automatically                                                   *
* A function returning a pointer to a local variable is a (possible "silent") serious bug  *
* ******************************************************************************************/

#include <iostream>
#include <new>

using namespace std;


int* read_seq1() //NOT CORRECT!!!
{
    int seq[10]; //memory allocated automatically

    cout << "\nEnter a sequence: ";
    for(int i = 0; i < 10; i++)
        cin >> seq[i];

    //Returns a pointer to memory that is about to be automatically deallocated
    return seq;
    //Note: the array name is converted to a pointer to the firs slot of the array
}



int* read_seq2() //CORRECT!!!
{
    int *seq = new int[10]; //memory allocated explicitly

    cout << "\nEnter a sequence: ";
    for(int i = 0; i < 10; i++)
        cin >> seq[i];

    return seq;
}


int main()
{
    int* ptr;

    while (true)
    {
        ptr = read_seq2();
        //ptr = read_seq1();  //NOT ok!

        cout << "\nSequence: ";
        for(int i = 0; i < 10; i++)
            cout << *(ptr+i) << " ";

        cout << endl;

        if ( *ptr < 0 ) break;

        //dealocate the memory pointed by ptr before reading next sequence
        delete [] ptr;
    }

    return 0;
}
