/***************************************************************************
* TNG033: Fö 13                                                            *
* Program to exemplify the use of a map                                    *
* Map is used to represent the time table of a bus                         *
* Key is an object of class Clock                                          *
* The value associated to each key is a city name (string)                 *
* 1. The bus schedule is displayed sorted by time (Clock)                  *
* 2. The bus schedule is displayed sorted by city name (string)            *
* **************************************************************************/

#include <iostream>
#include <iomanip>
#include <map>
#include <iterator>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>


#include "C:\Arbets\TNG033\Lectures\2014\Fö13\Code13\Clock\clock.h"
//You may need to modify this path to the header file clock.h

using namespace std;


/*******************************
* 1. Declarations              *
********************************/

typedef map<Clock,string> Schema;

typedef pair<Clock,string> Table_Entry;


char to_upper(char c);

//Load bus schedule
void load_table(Schema &T);

bool compare(const Table_Entry &e1, const Table_Entry &e2);

ostream& operator<<(ostream& out, const Table_Entry& e);


/*******************************
* 2. Main function             *
********************************/

int main()
{
    Schema table;

    //1. Create the schema table (map)
    load_table(table);

    ostream_iterator<Table_Entry> oit(cout, "\n");

    //2. Display table sorted by time (Clock)
    cout << "Time" << "    "
         << setw(15) << left << "Destiny" << endl << endl;

    copy(table.begin(), table.end(), oit);

    cout << endl << endl << endl;

    ///////////////// To display the table sorted by destiny ////////////////

    vector<Table_Entry> vec_table(table.size());

    //1. Copy the pairs in the map to a vector
    //vec_table = make_vector(table);
    copy(table.begin(), table.end(), vec_table.begin());

    //2. Sort vector by destiny
    sort(vec_table.begin(), vec_table.end(), compare);

    //3. Display vector sorted by destiny (string)
    cout << "Time" << "    "
         << setw(15) << left << "Destiny" << endl << endl;

    copy(vec_table.begin(), vec_table.end(), oit);

    return 0;
}



/*******************************
* 3. Functions implementation  *
********************************/

char to_upper(char c)
{
    return toupper(c);
}

void load_table(Schema &T)
{
    T[Clock(8,30,0)] = "Norrkoping";
    T[Clock(10,30,0)] = "Linkoping";
    T[Clock(10,0,0)] = "Soderkoping";
    T[Clock(11,30,0)] = "Nykoping";
    T[Clock(9,0,0)] = "Stockholm";
}


ostream& operator<<(ostream& out, const Table_Entry& e)
{
    string S = e.second;

    //uppercase letters
    //transform(S.begin(), S.end(), S.begin(), to_upper);
    transform(S.begin(), S.end(), S.begin(), ::toupper);

    out << e.first;
    out << "  " << setw(15) << left << S;

    return out;
}


bool compare(const Table_Entry &e1, const Table_Entry &e2)
{
    return (e1.second <= e2.second);
}




