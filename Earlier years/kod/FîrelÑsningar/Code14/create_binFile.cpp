/***************************************************************************
* TNG033, Fö 14                                                            *
* 1. Create a binary file of Salesman records                              *
* 2. Read back the binary file and display each record                     *
* **************************************************************************/


#include <iostream>     //basic input output
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


int create_table(Salesman *T);


void write_file(fstream& f, const Salesman* T, int n);


void display_file(fstream& f);


/*******************************
* 2. Main function             *
*******************************/


int main()
{
    const int SIZE = 10;

    //Open the binary file
    fstream file("sales.bin", ios::in|ios::out|ios::trunc|ios::binary);

    Salesman sales_table[SIZE];
    int howMany = create_table(sales_table);

    //Test if file opening suceeded
    if (!file)
    {
        cout << "Could not open sales.bin" << endl;
        return 0;
    }

    //Write records in the binary file
    write_file(file, sales_table, howMany);

    //Get number of records in the file
    file.seekp(0, ios::end);
    cout << "Number of salesman records in the file = "
         << file.tellp()/sizeof(Salesman) << endl;

    //back to the file beginning
    file.seekp(0);

    //Read and display the records in the binary file
    display_file(file);

    file.close();


  return 0;
}



/*******************************
* 3. Functions implementation  *
********************************/

int create_table(Salesman *T)
{
    strcpy(T[0].name, "Anna Lund");
    T[0].sales = 200.6789;
    T[0].id = 1;

    strcpy(T[1].name, "Mattias Sund");
    T[1].sales = 3000.5;
    T[1].id = 2;

    strcpy(T[2].name, "Elvira XPTO");
    T[2].sales = 100;
    T[2].id = 3;

    return 3;
}


void write_file(fstream& f, const Salesman* T, int n)
{
    //Table T is sorted by salesman id
    for(int i = 0; i < n; i++)
    {
        Salesman temp = T[i];
        f.write( (char*)&temp, sizeof(Salesman) );
    }
}


void display_file(fstream& f)
{
    Salesman temp;

    //Read first record from file
    f.read( (char*)&temp, sizeof(Salesman) );

    while(f)
    {
        cout << "Id = " << temp.id << "  "
             << "Name = " << temp.name << "  "
             << "Sales = " << fixed << setprecision(2)
             << temp.sales << endl;

        //Read next record from file
        f.read((char*)&temp, sizeof(Salesman));
    }
}
