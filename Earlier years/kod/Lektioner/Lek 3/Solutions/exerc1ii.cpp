/***************************************************************
* TNG033, lesson 3                                             *
* Exerc 1.ii                                                   *
* **************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class AA
{
public:

    AA(int i = 0) : val (i) {};

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

    BB(int k = 0)
    {
        val = rand() % 100;
        val_BB = k;
    };

    void display()
    {
        cout << "BB: " << val << endl;
    }

protected:

    int val_BB;

};


class CC : public AA
{
public:

/*
    CC(int k)
    {
        val = rand() % 50;
        b.val = k; //only class BB or derived classes or class BB
                   //can access the protected data members of an object of class BB
    };
*/

     CC(int k)
      : b(k) //call constructor to initialize object b
    {
        val = rand() % 50;
    };

    void display()
    {
        cout << "CC: " << val << endl;
    }

protected:

    BB b;

};

int main()
{
    BB b(10);
    CC c(20);

    b.display();
    c.display();


    return 0;
}
