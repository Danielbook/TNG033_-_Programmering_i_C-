/********************************************************************
* TNG033, Fö 1                                                      *
* 1. Read a user sequence into an array                             *
* 2. Display the sum of the values in the sequence                  *
* 3. Display the largest and the smallest value in thesequence      *
* End of input indicated by a non-numeric valued, e.g. 'STOP'       *
* *******************************************************************/


#include <iostream>
#include <iomanip>

using namespace std;

/*********************************
* Functions declaration          *
**********************************/

//V is an array with n occupied slots
void display(const double V[], int n);


//Return the largest value stored in V through reference argument max
//Return the smallest value stored in V through reference argument min
//V is an array with n occupied slots
void max_min(const double V[], int n, double &max, double &min);


//Read a sequence of values and store them in array V
//V has n slots, i.e. at msot n values can be syored in the array
//Return how many values were read and stored in V
int read_seq(double V[], int n);


/**************************
* Main function           *
***************************/

int main()
{//V is an array with n occupied slots
//Return the largest value stored in V through max
//Return the smallest value stored in V through min
    const int SIZE = 100;

    double seq[SIZE] = {0};
    int howMany = 0;

    double x;

    cout << "Enter a sequence: ";

    howMany = read_seq(seq, SIZE);

    if (!howMany)
    {
        cout << "No sequence given!!" << endl;
        return 0;
    }

    cout << "\nYour sequence: ";
    display(seq, howMany);

    //sum the values in the array
    double sum = 0;

    for(int i = 0; i < howMany; i++)
        sum += seq[i];

    cout << "Sum = "  << fixed << setprecision(2) << sum << endl;

    double largest, smallest;

    max_min(seq, howMany, largest, smallest);

    cout << "Max = " << largest
         << "  Min = " << smallest << endl;

    return 0;
}

/*********************************
* Functions definition           *
**********************************/

//Read a sequence of values and store them in array V
//V has n slots, i.e. at most n values can be read and stored in array V
//Return how many values were read and stored in V
int read_seq(double V[], int n)
{
    int count = 0;

    //Read a user given sequence into an array
    while ( (count < n) && (cin >> V[count]) )  //Do NOT SWAP THE CONDITIONS
    {
        //inc. the number of values stored in the array
        count++;
    }

    return count;
}


//V is an array with n occupied slots
void display(const double V[], int n)
{
    for(int i = 0; i < n; i++)
        cout << V[i] << " ";

    cout << endl;

    //V[0] = 10; //compilation error because V is a const array
}


//Return the largest value stored in V through reference argument max
//Return the smallest value stored in V through reference argument min
//V is an array with n occupied slots
void max_min(const double V[], int n, double &max, double &min)
{
    max = min = V[0];

    for(int i = 1; i < n; i++)
    {
        if (V[i] > max) //new max?
            max = V[i];
        else if (V[i] < min)
            min = V[i];
    }
}

