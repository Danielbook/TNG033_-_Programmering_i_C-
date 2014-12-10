/********************************************************************
* TNG033, Fö 1                                                      *
* Program to illustrate a 2-dimentional array (table)               *
********************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

//Calculate the sum of values in array V
//V stores n values
int sum(const int V[], int n)
{
    int sum = 0;

    for(int i = 0; i < n; i++)
        sum += V[i];

    return sum;
}

int main()
{
    const int N_COL = 3;
    const int N_LINE = 3;

    int table[N_COL][N_LINE];

    //initialize the table
    for(int line = 0; line < N_LINE; line++)
        for(int col = 0; col < N_COL; col++)
        {
            cout << "V[" << line << "]["
                 << col << "]= ";
            cin >> table[line][col];
        }

    //table[0] is an array with four ints
    cout << "Sum of line 1 = " << sum(table[0], N_COL) << endl;
    cout << "Sum of line 2 = " << sum(table[1], N_COL) << endl;
    cout << "Sum of line 3 = " << sum(table[2], N_COL) << endl;

    return 0;
}
