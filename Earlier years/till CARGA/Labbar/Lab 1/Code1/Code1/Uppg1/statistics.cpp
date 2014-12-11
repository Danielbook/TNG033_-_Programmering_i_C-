#include <iostream>
#include <cmath>
#include <algorithm>

#include "statistics.h"


//Return the largest value stored in V
//Return the smallest value stored in V through reference argument min
//a is an array with n occupied slots
int max_min (int a[], int n, int& min)
{
    int max = a[0];
    min = a[0];

    for(int j = 0; j < n; j++)
    {
        if(a[j ]> max)
        {
            max = a[j];
        }
        if(a[j]<min)
        {
            min = a[j];
        }
    }
    return max;
}

//Return the average of the values stored in a
//a is an array with n occupied slots
double mean (int a[], int n)
{
   int sum = 0;

   for(int i = 0; i < n; i++)
   {
      sum += a[i];
   }

   return sum/n;
}


//Return the median of the values stored in a
//a is a sorted array storing n values
//Medianvärdet är det mittersta värdet
//i den sorterade arrayen
//Om n är jämnt blir det medelvärdet av de två talen i mitten.
double median (int a[], int n)
{
    int k = n/2; // ojämt, avrundar nedåt
    double sum;

    if( n%2 == 0)
    {
        sum = (a[k]+a[k+1])/2;
    }

    else
    {
        sum = a[k];
    }

    return sum;
}


//Returns the standard deviation of n integer numbers in array a
double standard_deviation(int a[], int n)
{
    double avg = mean(a, n);
    double x = 0;

    for (int i=0; i < n; i++)
    {
       x += pow (a[i]-avg, 2)/n;
    }

    return sqrt(x);
}


//Sort array a
//a is an array storing n values
//Use a sorting algorithm different from bubblesort
void sort (int a[], int n) //selection sort
{
    //selection sort
    //LOOPAFÖR LÅNGT!!!OMG!
    int temp;

    int i, j, first;

    for(i = n - 1; i > 0; i--)
    {
        first = 0;
        for(j = 1; j <= i; j++)
        {
            if(a[j] < a[first]){
                first = j;
            }
        }
                temp = a[j];
                a[j] = a[first];
                a[first] = temp;
    }
    return;
}

//swap the values of parameters a and b
//to be used by sort function
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;

    return;
}













