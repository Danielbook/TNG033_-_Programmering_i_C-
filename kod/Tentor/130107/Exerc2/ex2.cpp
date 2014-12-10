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

void display(const pair<string, pair<int,int>> &p)
{
     cout << p.first << " "
          << (p.second).first << " " << p.second.second << endl;
}


bool compare(const pair<string, pair<int,int> > &p1,
             const pair<string, pair<int,int> > &p2)
{
    if (p1.second.first < p2.second.first)
        return true;
    else if (p1.second.first == p2.second.first &&
             p1.second.second <= p2.second.second)
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
    cin.ignore();

    file.open(name.c_str());

    if (!file)
    {
        cout << "Could not open file " << name << endl;
        return 0;
    }

    //Code for exercise b.
    typedef map<string,pair<int,int>> Table;

    //Code for exercise c.
    Table T;
    string line, movie = "";

    int min_score, max_score;

    while (getline(file, line))
    {
        istringstream is(line);

        if ( (is >> min_score >> max_score >> ws) && getline(is, movie) )
        {
            transform( movie.begin(), movie.end(),
                       movie.begin(), to_upper );
            T[movie] = make_pair(min_score, max_score);
            //cout << movie << " " << min_score << max_score << endl;
        }
        else
        {
            is.clear(); // reset error flags
            string token;

            movie = "";

            while ( is >> ws >> token && !isdigit(token[0]) )
                movie += (token + " ");

            if (movie.length()) //delete last white space
                movie.erase(movie.length()-1) ;

            if (is)
            {
                istringstream is1(token);

                if (is1 >> min_score && is >> max_score)
                {
                    transform( movie.begin(), movie.end(),
                       movie.begin(), to_upper );
                    T[movie] = make_pair(min_score, max_score);
                }
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
    vector< pair<string, pair<int,int> > > V(T.begin(),T.end());

    sort(V.begin(), V.end(), compare);
    cout << "MOVIES SORTED BY SCORE:" << endl;
    cout << "======================" << endl;
    for_each(V.begin(), V.end(), display);

    //Code for exercise g.
    cout << endl << "Movie name: ";
    getline(cin,movie);
    cout << endl << "Score 1: ";
    cin >> min_score;
    cout << endl << "Score 2: ";
    cin >> max_score;

    transform(movie.begin(), movie.end(), movie.begin(), to_upper);

    Table::iterator it = T.find(movie);

    if ( it == T.end() ) //movie not in the table
    {
        T[movie] = make_pair(min_score, max_score);
    }
    else
        cout << "Movie already exists!!" << endl;

    cout << "\nAfter insert ..." << endl << endl;
    for_each(T.begin(), T.end(), display);

    file.close();

    return 0;
}
