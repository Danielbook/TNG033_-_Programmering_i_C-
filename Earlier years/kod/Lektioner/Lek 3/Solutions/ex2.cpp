/***************************************************************
* TNG033, lesson 3                                             *
* Exerc 2: STL                                                 *
* **************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>
#include <cstdlib> //abs
#include <cmath> //sqrt

using namespace std;


struct Rectangle //A class could be defined instead
{
    int x1, y1; //Point P1
    int x2, y2; //Point P2
};


int area(const Rectangle &r)
{
    return abs(r.x2-r.x1) * abs(r.y2-r.y1);
}


istream& operator>>(istream &is, Rectangle &r)
{
    is >> r.x1 >> r.y1 >> r.x2 >> r.y2;

    return is;
}

ostream& operator<<(ostream &os, const Rectangle &r)
{
    os << "P1 = (" << r.x1 << ", " << r.y1 << ")  "
       << "P2 = (" << r.x2 << ", " << r.y2 << ")  "
       << "area = " << area(r);

    return os;
}


bool compare1(Rectangle r1, Rectangle r2)
{
    return area(r1) > area(r2);
}

bool compare2(Rectangle r1, Rectangle r2)
{
    return sqrt(r1.x1*r1.x1 + r1.y1*r1.y2) <
           sqrt(r2.x1*r2.x1 + r2.y1*r2.y2);
}

bool notSquare(Rectangle r)
{
    return (abs(r.x2-r.x1) != abs(r.y2-r.y1));
}

bool isSquare(Rectangle r)
{
    return (abs(r.x2-r.x1) == abs(r.y2-r.y1));
}




/**************************************
* Main function                       *
***************************************/


int main()
{
    ifstream file;
    string name;

    //Open text file
    cout << "File name: ";
    getline(cin, name);

    file.open(name.c_str());

    if (!file)
    {
        cout << "Could not open file " << name << endl;
        return 0;
    }

    vector<Rectangle> V;

    //1. Read the file and load all rectangles into vector V
    istream_iterator<Rectangle> in(file);

    istream_iterator<Rectangle> in_end;

    copy(in, in_end, back_inserter(V)); //operator>> for Rectangle is called

    cout << "Number of rectangles: "
         << V.size() << endl;

    //2. Sort vector V by rectangles area
    sort(V.begin(), V.end(), compare1);

    //3. Display the rectangles in vector V to cout
    ostream_iterator<Rectangle> out(cout, "\n");

    copy(V.begin(), V.end(), out); //operator<< for Rectangle is called

    //Part b -- version 1


    //4. Remove all non-squares from vector V
    vector<Rectangle>::iterator it = remove_if(V.begin(), V.end(), notSquare);
    V.erase(it, V.end());


    //5. Sort vector V by squares distance to point (0,0)
    sort(V.begin(), V.end(), compare2);

    //6. Display the squares in vector V to cout
    cout << "\nNumber of squares: "
         << V.size() << endl << endl;

    copy(V.begin(), V.end(), out);


/*

    //Part b -- version 2


    //4. Create another vector with all squares stored in V

    vector<Rectangle> theSquares;

    copy_if(V.begin(), V.end(), back_inserter(theSquares), isSquare);

    //5. Sort vector theSquares by squares distance to point (0,0)
    sort(theSquares.begin(), theSquares.end(), compare2);

    //3. Display the squares in vector theSquares to cout
    cout << "\nNumber of squares: "
         << theSquares.size() << endl << endl;

    copy(theSquares.begin(), theSquares.end(), out);

*/


    file.close();

    return 0;
}
