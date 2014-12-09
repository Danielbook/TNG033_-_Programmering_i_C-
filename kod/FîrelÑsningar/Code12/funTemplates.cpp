/***************************************************************************
* TNG033, Fö 12                                                            *
* Several examples of function templates                                   *
* **************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

template<class T>
void Swap(T& a, T& b)
{
    T temp = a;

    a = b;
    b = temp;
}

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
const T& Min(T* A, int n)
{
    T min = A[0];

    for(int i = 0; i < n; i++)
        if (A[i] < min)
            min = A[i];

    return min;
}

//Return the smallest value stored in an array A
//Note that the type of the values stored in A (T) and
//number of values stored in A (n) are template arguments
template<class T, int n>
const T& Min(const T* A)
{
    T min = A[0];

    for(int i = 0; i < n; i++)
        if (A[i] < min)
            min = A[i];

    return min;
}



//Return the smallest C-string stored in array A
//A stores n C-strings
char* Min(char* A[], int n) //To be used for array of C-strings
{
    int min = 0;

    for(int i = 0; i < n; i++)
        if ( strcmp(A[i], A[min]) < 0)
            min = i;

    return A[min];
}


//Return the smallest of two given values, a and b
//a and b can have different types: a has a type T1 and b has a type T2
template <class T1, class T2>
T1 GetMin (T1 a, T2 b)
{
  if (a < b)
        return a;
    else
        return b;
}



int main()
{
    string S1 = "Floyd", S2 = "Pink";
    int i = 5, j = 10;

    cout << "Before swap: S1 = "  << S1
         << " S2 = " << S2 << endl;
    Swap(S1,S2); //specialization of function Swap for string
    cout << "After swap: S1 = "  << S1
         << " S2 = " << S2 << endl;

    cout << "Before swap: i = "  << i
         << " j = " << j << endl;
    Swap(i,j); //specialization of function Swap for int
    cout << "After swap: i = "  << i
         << " j = " << j << endl;

    cout << endl;

    cout << "min = " << Min<double>(4.5, 7) << endl;
    cout << "min = " << GetMin(4.5, 7) << endl;


    int V1[] = {4, 2, 9, 12, -1};
    cout << "min(V1) = " << Min(V1, 5) << endl;
    /* the specialization below is created
        const int& Min(const int* A, int n)
        {
            intmin = A[0];

            for(int i = 0; i < n; i++)
                if (A[i] < min)
                    min = A[i];

            return min;
        }
    */



    cout << "min(V1) = " << Min<int,5>(V1) << endl;
    /* the specialization below is created
        const int& Min(const int* A)
        {
            intmin = A[0];

            for(int i = 0; i < 5; i++)
                if (A[i] < min)
                    min = A[i];

            return min;
        }
    */


    char* V2[] = {"BB", "AA"};
    cout << "min(V2) = " << Min(V2, 2) << endl;
    //does not create a specialisation of the function template

   return 0;
}


