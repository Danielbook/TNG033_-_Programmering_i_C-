/********************************************************
* Lab 5                                                 *
* 1. Read each text file with jump scores for a round   *
* 2. Binary file of divers should be updated            *
*********************************************************/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include "diver.h"

using namespace std;

const int NR_OF_REF = 7;

/*******************************
* Function declarations        *
********************************/

//lab 1
double calculate_result(double scores [], double difficulty);

//Compare two divers by total number of points
bool compare(Diver d1, Diver d2);

//Update the binary file with the data in textfile
void update_bin_file(ifstream& textfile, fstream& binfile);

//Read the binary file binfile and load the Diver records into vector D
void read_bin_file(ifstream &binfile, vector<Diver> &D);


/*********************************
* main -- Do not modify          *
**********************************/

int main( )
{

    //Read a text file for one round of jumps

    string file_name = "round_5.txt";

    cout << "Filname: ";
    //cin >> file_name;

    ifstream textfile(file_name.c_str());

    //Open the binary file in read+write mode
    fstream binfile("divers.bin", ios::in | ios::out | ios::binary);

    if (!textfile || !binfile)
    {
        cout << "\nCould not open a file!!" << endl;
        return 0;

    }

    cout << "\nUpdating binary file of divers data ..." << endl;
    update_bin_file(textfile, binfile);

    binfile.close();
    textfile.close();

    /* *************************************************************** */

    //Read the updated binary file and load the diver records into a vector

    ifstream binfile1("divers.bin", ios::in | ios::binary); //open binary file in reading mode

    vector<Diver> all_divers;

    if(binfile1)
    {
      cout << "\nReading updated binary file ..." << endl;
      read_bin_file(binfile1, all_divers);

      binfile1.close();
    }

    sort (all_divers.begin(), all_divers.end(), compare);

    cout <<"\nDisplay the binary file sorted by total points ..." << endl;
    cout << "Nr   Name"
         << setw(25) << "Round 1"
         << setw(8) << "Round 2"
         << setw(8) << "Round 3"
         << setw(8) << "Round 4"
         << setw(8) << "Round 5"
         << setw(8) << "Total" << endl;

    for(int i = 0; i != all_divers.size(); i++)
        cout << all_divers[i] << endl;

    return 0;
}


/*******************************
* Function implementation      *
********************************/

//lab 1
double calculate_result(double scores [], double difficulty)
{
    double max = scores[0], min = scores[0], result;

    for (int i = 1; i < NR_OF_REF; i++ )
    {
        if (scores[i] > max)
        {
            max = scores[i];
        }

        if (scores[i] < min)
        {
            min = scores[i];
        }
    }

    double sum = 0;
    for (int i = 0; i < NR_OF_REF ; i++)
    {
        sum += scores[i];
    }

    sum = sum - max - min;
    result = 3 * difficulty * sum / (NR_OF_REF - 2);

    return result;
}


//Compare two divers by total number of points
bool compare(Diver d1, Diver d2)
{
    return d1.getTotal() > d2.getTotal();
}


//Update the binary file with the data in textfile
void update_bin_file(ifstream& textfile, fstream& binfile)
{

    string line, word, tempDiver, roundTemp;
    map<string,double> table;
    map<string,double>::iterator it;
    typedef vector<Diver> Divers;

    int counter, round;
    double points[6], difficulty;
    while(getline(textfile, line))
    {
        if(*line.begin() == 'R')
        {
            roundTemp = *line.rbegin();
            round = atoi(roundTemp.c_str());
        }
        else if(*line.begin() == 'D')
        {
            tempDiver = line;
        }
        else
        {
            istringstream instream(line);

            word = "";
            counter = 0;
            while (instream >> word)
            {
                if(counter == 0)
                    difficulty = atof(word.c_str());
                else
                    points[counter-1] = atof(word.c_str());
                counter++;
            }
            double result = calculate_result(points, difficulty);
            table[tempDiver] = result;

        }
        //
        //binfile.write((char*) &temp, sizeof(Driver));
    }
    Diver temp;
    int count = 0;
    for (it = table.begin(); it!= table.end(); it++)
    {
        //cout<<it->first << " & " << it->second<<endl;
        //set position to read from diver with specific id
        streampos pos = count * sizeof(Diver);
        binfile.seekg(pos, ios::beg);

        //Read Diver with selected id
        binfile.read((char*)&temp, sizeof(Diver));
        //update diver result
        if(temp.getID() == it->first){
            temp.update(round, it->second);
            //set position to write from
            pos = count * sizeof(Diver);
            binfile.seekp(pos, ios::beg);
            count++;
            //write the updated score to the binary file
            binfile.write((char*)&temp, sizeof(Diver));
            cout<<temp;
            if(++it == table.end())
                break;
            it = table.begin();

        }
    }






}


//Read the binary file binfile and load the Diver records into vector D
void read_bin_file(ifstream &binfile, vector<Diver> &D)
{
    Diver temp;
    //Read first record from file
    binfile.read((char*) &temp, sizeof(Diver) );

    while (binfile)
    {
        D.push_back(temp);
        binfile.read( (char*)&temp, sizeof(Diver) );
    }
}

