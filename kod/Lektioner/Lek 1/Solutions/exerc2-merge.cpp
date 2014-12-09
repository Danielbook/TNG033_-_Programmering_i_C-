/********************************************************
* TNG033, Lesson 1                                      *
* Exercise 2: merge two sorted sequences                *
* The merge algorithm used here can be useful for       *
* implementing operator+ of class Set, Lab 2            *
* ******************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int SIZE = 100;


void clean_up_stream(istream &in);


int read_seq(int *V, int n);


void merge(const int *S1, int n1, const int *S2, int n2, int *S3, int &n);

void display_seq(int *V, int n);



int main()
{
    int seq1[SIZE], seq2[SIZE], seq3[SIZE];
    int howMany1 = 0, howMany2 =0, howMany3 = SIZE;

    cout << "Enter sequence 1: ";
    howMany1 = read_seq(seq1, SIZE);

    cout << "Enter sequence 2: ";
    howMany2 = read_seq(seq2, SIZE);

    merge(seq1, howMany1, seq2, howMany2, seq3, howMany3);

    //cout << howMany3;

    cout << "\Merged sequence: ";
    display_seq(seq3, howMany3);

    return 0;
}


void clean_up_stream(istream &in)
{
    in.clear(); //Reset the stream error flags, i.e. put stream in back to good state

    //Extract the non-valid input from the stream’s buffer
    string trash;
    getline(cin, trash);
}


int read_seq(int *V, int n)
{
    int count = 0;

    while ( count < n && cin >> V[count] ) //stop reading when a non-numeric value is entered
        count++;

    //stream cin is in sad and depressed state -- we need to help him
    clean_up_stream(cin);

    return count;
}


void merge(const int *S1, int n1, const int *S2, int n2, int *S3, int &n)
{
    int count1 = 0, count2 = 0, count3 = 0;

    //Merge S1 with S2
    while (count1 < n1 && count2 < n2 && count3 < n)
    {
        if (S1[count1] < S2[count2])
        {
            S3[count3++] = S1[count1++];
        }
        else if (S2[count2] < S1[count1])
        {
            S3[count3++] = S2[count2++];
        }
        else
        {
             S3[count3++] = S1[count1++];
             count2++;
        }
    }

    //copy any remaining values from S1 to S3
    while(count1 < n1 && count3 < n)
    {
        S3[count3++] = S1[count1++];
    }

    //copy any remaining values from S2 to S3
    while(count2 < n2 && count3 < n)
    {
        S3[count3++] = S2[count2++];
    }

    n = count3;
}


void display_seq(int *V, int n)
{
    for(int i = 0; i < n; i++)
        cout << V[i] << " ";

    cout << endl;
}


