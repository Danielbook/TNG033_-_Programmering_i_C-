#include <iostream>
#include <cmath>

#include "statistics.h"


//Return the largest value stored in V
//Return the smallest value stored in V through reference argument min
//a is an array storing n ints
int max_min (int a[], int n, int& min)
{
    int max = a[0];
    min = a[0];

    for(int i = 0; i < n; i++ )
    {
        if(max < a[i])
            max = a[i];

        else if (min > a[i])
            min = a[i];

    }

	return max;
}

//Return the average of the values stored in a
//a is an array storing n ints
double mean (int a[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

	return sum/n;
}


//Return the median of the values stored in a
//a is a sorted array storing n ints
//Median is the middle value inthe sorted array, if n is odd
//Otherwise, the median is the average of the two middle values
double median (int a[], int n)
{

    double med = 0;

    if (n%2 != 0)
        med = a[n/2];
    else
    {
        int upp = ceil(n/2);
        int lower = floor(n/2);

        med = (a[upp]+a[lower])/2;

    }

	return med;
}


//Returns the standard deviation of n integers stored in array a
double standard_deviation(int a[], int n)
{

    double standardDev = 0;
    double meanValue = mean(a,n);

    for (int i = 0; i < n; i++)
    {
        standardDev += pow(a[i]-meanValue, 2);
    }

    standardDev /= n;
    standardDev = sqrt(standardDev);

	return standardDev;

}

