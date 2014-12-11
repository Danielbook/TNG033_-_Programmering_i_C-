/***************************************************************************
* TNG033, Fö 13                                                            *
* Program to exemplify the use of stream iterators                         *
* 1. Read several clocks from cin                                          *
* 2. Store the clocks in a vector                                          *
* 3. Display the vector                                                    *
* **************************************************************************/

#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <vector>

#include "clock.h"

using namespace std;


int main()
{
    vector<Clock> V;

     cout << "Enter HH:MM " << endl;

    istream_iterator<Clock> in_it(cin);
    istream_iterator<Clock> in_it_end;

    //Read Clock values from cin
    //operator>> defined for Clock class is used by the copy algorithm
    copy(in_it, in_it_end, back_inserter(V));

    cout << endl;

    ostream_iterator<Clock> oit(cout, "\n");

    //Display Clocks stored in the vector to cout
    //operator<< defined for class Clock is used by the copy algorithm
    copy(V.begin(), V.end(), oit);

    return 0;
}


