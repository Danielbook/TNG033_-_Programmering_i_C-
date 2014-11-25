/***************************************************************************
* TNG033: Fö 10                                                            *
* Test program for hierarchy of Employees                                  *
* **************************************************************************/

#include <iostream>

#include "employee.h"
#include "teacher.h"
#include "programmer.h"
#include "researcher.h"

using namespace std;


/********************************************
* main()  -- testing                        *
*********************************************/

int main()
{
    const int MAX = 100;

    string C1[] = {"TND012", "TNG033", "TNK031"};
    string C2[] = {"TNCG018", "TND004"};

    Teacher T("Anna", C2, 2);
    Programmer P1("Aida", C1, 3, "Smalltalk");
    Researcher R("Monika", "Swearing theory");

    //Teacher T1(T);
    Teacher T1;
    T1 = T;

    T1.display();
    cout << endl;

    T.display();
    cout << endl;
    T.set_name("Olivia Bla"); //inherited member function
    T.display();
    cout << endl;

    P1.display();
    cout << endl;

    R.display();
    cout << endl;

    Programmer P2 = P1; //copy constructor of class Programmer is called
    //Programmer P2(P1); // same as statement above

    P2.display();
    cout << endl;

    P2 = P2; //test self-assignment

    P2.display();
    cout << endl;

   return 0;
}


