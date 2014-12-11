#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>

using namespace std;


char to_upper (char c)
{
    return toupper(c);
}

void display(const pair<string, int> &p)
{
     cout << p.first << " " << p.second << endl;
}

bool compare(const pair<string, int> &p1, const pair<string, int> &p2)
{
    if (p1.second <= p2.second)
        return true;

    return false;
}


/**************************************
* Main function                       *
***************************************/


int main()
{
    //Code for exercise a.

    ifstream file;
    string name;

    cout << "File name: ";
    cin >> name;

    file.open(name.c_str());

    if (!file)
    {
        cout << "Could not open file " << name << endl;
        return 0;
    }

    //Code for exercise b.
    typedef map<string,int> Table;

    //Code for exercise c.
    Table T;
    string line, movie;

    int score;


    while (getline(file, line))
    {
        istringstream is(line);

        if ( (is >> score >> ws) && getline(is, movie) )
        {
            if ( ( score >= 1) && (score <= 5) ){
            transform(movie.begin(), movie.end(), movie.begin(), to_upper);
            T[movie] = score;
            //cout << movie << " " << score << endl;
            }
        }
    }

    //Code for exercise d.
    cout << "Number of movies read: " << T.size() << endl << endl;

    //Code for exercise e.

    //for(Table::iterator it = T.begin(); it != T.end(); it++)
        //cout << *it <<  endl;

    cout << "MOVIES SORTED BY NAME:" << endl;
    cout << "======================" << endl;
    for_each(T.begin(), T.end(), display);
    cout << endl;

    //Code for exercise f.
    vector< pair<string,int> > V(T.begin(),T.end());

    sort(V.begin(), V.end(), compare);
    cout << "MOVIES SORTED BY SCORE:" << endl;
    cout << "======================" << endl;
    for_each(V.begin(), V.end(), display);

    //Code for exercise g.
    cout << endl << "Movie name: ";
    cin >> movie;

    transform(movie.begin(), movie.end(), movie.begin(), to_upper);

    Table::iterator it = T.find(movie);

    if ( it != T.end() )
        cout << "Score = " << it-> second << endl;
    else
        cout << "Movie not found!!" << endl;


    file.close();

    return 0;
}
