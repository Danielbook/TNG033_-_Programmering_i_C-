/**********************************************
* TNG033: Fö 10                               *
* Programmer's member functions definitions   *
* *********************************************/

#include "programmer.h"

using namespace std;

//constructor  -- DO LIVE
Programmer::Programmer(string s, string *c, int n, string f)
    : Teacher(s, c, n) //call constructor of Teacher class
{
    fav_lang = f;
}


//Provide by the compiler
//Thus, no need to program copy constructor for class Programmer
Programmer::Programmer(const Programmer &p)
    : Teacher(p)
{
    fav_lang = p.fav_lang;
}


//Provide by the compiler
//Thus, no need to program operator= for Programmer
const Programmer& Programmer::operator=(const Programmer &p)
{
    Teacher::operator=(p); //call operator= of base class Teacher

    fav_lang = p.fav_lang;
}


void Programmer::display() const
{
    Teacher::display(); //call display function from class Teacher

    cout << "Favourite prog. language: " << fav_lang << endl;
}
