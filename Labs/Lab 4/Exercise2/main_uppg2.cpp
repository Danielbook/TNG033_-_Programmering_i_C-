#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
#include <iostream>
#include <iterator>

using namespace std;

string file_name = "uppgift2.txt";
string file_out = "outfile.txt";

ifstream in(file_name);
ofstream os(file_out);

/******************************
 * 1. Functions declarations  *
 ******************************/

typedef vector<string> anagrams;

void display(pair<string, int> subjects);

void displayString(string word);

bool compareWord(pair<string, int> s1, pair<string, int> s2);

bool compareChar(char C, string word);

/******************************
 * 2. Main function           *
 ******************************/

int main()
{
    map<string, anagrams> subjects;
    map<string, anagrams>::iterator it;
    string word;
    int howMany = 0;

    if ( !in )
    {
        cout << "Data file not found!!" << endl;
        return 0;
    }

    while(in >> word)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower); //Transform all to lowercase

        string str = word; //Copy the string

        sort(str.begin(), str.end()); //Sort the new string alphabetically

        subjects[str].push_back(word);

        howMany++;
    }

    os << "Number of words = " << howMany << endl;
    os << endl << "-- ANAGRAMS --" << endl;

    //mvector<pair<string, anagrams> > forDisplay(subjects.size());

    //copy(subjects.begin(), subjects.end(), forDisplay.begin());

    for (it = subjects.begin(); it!= subjects.end(); it++)
    {
        if(it->second.size()!= 1)
        {
            for(vector<string>::const_iterator i = it->second.begin(); i != it->second.end(); ++i)
            {
                os <<  *i << " ";
            }
            os << " --> " << it->second.size() << " words." << endl;
        }
    }

    return 0;
}

/******************************
 * 3. Function definitions    *
 ******************************/
void display(pair<string, anagrams> subjects)
{
    if(subjects.second.size()!= 1)
    {
        for_each(subjects.second.begin(), subjects.second.end(), displayString);
        os << " --> " << subjects.second.size() << " words." << endl;
    }
}

void displayString(string word)
{
    os << word << ", "<< endl;
}
