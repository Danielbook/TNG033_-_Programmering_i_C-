/***************************************************************
* TNG033, lesson 3                                             *
* Exerc 1.iii                                                  *
* **************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

class AA
{
public:

    AA(int i = 0) : val (i) {};

    virtual ~AA()
    {
        //do nothing
    };

    virtual void display()
    {
        cout << "AA" << endl;
    }

protected:

    int val;

};

class BB : public AA
{
public:

    //The compiler adds automatically the destructor ~BB() { };

    void display()
    {
        //this->~BB(); //<-- PROBLEM! Avoid callind the destructor explicitly in teh code

        cout << "BB" << endl;
    }

};

int main()
{
    BB *ptr_b = new BB;;

    ptr_b->display();
    ptr_b->display();

    return 0;
}
