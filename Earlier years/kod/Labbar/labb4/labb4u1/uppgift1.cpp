#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

ifstream fin; //skapa en inl�sare
ofstream fout;//skapa en utskrivare
string cannotCome = "(.,!?:\"();)"; //de tecken som �ro f�rbjudna

map<string, int> words;
vector<pair<int, string> > toSort;

void cleanUp(string &s);

int main()
{
    fin.open("uppgift1.txt");
    fout.open("output3.txt");

    string word;
    int howMany=0;
    while(fin >> word >> ws)
    {
        cleanUp(word);
        words[word]++;
        howMany++;
    }
    int Unique = 0;

    for(map<string, int>::iterator it = words.begin(); it != words.end(); ++it)
         Unique++;



    fout << "Number of words in the file = " << howMany << endl;
    fout << "Number of unique words in the file = " << Unique << endl  << endl;
    fout << "Frequency table sorted alphabetically ..." << endl << endl;

    for(map<string, int>::iterator it = words.begin(); it != words.end(); ++it)
    {
        pair<int, string> p;
        p.first = it->second;
        p.second = it->first;

        toSort.push_back(p);
        fout <<left << setw (20) << it->first << setw (24) << it->second << endl;
    }



    sort(toSort.begin(), toSort.end());
    reverse(toSort.begin(), toSort.end());
    fout << endl << endl << "Frequency table sorted by frequence ..." << endl << endl;
  //  cout << "Frekventiell ordning: " << endl;
    for(vector< pair<int, string> >::iterator ite = toSort.begin(); ite != toSort.end(); ++ite)
    {
        fout << left << setw (20) << ite->second << setw (24) << ite->first << endl;
    }

    fin.close();
    fout.close();

    return 0;
}


void cleanUp(string &s)
{
    std::string temp = "";
    bool found;

    for(int i = 0; i<s.length(); ++i)
    {
        found = false;

        s[i] = tolower(s[i]);

        for(int j = 0; j<cannotCome.length(); ++j)
        {
            if(s[i] == cannotCome[j])// theWord[i] = "";
            {
                found = true;

            }
        }

        if(!found) temp += s[i];
    }

    s = temp;
}
