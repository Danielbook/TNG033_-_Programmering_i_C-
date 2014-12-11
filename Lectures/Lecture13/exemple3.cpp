/***************************************************************************
* TNG033: Fö 13                                                            *
* 1. Read a sequence of user given integers                                *
* 2. Store the user given values in a set                                  *
* 3. Display the values in the set, sorted increasingly                    *
* Note: values in a set are unique and are stored sorted, automatically    *
* **************************************************************************/

#include <iostream>
#include <set>
#include <algorithm>  //find

using namespace std;

//Test data: 1 2 5 -1 66 55 -33 1 66 -1 0 55

int main()
{
   set<int> S;

    int value;

    cout << "Enter a value: ";

    while (cin >> value)  //read + test
    {
          S.insert(value); //add avalue to the set
          //if value already exists in the set then it's not added
    }

    //Display
    cout << endl << endl << "The values sorted : ";

    set<int>::const_iterator cit;

    for(cit = S.begin(); cit != S.end(); ++cit)
    {
    	cout << *cit << "  ";
    }

    cout << endl << endl;

    return 0;
}


