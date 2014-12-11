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
    ifstream myfile ("uppgift2.txt"); //läser in filen
    ofstream fout ("kul.txt");
    //fout.open("hej.txt");
    if (myfile.is_open())
    {
        int counter = 0;
        string line;
        typedef vector<string> words; //en vektor
        map<string,words> table;
        map<string,words>::iterator it; //typ en pekare

        while ( getline (myfile, line) )
        {
            istringstream instream(line);

            string word = "";
            while (instream >> word)
            {
                transform(word.begin(), word.end(), word.begin(), ::tolower); //ordet blir till gemener
                string str = word;
                sort(str.begin(), str.end()); //sorterar

                it = table.find(str);
                table[str].push_back(word);
                counter++;
            }
        }
        //cout << "Number of words = " << counter << endl << endl << "-- ANAGRAMS --" << endl;
        fout << "Number of words = " << counter << endl << endl << "-- ANAGRAMS --" << endl;
        //ska vi skriva ut till en fil istället?
        for (it = table.begin(); it!= table.end(); it++){
            if(it->second.size()!= 1)
            {
                for( vector<string>::const_iterator i = it->second.begin(); i != it->second.end(); ++i)
                //cout << *i<< ", ";
                //cout << " --> " << it->second.size() << "words." << endl
                fout <<  *i<< ", ";
                fout << " --> " << it->second.size() << "words." << endl;
            }
        }

        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}

