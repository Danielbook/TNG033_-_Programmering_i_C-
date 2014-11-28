
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "diver.h"

using namespace std;

/******************************
* 1. Functions declarations   *
*******************************/

//Read divers data from stream in and
//If correct diver's data then store a diver's record in array V
//If incorrect diver's data then write diver's name in log file
//Return number of divers read and stored in V
//V has n slots
//overloaded operator>> should be used in this function
int read_divers(istream& in, Diver V[], int n, ostream& log);


//Display all divers stored in array V to cout
//V stores n divers
//overloaded operator<< should be used in this function
void display(const Diver V[], int n);


//Write results to file
void writeToFile(ostream &res, const Diver V[], const int n);

//Sort V decreasingly by divers final score
//V stores n divers
//operator< should be used in this function
void sort_divers(Diver V[], int n);


/******************************
* 2. Main function            *
*******************************/



int main ()
{
    //Initialize variables
    const int NR_OF_DIVERS = 50;

    Diver V[NR_OF_DIVERS];

    int nmbrOfDivers = 0;
    
    //Which file to read
    string file_name = "/Users/Daniel/Skolarbeten/Nuvarande/TNG033-Programmering_i_C++/Labs/xCode Lab1/Lab1/Uppg2/diver_data4.txt";
    string error_name = "/Users/Daniel/Skolarbeten/Nuvarande/TNG033-Programmering_i_C++/Labs/xCode Lab1/Lab1/Uppg2/log.txt";
    string results_name = "/Users/Daniel/Skolarbeten/Nuvarande/TNG033-Programmering_i_C++/Labs/xCode Lab1/Lab1/Uppg2/results.txt";

    /*
    cout << "File name: " << endl;
    cin >> file_name;
    */

    //Creating stream objects to read from and write to
    ifstream inFil(file_name);
    ofstream errorlog(error_name);
    ofstream results(results_name);
    
    //Check if there were any problems when creating the streams
    if ( !inFil || !errorlog || !results )
    {
        cout << "File could not be opened!!" << endl;
        return 0;
    }

    //Call function read_divers to read the file
    nmbrOfDivers = read_divers(inFil, V, NR_OF_DIVERS, errorlog);

    //Displaying how many divers that have been read
    cout << "Number of divers: " << nmbrOfDivers << endl;
    cout << "------------------------------" << endl;
    
    //Sort the divers by their final score
    sort_divers(V, nmbrOfDivers);

    //Display the divers in the console
    display(V, nmbrOfDivers);

    //Write to result file
    writeToFile(results, V, nmbrOfDivers);

    return 0;
}


/******************************
* 3. Functions definitions    *
*******************************/


//Read divers data from stream in and
//If correct diver's data then store a diver's record in array V
//If incorrect diver's data then write diver's name in log file
//Return number of divers read and stored in V
//V has n slots
//overloaded operator>> should be used in this function
int read_divers(istream& in, Diver V[], int n, ostream& log)
{
    int nmbrOfDivers = 0;

    while( ( nmbrOfDivers < n ) && ( in >> V[nmbrOfDivers] ) ) //Read and test
    {
        //If there were any problems reading, the difficulty is set to -1
        if(V[nmbrOfDivers].difficulty == -1)
        {
            log << V[nmbrOfDivers].name << endl;
        }
        
        //If evereything went right, increment the number of divers
        else
        {
            nmbrOfDivers++;
        }
    }
    
    //If the number of divers is 0
    if( nmbrOfDivers == 0)
    {
        cout << "EMPTY FILE!!!" << endl;
    }

    return nmbrOfDivers;
}


//Display all divers stored in array V to cout
//V stores n divers
//overloaded operator<< should be used in this function
void display(const Diver V[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". " <<  V[i];
    }
}

//Write results to from array V to file
void writeToFile(ostream &res, const Diver V[], const int n)
{
   for (int i = 0; i < n; i++)
    {
        res << V[i];
    }
}

//To be used by sort function
void swap(Diver& a, Diver& b)
{
    Diver temp = a;
    a = b;
    b = temp;
}

//Sort V decreasingly by divers final score
//V stores n divers
//operator< should be used in this function
void sort_divers(Diver V[], int n)
{
    int i, j, minIndex;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (V[minIndex] < V[j])
                minIndex = j;
        }

        if (minIndex != i)
            swap(V[i], V[minIndex]);
    }
}



