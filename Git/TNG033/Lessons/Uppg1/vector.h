#include <iostream>
#include <iomanip>

using namespace std;

struct Vector
{
    int size;
    double *p_table;
};

void createVector(Vector& V, int l);

void empty_vector(Vector& V);

double get(const Vector& V, int i);

void set(Vector& V, int i, double v);

double length(const Vector &v);

void operator>>(istream& in, Vector& V);

void operator<<(ostream& out, Vector& V);
