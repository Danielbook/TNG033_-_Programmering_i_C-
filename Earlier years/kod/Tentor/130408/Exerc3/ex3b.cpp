// =======================================================
// Ex3b
// Name:
// Personal number:
// =======================================================


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <cstdlib>
#include <utility> //pair
#include <iomanip>
#include <cctype>
#include <sstream>
#include <numeric>

using namespace std;

//A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
const string morseCode[] = {".-",    "-...",  "-.-.", "-..",  ".",    "..-.",
                     "--.",   "....",  "..",   ".---", "-.-",  ".-..",
                     "--",    "-.",    "---",  ".--.", "--.-", ".-.",
                     "...",   "-",    "..-",  "...-", ".--",  "-..-",
                     "-.--",  "--.." };


map<string,char> CODES;


char decodify(string s)
{
    return CODES[s];
}


/**************************************
* Main function                       *
***************************************/


int main()
{
    cout << "DECODIFY" << endl;
    cout << "========================" << endl;

    //Build the map
    for(char c = 'A'; c <= 'Z'; c++)
    {
        CODES[morseCode[c - 'A']] = c;
    }


    string name, line;
    ifstream in_file("inMorse.txt");

    if (!in_file)
    {
        cout << "Could not open file " << name << endl;
        return 0;
    }


    while(getline(in_file, line)) //one word codified per line
    {

        istringstream is(line);

        istream_iterator<string> is_it(is);
        istream_iterator<string> is_end;

        vector<string> line_codes;

        copy(is_it, is_end, back_inserter(line_codes));

        string w = "";

        transform(line_codes.begin(), line_codes.end(), back_inserter(w), decodify);

        cout << w << endl;
    }

    in_file.close();

    return 0;
}
