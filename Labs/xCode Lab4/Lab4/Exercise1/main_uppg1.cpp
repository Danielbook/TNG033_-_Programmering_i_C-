#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

/******************************
 * 1. Variable declarations   *
 *******************************/

string forbidden = ".,!?:\"();";
ifstream in;
ofstream os;

map<string, int> mWords;
vector<pair<int, string> > forSorting;

/*******************************
 * 2. Functions declarations   *
 *******************************/

void transformWord(string &word);

/******************************
* 3. Main function            *
******************************/

int main ()
{
    string file_name = "/Users/Daniel/Skolarbeten/Nuvarande/TNG033-Programmering_i_C++/Labs/xCode Lab4/Lab4/Exercise1/uppgift1.txt";
    string file_out = "/Users/Daniel/Skolarbeten/Nuvarande/TNG033-Programmering_i_C++/Labs/xCode Lab4/Lab4/Exercise1/outfile.txt";
    string word;
    
    int wordCounter = 0;
    int uniqueWord = 0;
    
    in.open(file_name);
    os.open(file_out);
    
    while(in >> word >> ws){
        transformWord(word);
        mWords[word]++;
        wordCounter++;
    }
    
    for(map<string, int>::iterator itr = mWords.begin(); itr != mWords.end(); ++itr){
        uniqueWord++;
    }
    
    os << "Number of words in the file = " << wordCounter << endl;
    os << "Number unique  words in the file = " << uniqueWord << endl << endl << endl;
    os << "Frequency table sorted alphabetically ..." << endl << endl;

    for(map<string, int>::iterator itr = mWords.begin(); itr != mWords.end(); ++itr){
        pair<int, string> pWord;
        pWord.first = itr->second;
        pWord.second = itr->first;
        
        forSorting.push_back(pWord);
        os << left << setw (20) << itr->first << setw (24) << itr->second << endl;
    }
    
    os << endl << endl << "Frequency table sorted by frequence ..." << endl << endl;
    
    sort( forSorting.begin(), forSorting.end() );
    reverse(forSorting.begin(), forSorting.end() );
    
    for(vector<pair<int, string>>::iterator itr = forSorting.begin(); itr != forSorting.end(); ++itr){
        os << left << setw (20) << itr->second << setw (24) << itr->first << endl;
    }

    in.close();
    os.close();
    
    return 0;
}


/*************************************
* 4. Function definitions            *
**************************************/

void transformWord(string &word){
    
    string newWord = "";
    
    bool rubbishFound;
    
    for(int i = 0; i < word.length(); i++) { //Loop the whole word
        
        rubbishFound = false; //Assume the word doesnt contain the forbidden characters
        
        word[i] = tolower( word[i] ); //Lower the case of the letter
        
        for(int k = 0; k < forbidden.length(); k++) { //Loop the letter
            
            if(word[i] == forbidden[k]){
                
                rubbishFound = true;
            }
        }
        
        if(!rubbishFound)
            newWord += word[i];
    }
    word = newWord; //Passes it by reference
}


