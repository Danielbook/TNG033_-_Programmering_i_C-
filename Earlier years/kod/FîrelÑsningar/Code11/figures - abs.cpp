/***************************************************************************
* TNG033, Fö 11                                                            *
* Defines a hierarchy of geometric figures                                 *
* Class Figure has 3 sub-classes: Rectangle, Circle, and Triangle          *
* Class Figure is abstract: area() is pure virtual function                *
* **************************************************************************/

#include <iostream>
#include <string>

using namespace std;

const double PI = 3.14159;


/**************************
* Employee Figure         *
***************************/

class Figure //abstract class
{
  public:

    //default constructor provided by compiler
    //Figure() {};

    virtual double area() const = 0; //pure virtual function
};


/**************************
* Square class            *
***************************/


class Rectangle : public Figure
{
  public:

    //constructor
    Rectangle(double l1 = 0.0, double l2 = 0.0)
     : side1(l1), side2(l2) { };

    double area() const
    {
        cout << "Rectangle's area: ";
        return side1 * side2;
    };

	protected:
        double side1, side2;
};


/**************************
* Circle class            *
***************************/


class Circle : public Figure
{
  public:

    //constructor
    Circle(double r = 0.0)
     : radius(r) { };

    double area() const
    {
        cout << "Circle's area: ";
        return PI * radius * radius;
    } ;

    double get_radius()
    {
        return radius;
    }

	protected:
        double radius;
};


/**************************
* Triangle class          *
***************************/


class Triangle : public Figure
{
  public:

    //constructor
    Triangle(double b = 0.0, double h = 0.0)
     : base(b), height(h) { };

    double area() const
    {
        cout << "Triangle's area: ";
        return (base * height) / 2;
    } ;

	protected:
        double base,  height;
};


/**********************************
* main()  -- testing              *
***********************************/

int get_option()
{
    //Assumes user always enter an option 1-4
    int option;

    cout << "\n*****************" << endl;
    cout << "*1. Rectangle" << endl;
    cout << "*2. Circle" << endl;
    cout << "*3. Triangle" << endl;
    cout << "*****************" << endl;

    cout << "Option? ";
    cin >> option;

    return option;
}



int main()
{
    const int MAX = 20;

    double side1, side2;
    double h, b, r;

    //Figure E; //compilation error because Figure is an abstract class

    Figure* DB[MAX];
    int howMany = 0;

    cout << "How many figures? ";
    cin >> howMany;

    if (howMany > MAX)
        return 0; //exit th eprogram

    for(int i = 0; i < howMany; i++)
    {
        int option = get_option();

        switch(option)
        {
            case 1: cout << "Enter sides length: ";
                    cin >> side1 >> side2;
                    DB[i] = new Rectangle(side1, side2);
                    break;
            case 2: cout << "Enter circle's radius: ";
                    cin >> r;
                    DB[i] = new Circle(r);
                    break;
            case 3: cout << "Enter triangle's height and base: ";
                    cin >> h >> b;
                    DB[i] = new Triangle(b, h);
                    break;
            default: return 0; //exit the program
        }
    }

    cout << "\nCalculating the area of the figures ..." << endl;
    for(int i = 0; i < howMany; i++)
    {
        cout << DB[i]->area() //dynamic binding
             << endl;
    }

   return 0;
}
