/*******************************************
* TNG033: Fö 10                            *
* Teacher's member functions definitions   *
* ******************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <new>

#include "teacher.h"

using namespace std;

//constructor
Teacher::Teacher(string s, string *c, int n)
    : n_courses(n), Employee(s) //call constructor of base class
{
    courses = new string[n_courses]; //allocate memory for the course codes

    for(int i = 0; i < n_courses; i++)
        courses[i] = c[i];
}


//copy constructor
Teacher::Teacher(const Teacher &T)
    : Employee(T) //call constructor of base class
{

    //1. Allocate memory for the course codes
    courses = new string[T.n_courses];

    //2. Copy
    n_courses = T.n_courses;

    //copy course codes
    for(int i = 0; i < n_courses; i++)
        courses[i] = T.courses[i];
}

//destructor
Teacher::~Teacher()
{
    delete [] courses;

    //Employee destructor is automatically called last
}

//assignment operator
const Teacher& Teacher::operator=(const Teacher &rhs)
{
    if (this != &rhs) //test self-assignment
    {
        Teacher Acopy(rhs);  //call copy constructor

        //swap the contents of Acopy with *this
        swap(name, Acopy.name);
        swap(n_courses, Acopy.n_courses);
        swap(courses, Acopy.courses);
    }

    //destructor for Acopy is automatically called

    return *this;
}


bool Teacher::gives_course(string code) const
{
    for(int i = 0; i < n_courses; i++)
        if (code == courses[i])
            return true;

    return false;
}


void Teacher::display() const
{
    //Employee::display(); //call display function from class Employee
    cout << "Name: " << name << endl;

    cout << "Courses: ";
    for(int i = 0; i < n_courses-1; i++)
        cout << courses[i] << ", ";

    cout << courses[n_courses-1] << endl;
}
