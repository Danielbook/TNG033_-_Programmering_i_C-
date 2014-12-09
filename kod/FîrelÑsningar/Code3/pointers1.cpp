/**********************************************************************************
* TNG033, Fö 3                                                                    *
* To illustrate the use of pointer with array notation                            *
* To illustrate the use of array with pointer notation                            *
* ********************************************************************************/


#include <iostream>
#include <iomanip>

using namespace std;


//Returns true, if array V1 stores the same values as V2
//n is the number of values stored in the arrays
bool is_equal(const int *V1, const int *V2, int n);


//Copy array V1 into array V2
//V1 stores n elements
void do_copy(const int *V1, int *V2, int n);


int main()
{
  int const SIZE = 10;

  int A1[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  cout << "Display array contents: array notation" <<endl;
  for(int i = 0; i < SIZE; i++)
    cout << A1[i] << " ";

  cout << endl;

  cout << "Display array contents: pointer notation" <<endl;
  for(int *p = A1; p < (A1+SIZE); p++)
    cout << *p << " ";

  cout << endl;

  cout << "Display array contents: array with pointer notation" << endl;
  for(int i = 0; i < SIZE; i++)
    cout << *(A1+i) << " "; //A1[i]

  cout << endl;

  cout << "Display array contents: pointer with array notation" << endl;
  int *p = &A1[0];
  for(int i = 0; i < SIZE; i++)
    cout << p[i] << " "; //*(p+i)

  cout << endl;

  int A2[SIZE] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

  if ( is_equal(A1, A2, SIZE) )
        cout << "Arrays A1 and A2 are equal!" << endl;
    else
        cout << "Arrays A1 and A2 are different!" << endl;

  //Copy A1 into A2
  cout << "Copying A1 to A2 ..." << endl;
  do_copy(A1, A2, SIZE);


  cout << "\nA2: ";
  p = A2;
  for(int i = 0; i < SIZE; i++)
    cout << p[i] << " "; //pointer with array notation

  cout << endl;

  return 0;
}


//Returns true, if array V1 stores the same values as V2
//n is the number of values stored in the arrays
bool is_equal(const int *V1, const int *V2, int n)
{
    const int *p1 = V1, *p2 = V2; //pointers to constants

    for( ; p1 != (V1+n); p1++, p2++)
        if (*p1 != *p2)
            return false;

    return true;
}



//Copy array V1 into array V2
//V1 stores n elements
void do_copy(const int *V1, int *V2, int n)
{
    const int *V1_end = V1+n;

    for( ; V1 != V1_end; V1++, V2++)
        *V2 = *V1;
}
