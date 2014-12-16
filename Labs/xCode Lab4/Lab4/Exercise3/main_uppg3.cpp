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

string file_name = "/Users/Daniel/Skolarbeten/Nuvarande/TNG033-Programmering_i_C++/Labs/xCode Lab4/Lab4/Exercise3/uppgift3.txt";
string file_out = "/Users/Daniel/Skolarbeten/Nuvarande/TNG033-Programmering_i_C++/Labs/xCode Lab4/Lab4/Exercise3/outfile.txt";

ifstream in(file_name);
ofstream os(file_out);

/******************************
 * 1. Functions declarations  *
 ******************************/

typedef vector<string> anagrams;

void display(pair<string, int> subjects);

void displayString(string word);

bool sortByNumber(pair<string, anagrams> p1, pair<string, anagrams> p2);

bool compareWord(pair<string, int> s1, pair<string, int> s2);

bool compareChar(char C, string word);

/******************************
 * 2. Main function           *
 ******************************/

int main()
{
    map<string, anagrams> subjects;
    vector<pair<string, anagrams>>::iterator it;
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
    os << endl << "--ANAGRAMS--" << endl;
    
    vector< pair<string, anagrams> > forSorting(subjects.size());
    
    copy(subjects.begin(), subjects.end(), forSorting.begin());
    
    sort(forSorting.begin(), forSorting.end(), sortByNumber);

    //for_each(forSorting.begin(), forSorting.end(), display);
    
    for (it = forSorting.begin(); it!= forSorting.end(); it++)
    {
        for(vector<string>::const_iterator i = it->second.begin(); i != it->second.end(); ++i)
        {
            os <<  *i << " ";
        }
        os << " --> " << it->second.size() << " words." << endl;
    }
    return 0;
}

/******************************
 * 3. Function definitions    *
 ******************************/
bool sortByNumber(pair<string, anagrams> p1, pair<string, anagrams> p2)
{
    return ( p1.second.size() > p2.second.size() );
}

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




