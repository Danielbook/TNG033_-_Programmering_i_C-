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
/*******************************
 * 1. Functions declarations   *
 *******************************/
typedef map<string, int> mapStore;
typedef pair<string, int> pDisplay;

bool polishChar(char c);

void display(pair<string, int> mWords);

bool vectorSorting(pair<string, int> p1, pair<string, int> p2);

namespace std {
    ostream& operator<<(ostream& os, const pDisplay& p1)
    {
        os << left << setw (20) << p1.first << setw (24) << p1.second << endl;
        return os;
    }
}
/******************************
* 2. Main function            *
******************************/
int main ()
{
    mapStore mWords;
    
    string file_name = "/Users/Daniel/Skolarbeten/Nuvarande/TNG033-Programmering_i_C++/Labs/xCode Lab4/Lab4/Exercise1/uppgift1.txt";
    string file_out = "/Users/Daniel/Skolarbeten/Nuvarande/TNG033-Programmering_i_C++/Labs/xCode Lab4/Lab4/Exercise1/outfile.txt";
    
    ifstream in(file_name);
    ofstream os(file_out);
    
    if ( !in )
    {
        cout << "Data file not found!!" << endl;
        return 0;
    }
    
    string word = "";
    int howMany = 0;
    
    while ( in >> word >> ws ){
        
        transform(word.begin(), word.end(), word.begin(), ::tolower); //Transform all to lowercase
        
        string newWord;
        newWord.reserve(word.size());
        
        copy_if(word.begin(), word.end(), back_inserter(newWord), polishChar); //Removes unwanted characters
        
        mWords[newWord]++;
        
        howMany++;
    }
    
    os << "Number of words in the file = " << howMany << endl;
    
    os << "Number unique  words in the file = " << distance(mWords.begin(), mWords.end()) << endl;
    
    os << endl << "Frequency table sorted alphabetically ..." << endl << endl;
    
    //for_each(mWords.begin(), mWords.end(), display);
    
    os << endl << "Frequency table sorted by frequence ..." << endl << endl;
    
    vector<pair<string, int> > frequency(mWords.size());
    
    copy(mWords.begin(), mWords.end(), frequency.begin());
    
    sort(frequency.begin(), frequency.end(), vectorSorting);
    
    ostream_iterator<pDisplay> out_it(os);
    
    copy(frequency.begin(), frequency.end(), out_it);
    
    return 0;
}

/*************************************
* 3. Function definitions            *
**************************************/
bool vectorSorting(pair<string, int> p1, pair<string, int> p2){
    if(p1.second > p2.second)
    {
        return true;
    }
    return false;
}

bool polishChar(char c){
    string punctuations = ".,!?:\"();";
    
    std::string::iterator it;

    it = find(punctuations.begin(), punctuations.end(), c);
    
    if (it != punctuations.end())
        return false;
    
    return true;
}




