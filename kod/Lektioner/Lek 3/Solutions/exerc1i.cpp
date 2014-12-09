/***************************************************************
* TNG033, lesson 3                                             *
* Exerc 1.i                                                    *
* **************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class AA
{
public:

    AA(int i) : val (i) {};

    virtual void display()
    {
        cout << "AA: " << val << endl;
    }

protected:

    int val;

};


class BB : public AA
{
public:

    /*
    BB()
    //Default constructor for the base class AA() is called automatically
    //before the body of BB() is executed
    //However, there is no default constructor AA()
    {
        val = rand() % 100;
    };
    */

     BB()
      : AA(rand() % 100)
      { };


    void display()
    {
        cout << "BB: " << val << endl;
    }

};

int main()
{
    BB V[10];

    for(int i = 0; i < 10; i++)
            V[i].display();

    return 0;
}
