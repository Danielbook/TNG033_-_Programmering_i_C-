#include <iostream>
#include <new>
#include "vector.h"

using namespace std;

int main()
{ 
    int nmbrOfCoords = 0;
    Vector V;

    double coords = 0.0;

    cout << "Number of coordinates: " << endl;
    cin >> nmbrOfCoords;

    createVector(V, nmbrOfCoords);

    cout << "Enter coordinates: " << endl;
    cin >> coords;
    
    cout << "Vector length: " << length(V) << endl;

    return 0;
}
