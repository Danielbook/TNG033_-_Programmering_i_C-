/***************************************************************************
* TNG033: Fö 13                                                            *
* 1. Read a sequence of user given times (two integer, hh mm)              *
* 2. Store the user given times (represented with Clock) in a vector       *
* No repeated times should be stored in the vector                         *
* 3. Display the times in the vector, sorted increasingly                  *
* **************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>  //find

#include "C:\Arbets\TNG033\Lectures\2014\Fö13\Code13\Clock\clock.h"
//You may need to modify this path to the header file clock.h

using namespace std;

//Test data: 1 2 5 -1 66 55 -33 1 66 -1 0 55

int main()
{
   vector<Clock> V;

    int hh, mm;

    cout << "Enter a time (hh mm): ";

    while (cin >> hh >> mm)  //read + test
    {
        Clock K (hh, mm, 0);

        //Test if hh:mm has been previously entered by the user
    	if (find(V.begin(), V.end(), K) == V.end()) //Clock::operator== is needed
    	{
    	    V.push_back(K); //add new Clock to the vector
    	}

    	cout << "Enter a time (hh mm): ";
    }

     //Sort
    sort(V.begin(), V.end()); //Clock::operator< is needed

    //Display
    cout << endl << endl << "The times sorted : ";

    vector<Clock>::const_iterator cit;

    for(cit = V.begin(); cit != V.end(); ++cit)
    {
    	cout << *cit << "  ";
    }

    cout << endl << endl;

    return 0;
}


