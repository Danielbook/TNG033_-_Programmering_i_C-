/***************************************************************************
* TNG033, Fö 12                                                            *
* Defines a template for class Matrice                                     *
* The template has three arguments:                                        *
*  - type T of the values stored in the matrice                            *
*  - number of LINES                                                       *
*  - number of columns (COLS)                                              *
* Note that there is no need to use dynamic memory allocation              *
* **************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

/***********************************************
* Template for class Matrice                   *
* Template arguments: type T, LINES, COLS      *
************************************************/

template <class T, int LINES = 10, int COLS = 10>
class Matrice
{
    public:

    Matrice(T init_val);

    //default copy constructor and operator= work, no need to program them!

    const Matrice& operator+=(const Matrice &M);

    istream& read(istream& is);
    ostream& display(ostream& os);

    private:
        T table[LINES][COLS];

};

/************************************************
* Member functions implementation               *
*************************************************/


template <class T, int LINES, int COLS>
Matrice<T, LINES, COLS>::Matrice(T init_val)
{
    for(int i = 0; i < LINES; i++)
        for(int j = 0; j < COLS; j++)
            table[i][j] = init_val;
}


template <class T, int LINES, int COLS>
const Matrice<T, LINES, COLS>&
Matrice<T, LINES, COLS>::operator+=(const Matrice &M)
{
    for(int i = 0; i < LINES; i++)
        for(int j = 0; j < COLS; j++)
            table[i][j] += M.table[i][j];

     return *this;
}


template <class T, int LINES, int COLS>
ostream& Matrice<T, LINES, COLS>::display(ostream& os)
{
    os << "[" << endl;
    for(int i = 0; i < LINES; i++)
    {
        for(int j = 0; j < COLS; j++)
            os << fixed << setprecision(2) << setw(5)
               << table[i][j];

        os << endl;
    }
    os << "]" << endl;

    return os;
}


template <class T, int LINES, int COLS>
istream& Matrice<T, LINES, COLS>::read(istream& in)
{
    //Read user given values
    for(int i = 0; i < LINES; i++)
        for(int j = 0; j < COLS; j++)
        {
            in >>  table[i][j];
        }

    return in;
}

/***********************************************
* Test program                                 *
************************************************/

//Display the menu
void display_menu()
{
    cout << endl << setw(35) << setfill('*') << '*' << endl;
    cout << "1. Display matrices" << endl;
    cout << "2. Add matrices" << endl;
    cout << "3. Quit" << endl;
    cout << setw(35) << setfill('*') << '*' << endl;
    cout << setfill(' ');
}


int main()
{
    //create matrice 2*2
    Matrice<int,2,2> M1(0), M2(0), M3(0); //default constructor is called

    cout << "Enter matrix M1(2*2): ";
    M1.read(cin);

    cout << "Enter matrix M2(2*2): ";
    M2.read(cin);

    Matrice<int,2,2> M4(M1); //default copy constructor
    cout << endl << "M4 = " << endl;
    M4.display(cout);

    int option;

    do
    {
        display_menu();

        cout << "Option ? ";
        cin >> option;
        cin.ignore();

        switch (option){
            case 1: cout << endl << "M1 = " << endl;
                    M1.display(cout);
                    cout << endl;
                    cout << endl << "M2 = " << endl;
                    M2.display(cout);
                    cout << endl;
                    break;
            case 2: cout << endl << "M1 += M2" << endl;
                    M1 += M2;
                    M3 = M1;
                    M3.display(cout);
                    cout << endl;
                    break;
            case 3: break;
            default: cout << "Wrong option!!" << endl;
        }
   } while (option != 3);

   cout << "GoodBye." << endl;

   return 0;
}


