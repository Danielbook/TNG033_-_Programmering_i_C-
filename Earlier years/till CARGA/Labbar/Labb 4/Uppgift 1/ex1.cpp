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
#include <utility>


using namespace std;
//skicka in något konstigt, döper den till en pair som består av en string och en int
typedef pair<string, int> typen;

bool compareTo(const typen& T, const typen& K) //måste alltid vara cont och en referens
{
    return (T.second > K.second);
}

void display(const typen& T)
{
    cout << left << setw(30) << T.second << T.first << endl;
}


int main()
{
     cout << "Innan vi öpnnar txt " << endl;
    //ifstream myfile ("uppgift1.txt");
    //ofstream fout;
    cout << "Innan vi öpnnar txt " << endl;
    //fout.open("hej.txt");
    //if (myfile.is_open())
    //{

        string line;
        map<string,int> table; //bestŒr av en string & int, heter table


        map<string,int>::iterator it; //lik en pekar, ger igenom alla element
        //map<string,int>::iterator it2;
        //vector<pair<int, string> > toSort;

        //while ( getline (myfile, line) )
        //{

            istringstream instream(line);

            string word = "";
            char badChars[10] = ".,!?:\();"; //fŒr inte innehŒlla dessa ord
            badChars[9] = '"';
            cout << "Innan while" << endl;
            while (cin >> word)
            {

                transform(word.begin(), word.end(), word.begin(), ::tolower); //gör alla bokstäver till gemener
                for(int i = 0; i<sizeof(badChars); i++)
                    word.erase (remove(word.begin(), word.end(), badChars[i]), word.end()); //tar bort tecken


                //Kollar om order redan finns
                it = table.find(word);
                if(it != table.end()) //iterator pointing to the slot after the last is returned
                    table[word] = (it->second) + 1; //om ordet redan finns -> +1
                else
                    table[word] = 1;

            }
        //}

        cout <<endl << "innan loopen" << endl;
        vector<typen> sorten(table.size()); //går att sortera
        copy(table.begin(), table.end(), sorten.begin());
        cout << "jekekeke";
        sort(sorten.begin(), sorten.end(), compareTo);
        //skriver ut listan
        //ska vi skriva ut till en fil istället?
        ostringstream os;
        cout << "hej";
        map<string,int>::iterator iter;
        for (iter = table.begin(); iter!= table.end(); iter++){
            //cout << left << setw(30) << iter-> first << iter-> second << endl;
            cout << left << setw(30) << iter-> first << iter-> second << endl;

        }

        cout << "Frequency table sorted by frequence ..." << endl;
        /*vector<typen>::iterator pek;
        for(pek = sorten.begin(); pek != sorten.end(); ++pek)
        {

            //fout << left << setw(30) << pek->second << pek->first << endl;
        }*/
        for_each(sorten.begin(), sorten.end(), display);
        //myfile.close();
    //}
    /*else
    {
        cout << "Unable to open file";
    }*/

    return 0;
}

