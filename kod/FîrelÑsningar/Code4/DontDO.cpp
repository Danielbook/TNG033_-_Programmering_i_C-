/**********************************************************************************
* TNG033, Fö 4                                                                    *
* To illustrate a common mistake when using pointers                              *
* Functions should not return pointers to local variables,                        *
* i.e. have been allocated automatically                                          *
* A function returning a pointer to a local variable can be a "silent" bug        *
* ********************************************************************************/

#include <iostream>
#include <iomanip>
#include <new>
#include <cstring>  //strcmp

using namespace std;


char* read_word1() //NOT CORRECT!!!
{
    char word[50]; //memory allocated automatically

    cout << "Enter a word: ";
    cin >> setw(50) >> word;

    //Returns a pointer to memory that is about to be automatically deallocated
    return word;
    //Note: the array name is converted to a pointer to the firs slot of the array
}



char* read_word2() //CORRECT!!!
{
    char *word = new char[50]; //memory allocated explicitly

    cout << "Enter a word: ";
    cin >> setw(50) >> word;

    return word;
    //Note: the array name is converted to a pointer to the firs slot of the array
}




int main()
{
    char* W;

    while (true)
    {
        W = read_word2();
        //W = read_word1();  //NOT ok!

        cout << "word: " << W << endl;

        if ( !strcmp(W, "STOP") ) break;

        //dealocate the memory pointed by W before reading the next word
        delete [] W;
    }

    return 0;
}
