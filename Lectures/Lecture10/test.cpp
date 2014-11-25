/*************************
* TNG033, Fö 10          *
* See slide 17           *
* ************************/

#include <iostream>

using namespace std;


class B
{
   public:

     //B(int k = 0)
     B(int k)
      : value(k)
    {  };

   private:
    int value;
};


class D : public B
{
   public:
     D(int i)
      : n(i) // Compilation error due to missing default constructor B::B()
      { } ;

   private:
     int n;
};


int main()
{
    D d(3);

   return 0;
}






