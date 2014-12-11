/***************************************************************************
* TNG033: Fö 12                                                            *
* Test program for class Clock                                             *
* A vector of Clocks is also used                                          *
* Operations of vectors are illustrated: V1 = V2, V1 == V2, V1 < V2        *
* **************************************************************************/


#include <iostream>
#include <iomanip>
#include <vector>

#include "C:\Arbets\TNG033\Lectures\2014\Fö12\Code12\Clock\clock.h"
//You may need to modify this path to the header file clock.h

using namespace std;


int main()
{
    const int SIZE1 = 4;
    const int SIZE2 = 3;

    Clock V2[] = {Clock(10,30,0), Clock(0,30,0), Clock(2,0,0)};

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

    //Comparison of vectors, see slide 25 of Fö 12
    if (C1 < C2)
        cout << "C1 < C2" << endl;
 /*
   //if (C1 < C2) ... same as
   for(int i = 0; i < C2.size(); i++)
   {
       if (C1[i] < C2[i]) //Clock::operator< is called
       {
           cout << "C1 < C2" << endl;
           break;
       }
   }
*/

    C2 = C1; //the operator= of vector and Clock::operator= are used
/* same as

   for(int i = 0; i < C2.size(); i++)
   {
       C1[i] = C2[i]); //Clock::operator= is called
   }
*/

    //Comparison of vectors
    if (C1 == C2)
        cout << "C1 == C2" << endl;
    else
        cout << "C2 =/= C1" << endl;


   return 0;
}


