/***************************************************************************
* TNG033, Fö 12                                                            *
* Test program for class Clock                                             *
* A template function is defined and tested with an array of Clocks        *
* A vector of Clocks is also used                                          *
* Operations of vectors are illustrated: V1 = V2, V1 == V2, V1 < V2        *
* **************************************************************************/


#include <iostream>
#include <iomanip>
#include <vector>

#include "clock.h"

using namespace std;


template<class T>
const T& min(T* A, int n)
{
    T min = A[0];
    for(int i = 0; i < n; i++)
        if (A[i] < min)
            min = A[i];
    return min;
}



int main()
{
    const int SIZE1 = 4;
    const int SIZE2 = 3;

    //Fö 12, slide 7 example
    Clock V2[] = {Clock(10,30,0), Clock(0,30,0), Clock(2,0,0)};
    cout << min(V2,3);

    //calls the default constructor for each Clock
    vector<Clock> C1(SIZE1);

    //Set the Clocks of C1
    C1[0] = Clock(10,30,0);
    C1[1] = Clock(11,0,0);
    C1[2] = Clock(8,30,0);
    C1[3] = Clock(12,0,0);

    vector<Clock> C2(SIZE2);

    //Set the Clocks of C2
    C2[0] = Clock(10,30,0);
    C2[1] = Clock(11,0,0);
    C2[2] = Clock(11,30,0);

    //Comparison of vectors, see slide 27 of Fö 12
    if (C1 < C2)
        cout << "C1 < C2" << endl;
 /*
   //if (C1 < C2) ... same as
   for(int i = 0; i < C2.size(); i++)
   {
       if (C1[i] < C2[i])
       {
           cout << "C1 < C2" << endl;
           break;
       }
   }
*/

    C2 = C1; //Clock::operator= is used

    //Comparison of vectors
    if (C1 == C2)
        cout << "C1 == C2" << endl;
    else
        cout << "C2 =/= C1" << endl;


   return 0;
}


