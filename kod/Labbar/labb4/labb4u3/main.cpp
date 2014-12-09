#include <fstream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <set>


using namespace std;

ifstream fin;
ofstream fout;

typedef vector<string> anagrams;
typedef pair<int, string> anagrams_entry;
typedef pair<string, anagrams> PAIR;

map<string, anagrams> words;
vector< pair<int, string> > toSort;

void display(const anagrams &v)
{
    if (v.size()!=0)
    {
      for(int i=0;i<v.size();i++)
        fout << v[i] << " ";

        fout << " " <<v.size() <<  endl;
    }
}
bool compare(const anagrams &e1, const anagrams &e2)
{
    return (e1.size() > e2.size());
}

vector<string> getAnagrams(const PAIR& p)
{
    return p.second;
}
int main()
{
    fin.open("uppgift3_kort.txt");
    fout.open("output.txt");
    string word;
    int howMany = 0;
    while(fin >> word)
    {
        string w = word;
        sort(w.begin(), w.end());

        words[w].push_back(word);
        howMany++;
    }
   /*   int howMany = 0;
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

    cout << "Heyoooo" << endl;*/
    vector<anagrams>vec_words(words.size());
    transform(words.begin(),words.end(),back_inserter(vec_words), getAnagrams);
    sort(vec_words.begin(),vec_words.end(),compare);
    fout << "Number of words = " << howMany << endl << endl << "-- ANAGRAMS --" << endl;


    for_each(vec_words.begin(), vec_words.end(), display);

    fin.close();
    fout.close();

    return 0;
}
