/**************************************************************
* TNG033, Fö 1                                                *
* 1. Sum the values in a user given sequence                  *
* End of input indicated by a non-numeric valued, e.g. 'STOP' *
* 2. Read an integer k                                     *
* 3. Display the sum multiplied by k                          *
* *************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

void clean_up_stream(istream &in)
{
    in.clear(); //Reset the stream error flags, i.e. put stream in back to good state

    //Extract the non-valid input from the stream’s buffer
    string trash;
    getline(in,trash);
}


int main()
{
    double x;
    double sum = 0;

    cout << "Enter the sequence: ";

    //Read the sequence
    while ( cin >> x ) //read+test
    {
        sum += x;
    }

    cout << "Sum = "  << fixed << setprecision(2) << sum << endl;

    //Clean up stream cin
    clean_up_stream(cin);

    int k  = 0;
    cout << "\nEnter k: ";
    cin >> k;

    //Display the result
    cout << "Result = " << k * sum << endl;

    return 0;
}
