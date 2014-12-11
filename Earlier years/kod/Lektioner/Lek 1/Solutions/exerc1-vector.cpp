/******************************************************************
* TNG033, Lesson 1                                                *
* *****************************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

const int SIZE = 100;

struct Vector
{
    double coord[SIZE];
    int n_coord;
};


istream& operator>>(istream& is, Vector &v)
{
    int count = 0;
    v.n_coord = 0;

    string line;

    is >> ws; //skip any empty lines

    if (getline(is, line))
    {
        istringstream in(line);

        while (count < SIZE && in >> v.coord[count])
            count++;

         v.n_coord = count;
    }

    return is;
}


ostream& operator<<(ostream& os, const Vector &v)
{
    os << "<"
       << fixed << setprecision(2);

    for(int i = 0; i < v.n_coord-1; i++)
        os << v.coord[i] << ", ";

    os << v.coord[v.n_coord-1] << ">";

    return os;
}


double length(const Vector &v)
{
    double sum = 0;
    const double* v_end = v.coord + v.n_coord;

//     for(int i = 0; i < v.n_coord; i++)
//        sum += pow(v.coord[i],2);

    for(const double* p = v.coord; p != v_end; p++)
        sum += pow(*p,2);

     return sqrt(sum);
}

bool operator<(const Vector &v1, const Vector &v2)
{
    return (length(v1) < length(v2));
}

void bubbelsort(Vector *V, int n)
{
   Vector temp;

    //sort
    for ( int pass = 0; pass <= n - 2; pass++ ) // passes

        for (int i = 0; i <  n - 1; i++ )      // one pass
        {

            if ( *(V+i+1) < *(V+i) ) //overloaded operator< called
            {
                //swap
                temp = *(V+i);
                *(V+i) = *(V+i+1);
                *(V+i+1) = temp;
            }
        }
}



int main()
{
    Vector A[SIZE];
    int howMany = 0;

    ifstream file("vectors.txt");

    if (!file)
    {
        cout << "Could not open the text file!!" << endl;
        return 0;
    }

    //Read the vectors from text file and store them in array A
    while (howMany < SIZE && file >> A[howMany])
            howMany++;

    if (!howMany)
    {
        cout << "Text file is empty!!" << endl;
        return 0;
    }

    cout << fixed << setprecision(2);

    //Sort by vector length
    bubbelsort(A, howMany);

    //Display the sorted array
    for(int i = 0; i < howMany; i++)
    {
        cout << "length("
             <<  *(A+i) //array with pointer notation
             << ") = " << length(*(A+i)) << endl;
    }

    return 0;
}
