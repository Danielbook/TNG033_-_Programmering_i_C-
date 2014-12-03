
#include <iostream>

using namespace std;

//Define function selected_average

bool odd(int n)
{
    if (n%2) return true;

    return false;
}


bool prime(int n)
{
    if (n == 1) return false;

    if ( n == 2 ) return true;

    if ( !(n%2) ) return false;

    for(int i = 3; i < n; i++)
      if (!(n%i)) return false;

    return true;
}


int main()
{

    int V[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //Display the average of all prime numbers in V
    cout << "Average of the prime numbers = " << endl;

    //Display the average of all odd numbers in V
    cout << "Average of the odd numbers = " << endl;

    return 0;
}

