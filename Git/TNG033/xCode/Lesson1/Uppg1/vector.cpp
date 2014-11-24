#include <iostream>
#include <new>
#include <fstream>
#include <istream>
#include <sstream>
#include <math.h>
#include "vector.h"

using namespace std;

void createVector(Vector& V, int n)
{
    V.size = n;
    V.coord = new (nothrow) double [n]; //allocate explicitly memory

    if (!V.coord) //not possible to allocate memory!!
    {
        V.n_coord = 0;
    }
    else
    {
        V.n_coord = n;
        
        for (int i = 0; i < n; i++) {
            V.coord[i] = 0.0;
        }
        
        cout << "Vector created\n";

    }
    
    
}

double length(const Vector& V)
{
    double sum = 0;

//    for(int i = 0; i < V.size; i++)
//    {
//        sum += pow(get(V, i), 2);
//    }
//
    
    const double *v_end = V.coord + V.n_coord;
    
    for(const double* p = V.coord; p != v_end; p++)
    {
        sum += pow(*p, 2);
    }
    
    return sqrt( sum );
}

double get(const Vector& V, int i)
{
    return V.coord[i];
}

void set(Vector& V, int i, double v)
{
    V.coord[i] = v;
}


void empty_vector(Vector& V)
{
    delete [] V.coord; //deallocate memory

    V.coord = nullptr;
    
    V.n_coord = 0;
}

istream& operator>>(istream& is, const Vector& V)
{
//
//    while (in >> coord)
//    {
//        V.coord[i++] = coord;
//        
//        if (i == V.n_coord)
//        {
//            return is;
//        }
//    }
    
    string line;
    double d;
    int i = 0;
    
    is >> ws;
    
    getline(is, line);
    
    istringstream in(line);
    
    while ( in >> d )
    {
        {
            V.coord[i++] = d;
    
            if (i == V.n_coord)
            {
                return is;
            }
        }
    }
    
    return is;
}

ostream& operator<<(ostream& os, const Vector& V)
{
    os << "<" << fixed << setprecision(2);

    for(int i = 0; i < V.n_coord-1; i++)
    {
        os << V.coord[i] << ", ";
    }
    
    os << V.coord[V.n_coord[-1]] << ">";
    
    return os;
}
