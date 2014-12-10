/***************************************************************************
* TNG033, Fö 6                                                             *
* Program with complicate declarations                                     *
* You can safely skip this example :)                                      *
* **************************************************************************/



#include <iostream>
#include <new>

using namespace std;


int table[5][10];


//Return line i of table after initializing it with -1
//Return a pointer to an array of 10 ints
//C++ cannot return arrays, only pointers to arrays
int (*get_line(int i))[10]
{
    for(int k = 0; k < 10; k++)
        table[i][k] = -1;


    return &table[i]; //pointer to an array of 10 ints
}


int main()
{
    //ref_fun is a reference pointing to function get_line
    int (*(&ref_fun)(int i))[10] = get_line;

    //int (*V)[10] = get_line(3);
    int (*V)[10] = ref_fun(3); //call function through a reference

    for(int k = 0; k < 10; k++)
        cout << (*V)[k] << " ";

    cout << endl;

    return 0;

}
