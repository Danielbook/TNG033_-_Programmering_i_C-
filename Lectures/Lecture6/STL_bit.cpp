/***************************************************************************
* TNG033, Fö 6                                                             *
* A first taste of STL                     *
* **************************************************************************/

#include <iostream>
#include <cstdlib>
#include <algorithm> //generate

using namespace std;

//Generate a random number in [0,99]
int RandomNumber1 ()
{
    return (rand()%100);
}

//Generate a random number in [1,6]
int RandomNumber2 ()
{
    return (1+rand()%6);
}

int main()
{
    const int SIZE = 10;

    int seq1[SIZE];
    int seq2[SIZE];

    //seq1[i] = RandomNumber1(); -- for each slot i
    generate(seq1, seq1+SIZE, RandomNumber1);

    cout << "SEQ1" << endl;
    for(int i = 0; i < SIZE; i++)
        cout << seq1[i] << " ";

    cout << endl << endl;

    //seq2[i] = RandomNumber2(); -- for each slot
    generate(seq2, seq2+SIZE, RandomNumber2);

    cout << "SEQ2" << endl;
    for(int i = 0; i < SIZE; i++)
        cout << seq2[i] << " ";

    cout << endl;

    return 0;
}
