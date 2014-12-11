/***************************************************************************
* TNG033: Fö 13                                                            *
* Read a sequence of ints from a file and store them in a vector           *
* Iterators connected to streams are used                                  *
* **************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>  //find
#include <fstream>
#include <iterator>

using namespace std;



int main()
{
    vector<int> V;

    ifstream file("data.txt");

    //test if opening the file suceeded
    if ( !file )
    {
        cout << "Data file not found!!" << endl;
        return 0;
    }

    cout << "Reading numbers from file ..." << endl;


    istream_iterator<int> in_it(file);
    istream_iterator<int> in_it_end;  //iterator pointing to the end of a stream

    //Read ints from file
    copy(in_it, in_it_end, back_inserter(V));

//    //same as
//    while (in_it != in_it_end)
//    {
//        V.push_back(*in_it);
//        ++in_it;
//    }

    cout << endl;

    //Display values in the vector to cout
    ostream_iterator<int> oit(cout, " ");

    copy(V.begin(), V.end(), oit);

//    //same as
//    vector<int>::const_iterator cit;
//
//    for(cit = V.begin(); cit != V.end(); ++cit)
//    {
//    	*oit = *cit;
//    }


    return 0;
}


