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

string file_name = "/Users/Daniel/Skolarbeten/Nuvarande/TNG033-Programmering_i_C++/Labs/xCode Lab4/Lab4/Exercise1/uppgift1.txt";
string file_out = "/Users/Daniel/Skolarbeten/Nuvarande/TNG033-Programmering_i_C++/Labs/xCode Lab4/Lab4/Exercise1/outfile.txt";

ifstream in(file_name);
ofstream os(file_out);

/*******************************
 * 1. Functions declarations   *
 *******************************/
bool polishChar(char c);

void display(pair<string, int> mWords);

bool vectorSorting(pair<string, int> p1, pair<string, int> p2);

/******************************
* 2. Main function            *
******************************/

int main ()
{
    map<string, int> mWords;
    
    
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
        
        copy_if(word.begin(), word.end(), back_inserter(newWord), polishChar);    //Removes unwanted characters
        
        mWords[newWord]++;
        
        howMany++;
    }
    
    os << "Number of words in the file = " << howMany << endl;
    
    os << "Number unique  words in the file = " << distance(mWords.begin(), mWords.end()) << endl;
    
    os << endl << "Frequency table sorted alphabetically ..." << endl << endl;
    
    for_each(mWords.begin(), mWords.end(), display);
    
    os << endl << "Frequency table sorted by frequence ..." << endl << endl;
    
    vector<pair<string, int> > frequency(mWords.size());
    
    copy(mWords.begin(), mWords.end(), frequency.begin());
    
    sort(frequency.begin(), frequency.end(), vectorSorting);
    
    reverse(frequency.begin(), frequency.end());
    
    for_each(frequency.begin(), frequency.end(), display);
    
    return 0;
}


/*************************************
* 3. Function definitions            *
**************************************/

void display(pair<string, int> mWords)
{
    os << left << setw (20) << mWords.first << setw (24) << mWords.second << endl;
}

bool vectorSorting(pair<string, int> p1, pair<string, int> p2){
    if(p1.second > p2.second)
    {
        return false;
    }
    return true;
}

bool polishChar(char c){
    string punctuations = ".,!?:\"();";
    
    std::string::iterator it;

    it = find(punctuations.begin(), punctuations.end(), c);
    
    if (it != punctuations.end())
        return false;
    
    return true;
}



