#include <iostream>
#include <new>
#include <math.h>
#include "vector.h"

using namespace std;

void createVector(Vector& V, int l)
{
    V.size = l;
    V.p_table = new (nothrow) double [l]; //allocate explicitly memory

    if (!V.p_table) //not possible to allocate memory!!
    {
        V.size = 0;
    }
    
    cout << "Vector created\n";

}

double length(const Vector& V)
{
    double sum = 0;

    for(int i = 0; i < V.size; i++)
    {
        sum += pow(get(V, i), 2);
    }
    
    return sqrt( sum );
}

double get(const Vector& V, int i)
{
    return V.p_table[i];
}

void set(Vector& V, int i, double v)
{
    V.p_table[i] = v;
}


void empty_vector(Vector& V)
{
    V.size = 0;

    delete [] V.p_table; //deallocate memory

    V.p_table = nullptr;
}

istream& operator>>(istream& in, Vector& V)
{
    double val;
    
    for(int i = 0; i < V.size; i++)
    {
        in >> val;
        set(V, i, val);
    }
    return in;
}

ostream& operator<<(ostream& out, Vector& V)
{
    cout << "[" << endl;

    for(int i = 0; i < V.size; i++)
    {
        out << setw (8) << fixed << setprecision(2)
            <<  get(V,i) << ", ";
    }

    cout << "]" << endl;
    return out;
}
