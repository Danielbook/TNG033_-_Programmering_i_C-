/***************************************************************************
* TNG033, Fö 13                                                            *
* Program to exemplify the use of a map                                    *
* Map is used to represent the time table of a bus                         *
* Key is an object of class Clock                                          *
* The value associated to each key is a city name (string)                 *
* **************************************************************************/

#include <iostream>
#include <iomanip>
#include <map>
#include <iterator>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>


#include "clock.h"

using namespace std;


/*******************************
* 1. Declarations              *
********************************/

typedef map<Clock,string> Schema;

typedef pair<Clock,string> Table_Entry;


char to_upper(char c);

void load_table(Schema &T);

vector<Table_Entry> make_vector(const Schema &T);

bool compare(const Table_Entry &e1, const Table_Entry &e2);

ostream& operator<<(ostream& out, const Table_Entry& e);

ostream& operator<<(ostream& out, const vector<Table_Entry>& V);


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
    cout << vec_table;


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
    T[Clock(8,30)] = "Norrkoping";
    T[Clock(10,30)] = "Linkoping";
    T[Clock(10,0)] = "Soderkoping";
    T[Clock(11,30)] = "Nykoping";
    T[Clock(9,0)] = "Stockholm";
}


ostream& operator<<(ostream& out, const Table_Entry& e)
{
    string S = e.second;

    //uppercase letters
    //transform(S.begin(), S.end(), S.begin(), to_upper);
    transform(S.begin(), S.end(), S.begin(), ::toupper);

    out << e.first;
    out << "   " << setw(15) << left << S;

    return out;
}



vector<Table_Entry> make_vector(const Schema &T)
{
    vector<Table_Entry> ret;

    Schema::const_iterator map_it = T.begin();

    //Table_Entry p;

    while (map_it != T.end())
    {
        //p = make_pair(map_it->first, map_it->second);

        ret.push_back(*map_it);

        map_it++;
    }

    return ret;
}

bool compare(const Table_Entry &e1, const Table_Entry &e2)
{
    return (e1.second <= e2.second);
}


ostream& operator<<(ostream& out, const vector<Table_Entry>& V)
{
    vector<Table_Entry>::const_iterator cit = V.begin();

    while (cit != V.end())
    {
        out << *cit <<endl;
        cit++;
    }

    return out;
}



