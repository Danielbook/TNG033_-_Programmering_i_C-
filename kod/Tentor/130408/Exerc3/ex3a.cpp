// =======================================================
// Ex3a
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
const string morseCode[] = {".-",    "-...",  "-.-.", "-..",  ".",    "..-. ",
                     "--.",   "....",  "..",   ".---", "-.-",  ".-..",
                     "--",    "-.",    "---",  ".--.", "--.-", ".-.",
                     "...",   "-",    "..-",  "...-", ".--",  "-..-",
                     "-.--",  "--.." };


bool isNotAlpha(char c)
{
    return !isalpha(c);
}

bool empty_string(string s)
{
    return !s.size();
}

string get_code(char c)
{
    return morseCode[c - 'A'] + " ";
}


string codify(string s)
{
    vector<string> codes;

    string res = "";

    //each slot of the vector contains
    //the morse code of a character of s plus a white space
    transform(s.begin(), s.end(), back_inserter(codes), get_code);

    return accumulate(codes.begin(), codes.end(), res); //concatenate all strings

    //a loop could be used, instead
}



string clean(string s) //same as in Lab 4
{
    //Remove punctuation signs and digits
    s.erase(remove_if(s.begin(), s.end(), isNotAlpha), s.end());

    //Make it uppercase letters
    transform(s.begin(), s.end(), s.begin(), ::toupper);

    return s;
}



/**************************************
* Main function                       *
***************************************/


int main()
{
    ifstream file;
    string name;

    //Open text file
    cout << "File name: ";
    cin >> name;
    cin.ignore();

    file.open(name.c_str());

    if (!file)
    {
        cout << "Could not open file " << name << endl;
        return 0;
    }

     vector<string> words;

    //Load the text file into a vector
    //same as in Lab 4
    istream_iterator<string> in(file);

    istream_iterator<string> in_end;

    copy(in, in_end, back_inserter(words));

    if (!words.size())
    {
         cout << "File is empty!!" << endl;
         return 0;
    }

    cout << "Number of words in the file: "
         << words.size() << endl;

   //Pre-process the words: remove numbers, punctuation signs
   //Put in capital letters -- lab 4
    transform(words.begin(), words.end(), words.begin(), clean);

    //remove empty strings
    //e.g. 35% becomes an empty string
    words.erase(remove_if(words.begin(), words.end(), empty_string), words.end());

    cout << "Number of words in the file: "
         << words.size() << endl;

    // CODIFY IN MORSE CODE

    vector<string> words_morse;

    transform(words.begin(), words.end(), back_inserter(words_morse), codify);

    //Write the codified text into a text file
    //copy vector to a file using iterators: same as in Lab 4
    ofstream out_file("inMorse.txt");

    ostream_iterator<string> out_f(out_file, "\n");

    copy(words_morse.begin(), words_morse.end(), out_f);


    //Close the files
    out_file.close();

    file.close();

    return 0;
}
