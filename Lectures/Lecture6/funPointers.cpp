/***************************************************************************
* TNG033, Fö 6                                                             *
* Program to illustrate the use of pointers to functions                   *
* **************************************************************************/

#include <iostream>

using namespace std;


//Define a new type COMPARISON has a pointer to a boolean function
typedef bool (*COMPARISON) (int , int);


bool lessEqual(int a, int b)
{
    if (a <= b)
        return true;

    return false;
}

bool greaterEqual(int a, int b)
{
    if (a >= b)
        return true;

    return false;
}

//Comparison function is passed as an argument
//sort function can be used to sort increasingly or decreasingly
void bubbelsort(int *V, COMPARISON f, int n)
{
    int temp;

    //sort
    for ( int pass = 0; pass <= n - 2; pass++ ) // passes

        for (int i = 0; i <  n - 1; i++ )      // one pass
        {

            if ( f(V[ i ],V[ i + 1 ]) )   // compare a pair of adjacent values
            {
                //swap
                temp = V[ i ];
                V[ i ] = V[ i + 1 ];
                V[ i + 1 ] = temp;
            }
        }
}




int main()
{
    const int SIZE = 10;

    int seq[SIZE] = {2,5,1,7,3,6,2,9,10,0};

    cout << "SORT DECREASINGLY" << endl;
    bubbelsort(seq, lessEqual, SIZE);

    for(int i = 0; i < SIZE; i++)
        cout << seq[i] << " ";

    cout << endl << endl;

    cout << "SORT INCREASINGLY" << endl;
    bubbelsort(seq, greaterEqual, SIZE);

    for(int i = 0; i < SIZE; i++)
        cout << seq[i] << " ";

    cout << endl;

    return 0;
}

/*
//Sorts increasingly
void bubbelsort(int V[], int n)
{
    int temp;

    //sort
    for ( int pass = 0; pass <= n - 2; pass++ ) // passes

      for (int i = 0; i <  n - 1; i++ )  {   // one pass

         if ( V[ i ] > V[ i + 1 ])   // compare a pair of adjacent values
             {
                 //swap
                 temp = V[ i ];
                 V[ i ] = V[ i + 1 ];
                 V[ i + 1 ] = temp;
             }
      }
}

*/
