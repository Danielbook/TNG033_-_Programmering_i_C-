
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <cctype>
#include <map>
#include <vector>

using namespace std;

int main()
{
    ifstream myfile ("uppgift3.txt");
    if (myfile.is_open())
    {
        int counter = 0;
        string line;
        typedef vector<string> words;

        map<string,words> table;
        map<string,words>::iterator it;

        multimap<int,words> table2; //massa värden som är samma
        multimap<int,words>::reverse_iterator it2;
        while ( getline (myfile, line) )
        {

            istringstream instream(line);

            string word = "";
            while (instream >> word)
            {
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                string str = word;
                sort(str.begin(), str.end());

                it = table.find(str);
                table[str].push_back(word);
                counter++;
            }
        }

        for (it = table.begin(); it!= table.end(); it++){
            table2.insert(make_pair(it->second.size(), it->second));
        }


        cout << "Number of words = " << counter << endl << endl << "-- ANAGRAMS --" << endl;
        for (it2 = table2.rbegin(); it2!= table2.rend(); it2++){

                for( vector<string>::const_iterator i = it2->second.begin(); i != it2->second.end(); ++i)
                cout << *i<< ", ";
                cout << " --> " << it2->second.size() << "words." << endl;

        }

        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}

