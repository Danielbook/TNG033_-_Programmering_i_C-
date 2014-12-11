/***************************************************************************
* TNG033: Fö 12                                                            *
* A program to illustrate the use of vectors                               *
* to represent tables with lines and columns                               *
* A vector of vectors is used                                              *
* **************************************************************************/


#include <iostream>
#include <vector>

using namespace std;

//define a new type representing a line in a table
typedef vector<double> Line;

//define a new type representing a 2-dimensional table
typedef vector<Line> Table;

void display(Table A);


int main()
{
   const int N_LINES = 4;
   const int N_COL = 12;

   Table M(4); // create a table with 4 lines

   for(int i = 0; i < M.size(); i++)
    cout << "M[" << i << "] line size= "
         << M[i].size() << endl;

    cout << endl;

    //Create 12 columns for each line of the table M
    for(int i = 0; i < M.size(); i++)
        M[i]. resize(N_COL); //create N_COLs for line i

    for(int i = 0; i < M.size(); i++)
        cout << "M[" << i << "] line size = "
             << M[i].size() << endl;

    cout << endl;

    M[1][2] = 4.4;

    display(M);

    M[0].push_back(-4); //line 0 has now 13 columns

    display(M);

  return 0;
}


void display(Table M)
{
    for(int line = 0; line < M.size(); line++){
        cout << "Line " << line << endl;
        for(int col = 0; col < M[line].size(); col++)
            cout << "M[" << line <<"]["
                 << col << "]= " << M[line][col] << endl;

         cout << endl;
    }
}
