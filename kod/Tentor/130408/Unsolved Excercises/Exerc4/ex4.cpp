// =======================================================
// Ex4
// Name:
// Personal number:
// =======================================================


#include <iostream>

using namespace std;


/******************************
* Class Employee definition   *
*******************************/



/*****************************
* Class Manager definition   *
*****************************/



/********************************
* Class Programmer definition   *
*********************************/



/****************************************************
* Main function: cannot be modified                 *
* except where explicitly indicated with "ADD CODE" *
****************************************************/


void add_to_group(Manager &e) //DO NOT MODIFY this function
{
    Programmer *e2 = new Programmer("P2", 2, 60, 700, "Java");
    Programmer *e3 = new Programmer("P3", 3, 50, 700, "C++");

    e.manage(e2);
    e.manage(e3);
}


int main()
{
    /***************************'*********/
    cout << "***PHASE 0" << endl << endl;
    /***************************'*********/

    cout << "Adding some employees ..." << endl;

    //Create manager M1, id = 1,
    //base salary = 50.000, bonus = 10%
    Manager e1("M1", 1, 50000, 10);

    //Add some employees to the group of e1
    add_to_group(e1);

    cout << "Number of employees: ";
    //ADD CODE to display number of employees

    cout << "Adding some more employees ..." << endl << endl;

    //Create manager M6, id = 6,
    //base salary = 50.000, bonus = 10%
    Manager *e6 = new Manager("M6", 6, 50000, 10);

    //Create programmer P5, id = 5,
    //working hours = 200, price per hour = 750
    Programmer *e5 = new Programmer ("P5", 5, 200, 750, "Javascript");

    //Create programmer P4, id = 4,
    //working hours = 60, price per hour = 700
    Programmer *e4 = new Programmer("P4", 4, 60, 700, "C++");

    //Add some employees to the group of e6
    e6->manage(e5);
    e6->manage(e4);

    //Add some employees to the group of e1
    e1.manage(e4);
    e1.manage(e5);
    e1.manage(e6);

    cout << "Number of employees: ";
    //ADD CODE to display number of employees

    //ADD CODE to display the list of all employees, sorted by id

    /***************************'*********/
    cout << "***PHASE 1" << endl << endl;
    /***************************'*********/

    cout << "Employee 5 quits ..." << endl << endl;

    //remove employee e5 from the group of e1
    e1.unmanage(e5);
    //remove employee e5 from the group of e6
    e6->unmanage(e5);

    delete e5;

    cout << "Number of employees: ";
    //ADD CODE to display number of employees

    cout << e1 << *e6;

    cout << "Manager with id " << e6->get_id()
         << " has a group of " << e6->group_size() << " person(s)."
         << endl << endl;

    /***************************'*********/
    cout << "***PHASE 2" << endl << endl;
    /***************************'*********/

    cout << "Manager 6 quits ..." << endl << endl;

     //remove employee e6 from the group of e1
    e1.unmanage(e6);
    delete e6;

    cout << "Number of employees: ";
    //ADD CODE to display number of employees


    cout << e1 << endl;

    /***************************'*********/
    cout << "***PHASE 3" << endl << endl;
    /***************************'*********/

    int id;

    cout << "Enter an employee id: ";
    cin >> id;

    //ADD CODE to
    //Display the salary of employee with given id
    //If employee id not found then display an error message

    return 0;
}
