#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;


//Add n years to the date d1
//d1 is a date of the format yyyy-mm-dd, e.g. 2012-03-15
string add_datum(string d1, int n)
{
    istringstream is(d1);

    int year;
    is >> year; // read year into i

    string s;
    getline(is, s); //read "-mm-dd" from is into s

    ostringstream os;
    os << year+n << s;

    return (os.str());

}


int main()
{
  string date;

  int n = 0;

  cout << "Enter n: ";
  cin >> n;

  cout << "Enter dates: ";

  while (cin >> date)  //ctrl-Z (eof) ends the input
  {
      cout << add_datum(date, n) << endl;
  }

  return 0;
}
