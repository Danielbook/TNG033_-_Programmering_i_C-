/***************************************************************************
* TNG033: Fö 13                                                            *
* 1. Read a sequence of user given integers                                *
* 2. Store the user given values in a list, but without repeated values    *
* 3. Display the values in the list, sorted increasingly                   *
* **************************************************************************/

#include <iostream>
#include <list>       //sort
#include <algorithm>  //find

using namespace std;

//Test data: 1 2 5 -1 66 55 -33 1 66 -1 0 55

int main()
{
   list<int> L;

    int value;

    cout << "Enter a value: ";

    while (cin >> value)  //read + test
    {
        //Test if value has been previously entered by the user
    	if (find(L.begin(), L.end(), value) == L.end())
    	{
          L.push_back(value); //add new value to the vector
    	}
    }

    //Sort
    L.sort( );  //Note: algorithm sort cannot be used with lists cause it requires random-access iterators

    //Display
    cout << endl << endl << "The values sorted : ";

    list<int>::const_iterator cit;

    //for(cit = L.begin(); cit != L.begin() + L.size(); ++cit) //<-- does not compile!!
    for(cit = L.begin(); cit != L.end(); ++cit)
    {
    	cout << *cit << "  ";
    }

    cout << endl << endl;

    return 0;
}


