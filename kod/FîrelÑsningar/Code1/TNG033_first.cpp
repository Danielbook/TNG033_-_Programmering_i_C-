/********************************************************************
* TNG033, Fö 1                                                      *
* Display the max and min representable int/double in your machine  *
* *******************************************************************/

#include <iostream> //basic input output
#include <climits>  //INT_MIN and INT_MAX declared in this library
#include <cfloat>   //DBL_MIN and DBL_MAX declared in this library

using namespace std;


int main()
{
    cout << "Smallest representable int: " << INT_MIN << endl
         << "Largest representable int: " << INT_MAX << endl;

    cout << "\nSmallest representable double: " << DBL_MIN << endl
         << "Largest representable double: " << DBL_MAX << endl;

    //Number of bytes occupied by an int or double in memory
    //is not the same for all machines
    cout << "\nAn int occupies "  << sizeof(int) << " bytes"
         << "\nA double occupies " << sizeof(double) << " bytes" << endl;

  return 0;
}
