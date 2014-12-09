#include <iostream>
#include <iomanip>

using namespace std;


/**************************************
* Class Celestial_Body definition     *
***************************************/

class Celestial_Body {
    public:

        Celestial_Body(string n) : name(n)
        {  N_BODIES++; } ;

        virtual ~Celestial_Body() { N_BODIES--; } ;

        string get_name() const
        {
            return name;
        };

        static int number_of_bodies()
        {
            return N_BODIES;
        };

        friend ostream& operator<<(ostream& os, const Celestial_Body& c);

    protected:

        const string name;

        static int N_BODIES; //count the number of celestial bodies

     virtual void display(ostream& os) const = 0;
};


/***********************************************************
* Class Celestial_Body member functions implementation     *
************************************************************/

int Celestial_Body::N_BODIES = 0;

ostream& operator<<(ostream& os, const Celestial_Body& c)
{
    c.display(os);
    return os;
}


/*********************************
* Class Star definition          *
**********************************/


class Star : public Celestial_Body {
    public:

        Star(string n, string g)
         : Celestial_Body(n), galaxy(g)
        { };


    protected:
        string galaxy;


    virtual void display(ostream& os) const;
};



/***********************************************
* Class Star member functions implementation   *
************************************************/


void Star::display(ostream& os) const
{
    os << "Star " << name
       << " from galaxy " << galaxy << "." << endl;
}


/*********************************
* Class Planet definition        *
**********************************/


class Planet : public Celestial_Body {
    public:

        Planet(string n, Celestial_Body *p, bool life = false)
         : Celestial_Body(n), body(p), populated(life)
        { };


        bool is_populated( ) const
        {
            return populated;

        }

        const Celestial_Body* get_celestial_body() const
        {
            return body;
        }


    protected:
        const Celestial_Body* body;
        bool populated;

    virtual void display(ostream& os) const;
};



/**************************************************
* Class Planet member functions implementation    *
***************************************************/


void Planet::display(ostream& os) const
{
    os << "Planet " << name
       << " belongs to " << body->get_name()
       << " and" << " it is " << (populated ? "" : "not ")
       << " populated." << endl;
}


/**************************************
* Main function                       *
***************************************/


int main()
{
    const int MAX = 6;

    Celestial_Body* DB[MAX];
    int howMany = 3;

    DB[0] = new Star("Helios", "Milky Way");;
    DB[1] = new Planet("Hearth", DB[0], true);
    DB[2] = new Planet("Moon",DB[1]);

    const Planet P3("MoonX", DB[1]);

    cout << P3.get_name() << " belongs to "
         << P3.get_celestial_body()->get_name() << endl
         <<"Population of " << P3.get_name() << " is "
         << P3.is_populated() << "." << endl << endl;


    cout << endl << "Other CELESTIAL BODIES..." << endl << endl;
    for(int i = 0; i < howMany; i++)
        cout << *DB[i] << endl << endl;


    cout << "Number of celestial bodies: "
         << Celestial_Body::number_of_bodies() << endl << endl;

    cout << "Deleting some celestial bodies ..." << endl << endl;
    for(int i = 0; i < howMany; i++)
        delete DB[i];

    cout << "Number of celestial bodies: "
         << Celestial_Body::number_of_bodies() << endl;


    return 0;
}
