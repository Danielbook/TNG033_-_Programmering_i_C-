/***************************************************************************
* TNG033, Fö 10                                                            *
* Defines a hierarchy of Employees: see slide 2                            *
* All classes in one source file                                           *
* **************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <new>

using namespace std;


/*************************
* Employee class         *
**************************/

class Employee
{
  public:

    //constructor
    Employee(string s = "") : name(s) {  };

    //~Employee() { };  //not needed

    void set_name(const string s) { name = s; };

    void display() const
    {
        cout << "Name: " << name << endl;
    } ;

	protected:  //data members are accessible to the memeber functions of derived classes
        string name;
};


/**************************
* Teacher class           *
***************************/


class Teacher : public Employee
{
  public:

    //constructor
    //s is teacher's name
    //c is a "list" (an array) of courses offered by the teacher
    //n is the number of courses offered
    Teacher(string s = "", string *c = nullptr, int n = 0);

    //copy constructor
    Teacher(const Teacher &T);

    //destructor
    ~Teacher()
    {
        delete [] courses;

        //Employee destructor is automatically called last
    }

    //assignment operator
    const Teacher& operator=(const Teacher &T);

    bool gives_course(string code) const;

    void display() const;

    protected:
        string *courses;  //array of course codes given by the teacher
        int n_courses;    //number of courses given by the teacher
};


/////////////////////////////////////////
//Teacher's member functions definitions
/////////////////////////////////////////

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

//assignment operator
const Teacher& Teacher::operator=(const Teacher &T)
{
    if (this != &T) //test self-assignment
    {
         name = T.name;

        //1. Delete old memory
        delete [] courses;

        //2. Allocate new memory
        courses = new string[T.n_courses];

        //3. Copy
        n_courses = T.n_courses;
        for(int i = 0; i < n_courses; i++)
            courses[i] = T.courses[i];
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
    //Employee::display(); //call display function from class Employee
    cout << "Name: " << name << endl;

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
    Programmer(string s = "", string *c = nullptr, int n = 0, string f = "C++")
     : Teacher(s, c, n) //call constructor of Teacher class
    {
        fav_lang = f;
    };


    //Provide by the compiler
    //Thus, no need to program copy constructor for class Programmer
    Programmer(const Programmer &p)
     : Teacher(p)
    {
        fav_lang = p.fav_lang;
    }


    //Provide by the compiler
    //Thus, no need to program operator= for Programmer
   const Programmer& operator=(const Programmer &p)
   {
       Teacher::operator=(p); //call operator= of base class Teacher

       fav_lang = p.fav_lang;
   }


    void display() const
    {
        Teacher::display(); //call display function from class Teacher

        cout << "Favourite prog. language: " << fav_lang << endl;
    } ;

	protected:
        string fav_lang;  //favourite programming language
};



/**************************
* Researcher class        *
***************************/


class Researcher : public Employee
{
  public:

    //constructor
    Researcher(string s = "", string a = "")
     : Employee(s) //call constructor of base class
    {
        area = a;
    };


    void display() const
    {
        Employee::display(); //call display function from class Employee

        cout << "Area of research: " << area << endl;
    } ;

	protected:
        string area;  //area of research
};



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

    Employee E;
    E = T;  //slicing
    E.display();
    cout << endl;

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
    //Programmer P2(P1); // same as Programmer P2 = P1;

    P2.display();
    cout << endl;

    P2 = P2; //test self-assignment

    P2.display();
    cout << endl;

   return 0;
}


