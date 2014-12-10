#include <fstream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <utility>

using namespace std;

ifstream fin;
ofstream fout;

typedef vector<string> anagrams;
map<string, anagrams> words;
vector< pair<int, string> > toSort;

int main()
{
    fin.open("uppgift2.txt");
    fout.open("output.txt");

    string word;

    while(fin >> word)
    {
        string w = word;
        sort(w.begin(), w.end());
        words[w].push_back(word);
    }
    int howMany = 0;
    for(map<string, anagrams>::iterator it = words.begin(); it != words.end(); ++it)
    {
        pair<int, string> p;
        p.first = 0;

        for(vector<string>::iterator ii = it->second.begin(); ii != it->second.end(); ++ii)
        {
            p.second += *ii + " ";
            p.first++;
            howMany++;
        }

        toSort.push_back(p);
    }
    fout << "Number of words = " << howMany << endl << endl << "-- ANAGRAMS --" << endl;



    for(vector< pair <int, string> >::iterator ite = toSort.begin(); ite != toSort.end(); ++ite)
    {
        if(ite->first != 1)
        {
              fout << (*ite).second << " --> " << ite->first << " words. \n";
        }

    }

    fin.close();
    fout.close();

    return 0;
}
