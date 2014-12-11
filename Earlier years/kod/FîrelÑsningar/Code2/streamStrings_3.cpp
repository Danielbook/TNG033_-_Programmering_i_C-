/**********************************************************************************
* TNG033, F� 2                                                                    *
* Example of using output stringstreams                                           *
* Program to illustrate an easy way                                               *
* att utf�ra typomvandling till och fr�n texter                                   *
* *********************************************************************************/


#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;


string convert(double d)
{
    ostringstream os;

    os << scientific << d;

    return (os.str());
}


int main()
{
  double d;

  cout << "Enter a number: ";
  cin >> d;

  cout << convert(d) << endl;

  return 0;
}
