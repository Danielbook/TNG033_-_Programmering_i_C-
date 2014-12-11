/***************************************************************
* TNG033, Fö 1                                                 *
* 1. Sum the values in a user given sequence                   *
* End of input indicated by a non-numeric valued               *
*                                                              *
* Test the progra with input redirection: sum2 < input_sum.txt *
* *************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
    double x;
    double sum = 0;

    //Read the sequence
    while ( cin >> x ) //read+test
    {
        sum += x;
    }

    cout << "Sum = "  << fixed << setprecision(2) << sum << endl;

    return 0;
}
