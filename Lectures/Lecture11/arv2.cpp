/***************************************************************************
* TNG033: F� 11                                                            *
* Defines a hierarchy of Employees (see also F�10)                         *
* function display() is now virtual --> dynamic binding is used            *
* Employee destructor must also be virtual                                 *
* **************************************************************************/

//Note: In this code, the author assumes that it's allways possible to allocate memory
//I know god is going to kill another kitten ...


#include <iostream>
#include <iomanip>
#include <string>
#include <new>

using namespace std;



/**************************
* Employee class          *
***************************/

class Employee
{
public:

    //constructor
    Employee(string s = "") : name(s) {   };

    //Destructor
    virtual ~Employee() { };

    void change_name(const string s)
    {
        name = s;
    };

    virtual void display() const
    //void display() const  //F� 10, function display() is not virtual
    {
        cout << "Name: " << name << endl;
    } ;

protected:
    string name;
};



/**************************
* Teacher class           *
***************************/


class Teacher : public Employee
{
public:

    //constructor
    Teacher(string s = "", string *c = nullptr, int n = 0);

    //copy constructor
    Teacher(const Teacher &T);

    ~Teacher(); //destructor

    //assignment operator
    const Teacher& operator=(const Teacher &T);

    bool gives_course(string code) const;

    void display() const;

protected:
    string *courses;  //array of courses codes given by the teacher
    int n_courses;    //number of courses given by the teacher
};


/////////////////////////////////////////
//Teacher's member functions definitions
/////////////////////////////////////////


//constructor
Teacher::Teacher(string s, string *c, int n)
    : n_courses(n), Employee(s) //call constructor of base class to initialize name
{
    courses = new string[n_courses]; //allocate memory for the course codes

    for(int i = 0; i < n_courses; i++) //copy course codes from array c
        courses[i] = c[i];
};


//copy constructor
Teacher::Teacher(const Teacher &T)
    : n_courses(T.n_courses), Employee(T) //call base class copy constructor
{
    courses = new string[n_courses]; //allocate memory for the course codes

    for(int i = 0; i < n_courses; i++)
        courses[i] = T.courses[i];  //copy course codes from array c
};

Teacher::~Teacher() //destructor
{
    //cout << "Destructor teacher: " << name << endl;
    delete [] courses;

    courses = nullptr;
}


const Teacher& Teacher::operator=(const Teacher &rhs)
{
    if (this != &rhs) //test self-assignment
    {
        Teacher Acopy(rhs);

        swap(courses, Acopy.courses); //swap the courses pointer
        swap(n_courses, Acopy.n_courses);
    }

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
    cout << "Teacher: " << name << endl;

    cout << "Courses: ";
    for(int i = 0; i < n_courses-1; i++)
        cout << courses[i] << ", ";

    cout << courses[n_courses-1] << endl;
}



/**************************
* Programmer class        *
***************************/

class Programmer : public Teacher
{
public:

    //constructor
    Programmer(string s = "", string *c = NULL, int n = 0, string f = "C++")
        : fav_lang(f), Teacher(s, c, n) //call constructor of Teacher class
    {

    };


    void display() const;

protected:
    string fav_lang;  //favourite programming language
};



void Programmer::display() const
{
    cout << "Programmer: " << name << endl;
    cout << "Favourite prog. language: " << fav_lang << endl;

    cout << "Courses: ";
    for(int i = 0; i < n_courses-1; i++)
        cout << courses[i] << ", ";

    cout << courses[n_courses-1] << endl;
};



/**************************
* Researcher class        *
***************************/

class Researcher : public Employee
{
public:

    //constructor
    Researcher(string s = "", string a = "")
        : area(a), Employee(s) //call constructor of base class
    {

    };


    void display() const
    {
        cout << "Researcher: " << name << endl;
        cout << "Area of research: " << area << endl;
    } ;

protected:
    string area;  //area of research
};



/*************************************************
* main()  -- testing                             *
**************************************************/


int main()
{
    const int MAX = 100;

    string C1[] = {"TND012", "TNG033", "TNK031"};
    string C2[] = {"TNCG018", "TND004"};

    Teacher T("Anna", C2, 2);
    Researcher R("Monika", "Swearing theory");

    Employee* DB[MAX];
    int howMany = 3;

    DB[0] = &T;
    DB[1] = new  Programmer("Aida", C1, 3, "Smalltalk");;
    DB[2] = &R;

    for(int i = 0; i < howMany; i++)
    {
        DB[i]->display(); //dynamic binding
        cout << endl;
    }

    delete DB[1];  //dynamic binding is used to call the destructor ~Programmer()

    //Destructor for objects T and R are called automatically

    return 0;
}


