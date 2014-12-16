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
typedef map<string, anagrams> anagramMap;
typedef pair<string, anagrams> displayPair;

namespace std
{
    ostream& operator<<(ostream& os, const displayPair &dP)
    {
        if(dP.second.size() > 1)
        {
            ostream_iterator<string> out_it(os, " ");
            copy(dP.second.begin(), dP.second.end(), out_it);
            os << " --> " << dP.second.size() << " words." << endl;
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

    anagramMap subjects;
    anagramMap::iterator it;
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
    
    vector<displayPair> toDisplay(subjects.size());
    
    copy(subjects.begin(), subjects.end(), toDisplay.begin());
    
    ostream_iterator<displayPair> out_it(os);
    
    copy(toDisplay.begin(), toDisplay.end(), out_it);
    
    return 0;
}


