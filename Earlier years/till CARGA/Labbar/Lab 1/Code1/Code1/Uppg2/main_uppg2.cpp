#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "diver.h"

/******************************
* 1. Functions declarations   *
*******************************/

//Read divers data from cin and
//store each diver in array V
//V has size slots
//Return number of divers read and stored in V
//overloaded operator>> should be used in this function
int read_divers(Diver V[], int size);


//Display all divers store in array V to cout
//V stores n divers
//overloaded operator<< should be used in this function
void display(const Diver V[], int n);


//Sort V decreasingly by divers final score
//V stores n divers
//operator< should be used in this function
void sort (Diver V[], int n);


/******************************
* 2. Main function            *
*******************************/



int main ()
{
    const int NR_OF_DIVERS = 20;

    Diver theDivers[NR_OF_DIVERS];

    //Read divers data
    int howMany = read_divers(theDivers, NR_OF_DIVERS);

    //cout << "howMany = " << howMany << endl;

    if (!howMany)
    {
        cout << "No data given!!" << endl;
        return 0;
    }

    //Calculate final score for each diver
    for (int i = 0; i < howMany; i++ )
    {
        calculate_final_score(theDivers[i]);
    }

    //Sort divers decreasingly by final score
    sort(theDivers, howMany);

    //Display divers
    cout << "\nDivers Results" << endl;
    cout << "=======================================" << endl;
    display(theDivers, howMany);

    return 0;
}


/******************************
* 3. Functions definitions    *
*******************************/


//Read divers data from cin and
//store each diver in array V
//V has size slots
//Return number of divers stored in V
//overloaded operator>> should be used in this function
int read_divers(Diver V[], int size)
{
    int antal = 0;

    ifstream file("diver_data5.txt");

    if(!file.is_open()){
        cout << "Data file not found!" << endl;
        return 0;
    }

    while((antal < size) && (file >> V[antal])){
        antal++;
    }

    //cout << endl << endl<< "Antal"  << antal;

    return antal;
}


//Display all divers stored in array V to cout
//V stores n divers
//overloaded operator<< should be used in this function
void display(const Diver V[], int n)
{
    int p = 0;

    for(int i = 0; i < n; i++){
        if(!(V[i].name == "")){ //om namn existerar
            cout << setw(3) << right << p+1 << ". " << V[i] << endl;
            p++;
        }
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
void sort (Diver V[], int n)
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(V[j] < V[j+1])
                swap(V[j], V[j+1]);
        }
    }
}



