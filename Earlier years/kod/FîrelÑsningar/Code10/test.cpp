/***************************************************************************
* TNG033, Fö 10                                                            *
* See slide 15                                                             *
* **************************************************************************/



#include <iostream>

using namespace std;


class B
{
   public:

       B() = default;

       B() {};

     //B(int k = 0) //can be used as default constructor
     //B() = default;
     B(int k = 0)
      : value(k)
    {  };

   private:
    int value;
};


class D : public B
{
   public:
     D(int i)
      : n(i), B() // Compilation error due to missing default constructor B::B()
      { } ;

   private:
     int n;
};


int main()
{
    D d(3);

   return 0;
}






