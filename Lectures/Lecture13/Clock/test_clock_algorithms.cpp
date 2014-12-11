/***************************************************************************
* TNG033: Fö 12                                                            *
* Solution for exercise in slide 40                                        *
* Vectors are use                                                          *
* Iterators are used: back_inserter                                        *
* Algorithms are used: copy, sort, transform, and for_each                 *
* **************************************************************************/


#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator> //back_inserter
#include <algorithm> //copy_if, sort

#include "C:\Arbets\TNG033\Lectures\2014\Fö13\Code13\Clock\clock.h"
//You may need to modify this path to the header file clock.h

using namespace std;

bool is_AM(const Clock& K)
{
    return (K.get_hours() < 12);
}

bool is_PM(const Clock& K)
{
    return (K.get_hours() >= 12);
}

void display_clock_AM(const Clock& K)
{
    cout << K << "AM" << endl;
}

void display_clock_PM(const Clock& K)
{
    cout << K << "PM" << endl;
}

Clock to_PM_time(const Clock& K)
{
   int hh = (K.get_hours() > 12)? K.get_hours()-12 : K.get_hours();
   int mm = K.get_minutes();

   return (Clock(hh, mm, 0));
}



int main()
{
    vector<Clock> times;

    int hh, mm;

    cout << "Enter time: ";

    while (cin >> hh >> mm)
    {
        times.push_back(Clock(hh,mm,0));

        cout << "Enter time: ";
    }

    vector<Clock> times_AM; //vector with zero slots
    vector<Clock> times_PM; //vector with zero slots

    /************
    * AM        *
    *************/

    //copy AM clocks and insert them in the times_AM vector
    copy_if(times.begin(), times.end(), back_inserter(times_AM), is_AM);

    //Sort the Clocks in the times _AM vector
    sort(times_AM.begin(), times_AM.end());

    cout << "\nMorning times" << endl;

    //Display all clocks in the times_AM vector
    //Function display_clock is called for each clock in the vector
    for_each(times_AM.begin(), times_AM.end(), display_clock_AM);

    /************
    * PM        *
    *************/

    //copy PM clocks and insert them in the times_PM vector
    copy_if(times.begin(), times.end(), back_inserter(times_PM), is_PM);

    //transform all clocks in times_PM vector to PM time
    transform(times_PM.begin(), times_PM.end(), times_PM.begin(), to_PM_time);

    //Sort the Clocks in the times_PM vector
    sort(times_PM.begin(), times_PM.end());

    cout << "\nAfternoon times" << endl;

    //Display all clocks in the times_AM vector
    //Function display_clock is called for each clock in the vector
    for_each(times_PM.begin(), times_PM.end(), display_clock_PM);

   return 0;
}


