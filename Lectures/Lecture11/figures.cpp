/***************************************************************************
* TNG033: Fö 11                                                            *
* Defines a hierarchy of geometric figures                                 *
* Class Figure has 3 sub-classes: Rectangle, Circle, and Triangle          *
* virtual functions and dynamic binding is used                            *
* **************************************************************************/

#include <iostream>
#include <string>

using namespace std;

const double PI = 3.14159;


/**************************
* Employee Figure         *
***************************/

class Figure
{
  public:

    //default constructor provided by compiler
    Figure() = default;

    virtual ~Figure() { };

    virtual double area() const
    //double area() const
    {
        cout << "A figure's area: ";
        return 0;
    } ;

};


/**************************
* Square class            *
***************************/


class Rectangle : public Figure
{
  public:

    //constructor
    Rectangle(double l1 = 0.0, double l2 = 0.0)
     : side1(l1), side2(l2) //deafult constructor Figure() is called automatically
     { };

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
    int option;

    cout << "\n*****************" << endl;
    cout << "*1. Rectangle" << endl;
    cout << "*2. Circle" << endl;
    cout << "*3. Triangle" << endl;
    cout << "*4. A figure" << endl;
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

    Figure* DB[MAX];
    int howMany = 0;

    cout << "How many figures? ";
    cin >> howMany;

    if (howMany > MAX)
        return 0; //exit the program

    for(int i = 0; i < howMany; i++)
    {
        int option = get_option();

        switch(option)
        {
            case 1: //create a Rectagle
                    cout << "Enter sides length: ";
                    cin >> side1 >> side2;
                    DB[i] = new Rectangle(side1, side2);
                    break;
            case 2: //create a Circle
                    cout << "Enter circle's radius: ";
                    cin >> r;
                    DB[i] = new Circle(r);
                    break;
            case 3: //Create a Rectangle
                    cout << "Enter triangle's height and base: ";
                    cin >> h >> b;
                    DB[i] = new Triangle(b, h);
                    break;
            case 4: //Create a Figure
                    DB[i] = new Figure; //create a figure
                    break;
            default: return 0; //exit the program
        }
    }

    cout << "\nCalculating the area of the figures ..." << endl;
    for(int i = 0; i < howMany; i++)
    {
        cout << DB[i]->area() //dynamic binding
             << endl;

        delete DB[i];  //deallocate the memory for each figure
    }

   return 0;
}
