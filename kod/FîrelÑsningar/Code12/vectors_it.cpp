/***************************************************************************
* TNG033, Fö 12                                                            *
* A program to illustrate the use of vectors, iterators, and               *
* member functions of class vector: insert and erase                       *
* **************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> V = {1, 2, 3};

    //insert values 1, 2, .., 10 in V
    for(int i = 4; i <= 10; i++)
        V.push_back(i);

    cout << "Usual loop ..." << endl;
    for(int i = 0; i < V.size(); i++)
        cout << V[i] << endl;

    cout << "With a forward iterator ..." << endl;
    for(vector<int>::iterator it = V.begin(); it != V.end(); it++)
        cout << *it << endl;

    cout << "With a reverse iterator ..." << endl;
    for(vector<int>::reverse_iterator it = V.rbegin(); it != V.rend(); it++)
        cout << *it << endl;

    vector<int> V1(V); //V1 is a copy of vector V

    //insert all values from V, in reverse order,
    //before the first element of V1
    V1.insert(V1.begin(), V.rbegin(), V.rend());

    cout << "V1.insert ..." << endl;
    for(int i = 0; i < V1.size(); i++)
        cout << V1[i] << endl;

    //Remove the 2nd value in the vector
    V1.erase(++V1.begin());

    cout << "V1.erase ..." << endl;
    for(int i = 0; i < V1.size(); i++)
        cout << V1[i] << endl;

  return 0;
}


