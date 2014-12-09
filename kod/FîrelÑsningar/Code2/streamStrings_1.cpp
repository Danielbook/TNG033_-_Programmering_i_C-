/**********************************************************************************
* TNG033, Fö 2                                                                    *
* Example of using input stringstreams                                            *
* Check whether input lines have the format                                       *
* "int  char int" (e.g. 8 + 7)                                                    *
* List all line numbers, for lines with wrong format                              *
* If a line has correct format then perfor the operation and display the result   *
* To Test: re-direct standard input to exp.txt                                    *
* *********************************************************************************/


#include <iostream>
#include <sstream>
#include <string>

using namespace std;


//Test if s has the format "int char int"
bool test_line(string s, int &left, char &op, int &right)
{
    istringstream instream(s);

    //instream.str(s);

    if (instream >> left >> op >> right) //read + test
    {
        if ( (op != '+') && (op != '-') && (op != '*') && (op != '/') )
            return false;

        instream >> ws;    //Skip white spaces, if any

        if (instream.eof())  //is the stream's buffer empty?
            return true;
        else
            return false;
    }
    else
        return false;
}


double perform_operation(int a, int b, int c)
{
    switch(c)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (double)a / b;
    }
}


int main()
{
    string line;
    int line_counter = 0;

    int left, right;
    char op;

    while (getline(cin, line))   // Reads a line
    {
        if (line == "STOP") break; //exit the loop if the user enters "STOP"

        line_counter++;

        if ( !test_line(line, left, op, right) )
            cout << "Line " << line_counter
                 << " not ok!!" << endl;
         else
            cout << left << op << right << "= "
                 << perform_operation(left, right, op) << endl;
    }

    return 0;
}
