/**********************************************************************************
* TNG033, Fö 4                                                                    *
* To illustrate dynamic memory allocation/deallocation                            *
* 1. Request to the user the sequence size                                        *
* 2. Allocate memory for an array to store the sequence                           *
* 3. Read the seqeunce values and then display them                               *
* 4. Deallocate the array's memory                                                *
* ********************************************************************************/


#include <iostream>
#include <iomanip>
#include <new>

using namespace std;


int main()
{
    long int howMany = 0;

    cout << "Enter array size: ";
    cin >> howMany;

    //Program crashes when there's not enough memory
    //double *array = new double[howMany];

    //Allocate memory for an array with howMany slots
    //returns nullptr, if it wasn't possible to allocate memory
    double *array = new (nothrow) double[howMany];

    if (array == nullptr) // if (!array)
    {
        cout << "No memory space :(" << endl << endl;
        return 0;
    }

    cout << "Enter " << howMany << " values: ";

    //Read values into the array
    for(int i = 0; i < howMany; i++)
        cin >> array[i];

    cout << "Array: "  ;

    //Display the values in the array
    for(int i = 0; i < howMany; i++)
        cout << *(array+i) << " ";

    cout << endl;

    //Deallocate the memory of array
    delete [] array;

    return 0;
}
