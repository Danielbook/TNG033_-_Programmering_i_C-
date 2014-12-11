/*******************************************************************************
* TNG033, Fö 14                                                                *
* Given a binary file sorted by Salesman's id                                  *
* Given a salesman id then                                                     *
* 1. read salesman data from the binary file into main memory, for salesman id *
* 2. update the sales amount                                                   *
* 3. write the updated record back to the binary file                          *
* ******************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

/*******************************
* 1. Declarations              *
********************************/

const int MAX = 20;

struct Salesman
{
    char name[MAX];
    double sales;  //total of sales
    int id;        //employee number
};

void display_file(fstream& f);



/*******************************
* 2. Main function             *
*******************************/


int main()
{
    //Open the binary file
    fstream file("sales.bin", ios::in|ios::out|ios::binary);
    //The file has only 3 records with id = 1, id = 2, id = 3

    //Test if file opening suceeded
     if (!file)
    {
        cout << "Could not open sales.bin" << endl;
        return 0;
    }

    //Display all records in the file
    cout << "The file before updates ..." << endl;
    display_file(file);

    cout << endl;

    int id;
    Salesman temp;
    double s = 0;

    while(true)
    {

        cout << "\nSalesman id? ";
        cin >> id;

        if (id <= 0 || id > 3)
            break;//exit the loop

        cout << "Sales?";
        cin >> s;

        //Set file’s position indicator over the record id
        streampos pos = (id-1) * sizeof(Salesman);
        //cout << "position indicator = " << pos << endl;

        file.seekg(pos, ios::beg);

        //Read Salesman record id
        file.read( (char*)&temp, sizeof(Salesman) );

//        cout << "Id = " << temp.id << "  "
//             << "Name = " << temp.name << "  "
//             << "Sales = " << fixed << setprecision(2)
//             << temp.sales << endl;

        //update sales
        temp.sales += s;

        //Set file’s position indicator over the record id again
        pos = (id-1) * sizeof(Salesman);
        file.seekp(pos, ios::beg);

        //write updated information back into the binary file
        file.write( (char*)&temp, sizeof(Salesman) );
    }

    file.seekg(0, ios::beg); //back to the file beginning

    cout << "\nThe updated file..." << endl;

    //Display all records in the file
    display_file(file);

    file.close();


  return 0;
}



/*******************************
* 3. Functions implementation  *
********************************/

void display_file(fstream& f)
{
    Salesman temp;

    //Read first record from file
    f.read( (char*)&temp, sizeof(Salesman) );

    while (f)
    {
        cout << "Id = " << temp.id << "  "
             << "Name = " << temp.name << "  "
             << "Sales = " << fixed << setprecision(2)
             << temp.sales << endl;

        //Read next record from file
        f.read( (char*)&temp, sizeof(Salesman) );
    }

    f.clear(); //reset error flags
}



