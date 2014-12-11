/***************************************************************************
* TNG033: Fö 13                                                            *
* 1. Read a sequence of user given integers                                *
* 2. Store the user given values in a vector, but without repeated values  *
* 3. Display the values in the vector, sorted increasingly                 *
* **************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>  //find, sort

using namespace std;

//Test data: 1 2 5 -1 66 55 -33 1 66 -1 0 55

int main()
{
    vector<int> V;

    int value;

    cout << "Enter a value: ";

    while (cin >> value)  //read + test
    {
        //Test if value has been previously entered by the user
    	if (find(V.begin(), V.end(), value) == V.end())
    	{
    	    V.push_back(value); //add new value to the vector
    	}
    }

    //Sort
    sort(V.begin(), V.end());

    //Display
    cout << endl << endl << "The values sorted : ";

    vector<int>::const_iterator cit;

    //for(cit = V.begin(); cit != V.begin()+V.size(); ++cit)
    for(cit = V.begin(); cit != V.end(); ++cit)
    {
    	cout << *cit << "  ";
    }

    cout << endl << endl;

    return 0;
}


