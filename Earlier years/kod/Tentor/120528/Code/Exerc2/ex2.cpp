#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>

using namespace std;


bool congruent_eq(int a, int b)
{
    return (a%5 == b%5);
}

bool f(int n)
{
    return (n > 15);
}


/**************************************
* Main function                       *
***************************************/


int main()
{
    //Code for exercise a.

    ifstream file;
    string name;

    cout << "File name: ";
    cin >> name;

    file.open(name.c_str());

    if (!file)
    {
        cout << "Could not open file " << name << endl;
        return 0;
    }

    //Code for exercise b.
    vector<int> vec1;
    int i;
    string s;

    while (file >> s)
    {
        istringstream is(s);

        if (is >> i) //any double is automatically converted to an int
        {
            vec1.push_back(i);
            //cout << i << endl;
        }
    }

    cout << endl;

    //Code for exercise c.
    cout << "Number of values read: " << vec1.size() << endl;

    cout << endl;


    //Code for exercise d.
    sort(vec1.begin(), vec1.end());


    //Code for exercise e.
    ostream_iterator<int> out_it(cout, " ");

    cout << "Values in increasing order" << endl;
    copy(vec1.begin(), vec1.end(), out_it);
    cout << endl << endl;

    cout << "Values in decreasing order" << endl;
    copy(vec1.rbegin(), vec1.rend(), out_it);
    cout << endl << endl;

    //Code for exercise f.
    vector<int>::iterator it1 = vec1.begin();
    vector<int>::iterator it2 = vec1.begin();
    int n = vec1.size();

    if (n%2) //odd size
    {
        it1++;
        it2++;
    }

    //for(int i = 1; i <= n/2; i++, it2++);
    it2 += n/2;

    if (equal(it1, it2, it2, congruent_eq))
        cout << "Congruence test succeeded!!" << endl;
    else
        cout << "Congruence test failed!!" << endl;

    cout << endl;

    //Code for exercise g.
    vector<int> vec2(vec1.begin(), vec1.end());

    //Code for exercise h.
    replace_if(vec2.begin(), vec2.end(), f, 20);

    cout << "Values in vector vec2" << endl;
    copy(vec2.begin(), vec2.end(), out_it);
    cout << endl << endl;

    //Code for exercise i.
    if (equal(vec1.begin(), vec1.end(), vec2.begin(), congruent_eq))
        cout << "Congruence test succeeded!!" << endl;
    else
        cout << "Congruence test failed!!" << endl;

    file.close();

    return 0;
}
