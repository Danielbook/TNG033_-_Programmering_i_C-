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
/******************************
 * 1. Functions declarations  *
 ******************************/
typedef vector<string> anagrams;
typedef map<string, anagrams> mSub;

void display(pair<string, anagrams> subjects);

void displayString(string word);

bool compareWord(pair<string, int> s1, pair<string, int> s2);

bool compareChar(char C, string word);

namespace std
{
    ostream& operator<<(ostream& os, const mSub &M)
    {
        ostream_iterator<anagrams> out_it(os);
        copy(M.begin(), M.end(), out_it);
        
        return os;
    }
    
    ostream& operator<<(ostream& os, const anagrams &A)
    {
        if(A.size() != 1)
        {
            ostream_iterator<string> out_it(os," ");
            
            copy(A.begin(), A.end(), out_it);
            
            cout << " --> " << A.size() << " words." << endl;
        }
        
        return os;
    }
}

/******************************
 * 2. Main function           *
 ******************************/

int main()
{
    string file_name = "/Users/Daniel/Skolarbeten/Nuvarande/TNG033-Programmering_i_C++/Labs/xCode Lab4/Lab4/Exercise2/uppgift2_kort.txt";
    string file_out = "/Users/Daniel/Skolarbeten/Nuvarande/TNG033-Programmering_i_C++/Labs/xCode Lab4/Lab4/Exercise2/outfile.txt";
    
    ifstream in(file_name);
    ofstream os(file_out);

    mSub subjects;
    mSub::iterator it;
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
    
    cout << "Number of words = " << howMany << endl;
    cout << endl << "-- ANAGRAMS --" << endl;
    
    //for_each(subjects.begin(), subjects.end(), display);
    
    ostream_iterator<mSub> out_it(os);
    
    copy(subjects.begin(), subjects.end(), out_it);
    
    return 0;
}

/******************************
 * 3. Function definitions    *
 ******************************/
//void display(pair<string, anagrams> p1)
//{
//    if(p1.second.size()!= 1)
//    {
//        for_each(p1.second.begin(), p1.second.end(), displayString);
//        cout << " --> " << p1.second.size() << " words." << endl;
//    }
//}
//
//void displayString(string word)
//{
//    cout << word << " ";
//}

//ostream& operator<<(ostream& os, const map<string, anagrams> &M)
//{
//    return os;
//}




