/******************************
* TNG033: Lesson 3            *
* Exercise 2                  *
*******************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*******************************
 * Class Uncopyable             *
 ********************************/
class Uncopyable
{
protected:
    Uncopyable(){};
    ~Uncopyable(){};
    
private:
    Uncopyable(const Uncopyable& x);
    
    const Uncopyable& operator=(const Uncopyable& x);
};

/*******************************
* Class Instrument             *
********************************/

class Instrument
{
public:
    //Constructor
    Instrument(string b);
    
    string get_identification() const;
    
    void set_brand(string b)
    {
        brand = b;
    }


protected:
    string brand;
    const int id;
    
    static int id_counter;

};

int Instrument::id_counter = 0;


/**********************************
* Class Instrument                *
* Member functions implementation *
***********************************/


//Constructor
Instrument::Instrument(string b)
    : brand(b), id(id_counter)
{
    ++id_counter;
};

string Instrument::get_identification() const
{
    ostringstream os;
    
    os << brand << "<" << id << "" << endl;
    
    return os.str();
}

/*******************************
* Class Piano                  *
********************************/


class Piano : public Instrument
{
public:

    Piano(string b) : Instrument(b)
    { };

};


/*******************************
* Class Violin                 *
********************************/


class Violin : public Instrument
{
public:

    Violin(string b, bool wood = true)
    : Instrument(b), wood_violin(wood)
    { };
    
    bool is_wooden() const
    {
        return wood_violin;
    }
    
protected:
    bool wood_violin;

};


/*******************************
* Main                         *
********************************/


int main()
{
   Instrument I1("Bach");

    Piano P1("Yamaha");
    Piano P2("Yamaha");

    const Violin V1("Stradivarius");

//    Exercise a.ii
    cout << I1.get_identification() << endl;
    cout << P1.get_identification() << endl;
    cout << P2.get_identification() << endl;
    cout << V1.get_identification() << endl;

    //Exercise b
//    Piano P3(P1);
//    P1 = P2;


    //Exercise c
//    Uncopyable *ptr = new Violin("XXX");
//
//    delete ptr;

    return 0;
}

