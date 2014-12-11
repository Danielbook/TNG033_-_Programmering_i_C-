/***************************************************************************
* TNG033: Fö 12                                                            *
* Several examples of function templates                                   *
* **************************************************************************/

#include <iostream>
#include <iomanip>

#include "C:\Arbets\TNG033\Lectures\2014\Fö12\Code12\Clock\clock.h"
//You may need to modify this path to the header file clock.h

using namespace std;

template<class T>
void Swap(T& a, T& b)
{
    T temp = a;

    a = b;
    b = temp;
}

//version V1
//Return the smallest of two given values, a and b
//Both a and b have type T
template<class T>
const T& Min(const T& a, const T& b)
{
    if (a < b)
        return a;
    else
        return b;
}

//Return the smallest value stored in an array A storing n values of type T
template<class T>
const T& Min(const T* A, int n)
{
    const T *p_min = A;

    for(int i = 0; i < n; i++)
        if (A[i] < *p_min)
            p_min = A+i;

    return *p_min;
}

//version V2
//Return the smallest value stored in an array A
//Note that the type of the values stored in A (T) and
//number of values stored in A (n) are template arguments
//Note: this class template leads easily to code bloating
//thus, version V1 is preferable
template<class T, int n>
const T& Min(const T* A)
{
    const T *p_min = A;

    for(int i = 0; i < n; i++)
        if (A[i] < *p_min)
            p_min = A+i;

    return *p_min;
}


int main()
{
    string S1 = "Floyd", S2 = "Pink";
    int i = 5, j = 10;

    cout << "Before swap: S1 = "  << S1
         << " S2 = " << S2 << endl;

    Swap(S1,S2); //specialization of function Swap for string
    //Swap<string>(S1,S2);

    cout << "After swap: S1 = "  << S1
         << " S2 = " << S2 << endl;

    cout << "min("  << i << "," << j << ")= "
         << Min(i,j) //specialization of function Min for int
         << endl;

    cout << endl;


    int V1[] = {4, 1, 9, 12, -1, 10, 23};
    cout << "min(V1) = " << Min(V1, 7) << endl;
    /* the specialization below is created -- V1
        const int& Min(const int* A, int n)
        {
            const int *p_min = A;

            for(int i = 0; i < n; i++)
                if (A[i] < *p_min)
                    p_min = A+i;

            return *p_min;
        }
    */



    cout << "min(V1) = " << Min<int,7>(V1) << endl;
    /* the specialization below is created -- V2
        const int& Min<int,7>(const int* A)
        {
            const int *p_min = A;

            for(int i = 0; i < 7; i++)
                if (A[i] < *p_min)
                    p_min = A+i;

            return *p_min;
        }
    */

    cout << "min(V1[0...3]) = " << Min<int,4>(V1) << endl;
    /* another specialization is created -- V2
        const int& Min<int,4>(const int* A)
        {
            const int *p_min = A;

            for(int i = 0; i < 4; i++)
                if (A[i] < *p_min)
                    p_min = A+i;

            return *p_min;
        }
    */


    Clock V2[3] = {Clock(10,30,0), Clock(0,30,0), Clock(2,0,0)};

    cout << "\nMin of clocks array: " << Min(V2,3) << endl;
    /* the specialization below is created -- V1
        const Clock& Min(const Clock* A, int n)
        {
            const Clock *p_min = A;

            for(int i = 0; i < n; i++)
                if (A[i] < *p_min)
                    p_min = A+i;

            return *p_min;
        }
    */



    return 0;
}


