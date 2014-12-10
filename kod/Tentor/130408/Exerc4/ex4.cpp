// =======================================================
// Ex4
// Name:
// Personal number:
// =======================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;


/******************************
* Class Employee definition   *
*******************************/


class Employee
{
    public:

        //constructor
        //Add employee to all_employees map
        Employee(string s, int i);

        virtual ~Employee(); //remove employee from all_employees map

        virtual int salary() const = 0;

        int get_id() const { return id; }

        friend ostream& operator<<(ostream &os, const Employee& e);

        static void list_all_employees(); //sorted by id
        static int number_of_employees();
        static Employee* get_employee(int i);

    protected:
        const string name;

        const int id; //unique employee id

        static map<int, Employee*> all_employees;

        virtual void display(ostream &os) const = 0;
};

//Declare the static variable
map<int, Employee*> Employee::all_employees;


Employee::Employee(string s, int i)
    : name(s), id(i)
 {
     all_employees[i] = this; //insert in the map
 }


 Employee::~Employee()
 {
     map<int, Employee*>::iterator it;

     it = all_employees.find(id);

     //remove the employee from the map all_employees
     all_employees.erase(it);
 }

ostream& operator<<(ostream &os, const Employee& e)
{
    os << "Name: " << e.name << endl;
    os << "Id: " << e.id << endl;
    os << "Salary: " << e.salary() << endl; // dynamic binding

    e.display(os); //dynamic binding

    os << endl << endl;

    return os;
}


void Employee::list_all_employees()
{
     //cout << all_employees.size();

     map<int, Employee*>::iterator it = all_employees.begin();

     while (it != all_employees.end())
     {
        cout << *(it->second);
        it++;
     }
}


int Employee::number_of_employees()
{
    return all_employees.size();
}

Employee* Employee::get_employee(int i)
{
    if (all_employees.find(i) != all_employees.end())
        return all_employees[i];

    return NULL;

}


/*****************************
* Class Manager definition   *
*****************************/


class Manager : public Employee
{
    public:

        Manager(string s, int i, int bs, int b);

        void manage(const Employee *e);   // a new person for the group
        void unmanage(const Employee *e); // a person leaving the group

        int salary() const;

        int group_size() const;


    protected:
        int base_salary;
        int bonus;

        vector<const Employee*> group;

        void display(ostream &os) const;

};

//Constructor
Manager::Manager(string s, int i, int bs, int b)
 : Employee(s, i), base_salary(bs), bonus(b) { }


void Manager::manage(const Employee *e)
{
    group.push_back(e);
}


void Manager::unmanage(const Employee *e)
{
    vector<const Employee*>::iterator it;

    it = find(group.begin(), group.end(), e);

    group.erase(it);
}

int Manager::salary() const
{
    return base_salary + base_salary*bonus/100;
}

int Manager::group_size() const
{
    return group.size();
}

void Manager::display(ostream &os) const
{
    os << "Position: manager" << endl;
    os << "Group managed: ";

    for(int i = 0; i < group.size(); i++)
        os << group[i]->get_id() << " ";
}


/********************************
* Class Programmer definition   *
*********************************/

class Programmer : public Employee
{
    public:
        Programmer(string s, int i, int h, int p, string l);

        int salary() const;


    protected:
        int hours;
        int hour_price;

        string prog_lang;

        void display(ostream &os) const;
};

//Constructor
Programmer::Programmer(string s, int i, int h, int p, string l)
  : Employee(s, i), hours(h), hour_price(p),  prog_lang(l) { }


int Programmer::salary() const
{
    return hours*hour_price;
}


void Programmer::display(ostream &os) const
{
    os << "Position: programmer" << endl;
    os << "Programming language: " << prog_lang;
}



/**************************************
* Main function: cannot be modified   *
* except where explicitly indicated   *
***************************************/


void add_to_group(Manager &e) //do not modify this function
{
    Programmer *e2 = new Programmer("P2", 2, 60, 700, "Java");
    Programmer *e3 = new Programmer("P3", 3, 50, 700, "C++");

    //Add two programmers to the group of manager e
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

    cout << "Number of employees: "
         << Employee::number_of_employees() << endl << endl;

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

    cout << "Number of employees: "
         << Employee::number_of_employees() << endl << endl;

    //Display the list of all employees
    Employee::list_all_employees();

    /***************************'*********/
    cout << "***PHASE 1" << endl << endl;
    /***************************'*********/

    cout << "Employee 5 quits ..." << endl << endl;

     //remove employee e5 from the group of e1
    e1.unmanage(e5);
    //remove employee e5 from the group of e6
    e6->unmanage(e5);

    delete e5;

   cout << "Number of employees: "
         << Employee::number_of_employees() << endl << endl;

    cout << e1 << *e6;

    //Employee::list_all_employees();

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

    cout << "Number of employees: "
         << Employee::number_of_employees() << endl << endl;

    //Display the list of all employees
    //Employee::list_all_employees();

    cout << e1 << endl;

    /***************************'*********/
    cout << "***PHASE 3" << endl << endl;
    /***************************'*********/

    int id;
    const Employee *e;

    cout << "Enter an employee id: ";
    cin >> id;

    //Display the salary of employee with given id
    //If employee id not found then display an error message
    if ( (e = Employee::get_employee(id)) )
    {
        cout << "Salary = " << e->salary() << endl;
    }

    else
        cout << "Employee not found!!" << endl;

    return 0;
}
