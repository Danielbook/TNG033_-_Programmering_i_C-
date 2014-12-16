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

string file_name = "/Users/Daniel/Skolarbeten/Nuvarande/TNG033-Programmering_i_C++/Labs/xCode Lab4/Lab4/Exercise2/uppgift2_kort.txt";
string file_out = "/Users/Daniel/Skolarbeten/Nuvarande/TNG033-Programmering_i_C++/Labs/xCode Lab4/Lab4/Exercise2/outfile.txt";

ifstream in(file_name);
ofstream os(file_out);

/******************************
 * 1. Functions declarations  *
 ******************************/

void display(pair<string, int> subjects);

bool compareWord(pair<string, int> s1, pair<string, int> s2);

bool compareChar(char C, string word);

/******************************
 * 2. Main function           *
 ******************************/

int main()
{
    map<string, int> subjects;
    string word;
    int howMany = 0;
    
    if ( !in )
    {
        cout << "Data file not found!!" << endl;
        return 0;
    }
    
    while(in >> word)
    {
        subjects[word]++;
        howMany++;
    }
    
    os << "Number of words: " << howMany << endl;
    os << endl << "--ANAGRAMS--" << endl << endl;
    
    for_each(subjects.begin(), subjects.end(), display);
    
    
    
    return 0;
}

/******************************
 * 3. Function definitions    *
 ******************************/
void display(pair<string, int> subjects)
{
    os << left << setw (20) << subjects.first << setw (24) << subjects.second << endl;
}



