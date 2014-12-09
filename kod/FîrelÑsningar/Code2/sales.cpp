/********************************************************************
* TNG033, Fö 2                                                      *
* Program to test the data type Salesman                            *
* 1. Create a database (array) of salesman                          *
* 2. Sort the database by salesman's name                           *
* 3. Search the database by a user given salesman's name            *
* *******************************************************************/


#include <iostream>
#include <iomanip>
#include <fstream>

#include "salesman.h"

using namespace std;

const int NOT_FOUND = -1;


/*******************************
* 1. Function Declarations     *
********************************/


//Sort an array V of salesman by name
//n is the numbers of records stored in V
void bubbelsort(Salesman V[], int n);


//Search for a salesman with name s in array V
//n is the numbers of records stored in the array
//If s is found in slot V[i] then function returns i
//If s is not found in V then return NOT_FOUND
//V is sorted and binary search is used
//Binary search: see pag. 112 of course book
int binary_search(Salesman V[], int n, string s);


//Read salesman data from cin and store it in V
//V can store at most n records
//Return the number of records read and stored in V
int read_DB(Salesman V[], int n);



/*******************************
* 2. Main function             *
*******************************/


int main()
{
    const int SIZE = 100;

    Salesman DB[SIZE];
    int howMany = 0; //number of salesman stored in DB

    cout << "Reading data from file ..." << endl;

    //Read the data for salesmans and store it in DB
    howMany = read_DB(DB, SIZE);

    //sort DB by salesman's names
    bubbelsort(DB, howMany);

    //table header
    cout << setw(20) << left << "Salesman"
         << setw(20) << left << "Sales" << endl << endl;

    //display the sorted DB
    for(int i = 0; i < howMany; i++)
        cout << DB[i];

    cout << endl;

    string nn;

    while (true)
    {
        cout << "Enter salesman name: ";
        getline(cin, nn);

        if ( nn == "STOP" )
            break; //exit the loop

        int pos;

        if ( (pos = binary_search(DB, howMany, nn)) != NOT_FOUND )
        {
            cout << DB[pos];
        }
        else
            cout << "Salesman not found!!" << endl;

    }

    return 0;
}



/*******************************
* 3. Functions implementation  *
********************************/

//Read salesman data and store it in V
//V can store at most n records
//Return the number of added records
int read_DB(Salesman V[], int n)
{
    int count = 0;

    ifstream file("sales_data.txt");

    if (!file.is_open())
    {
        cout << "Data file not found!!" << endl;
        return 0;
    }

    while ( (count < n) && (file >> V[count]) ) //overload operator>> called
        ++count;

    return count;
}


//Sort an array V of salesman by name
//n is the numbers of records stored in V
void bubbelsort(Salesman V[], int n)
{
    Salesman temp;

    //sort
    for ( int pass = 0; pass <= n - 2; pass++ ) // passes

        for (int i = 0; i <  n - 1; i++ )      // one pass
        {

            if ( V[ i ] > V[ i + 1 ]) //overloaded operator> called
            {
                //swap
                temp = V[ i ];
                V[ i ] = V[ i + 1 ];
                V[ i + 1 ] = temp;
            }
        }
}


//Search for a salesman with name s in array V
//n is the numbers of records stored in the array
//If s is found in slot V[i] then function returns i
//If s is not found in V then return NOT_FOUND
//V is sorted and binary search is used
//Binary search: see pag. 112 of course book
int binary_search(Salesman V[], int n, string s)

{
    int first = 0, last = n - 1;

    while (first <= last)
    {
        int mid = (first + last) / 2;

        if (s < V[mid].name) //search the left-half
            last = mid - 1;
        else if (s > V[mid].name) //search the right-half
            first = mid + 1;
        else
            return mid; //found
    }

    return NOT_FOUND;
}


