/*****************************************************
* TNG033, Lesson 2                                   *
* Exercise 3                                         *
******************************************************/


#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;


class Instrument
{
public:

    Instrument(string b)
    {
        brand = b;


         bool found = false;

        for(int i = 0; i < howMany; i++)
            if (all_brands[i] == b)
                found = true;

        if (!found && howMany < MAX)
            all_brands[howMany++] = b;
    };

   virtual void play(string note) const
    {
        cout << "Instrument::play with "
             << "tune " << note << endl;
    };

    static void display_brands()
    {
        for(int i = 0; i < howMany; i++)
                cout << all_brands[i] << endl;
    };

protected:
    string brand;

    static string all_brands[MAX];
    static int howMany;
};


int Instrument::howMany = 0;
string Instrument::all_brands[MAX];



class Piano : public Instrument
{
    public:

        Piano(string b) : Instrument(b)
        { };

        void play(string note) const
        {
            cout << "Piano::play with "
                  << "tune " << note << endl;
        }
};


class Flute : public Instrument
{
    public:

        Flute(string b) : Instrument(b)
        { };

        void play(string note) const
        {
            cout << "Flute::play with "
                  << "tune " << note << endl;
        }
};


class Violin : public Instrument
{
    public:

        Violin(string b) : Instrument(b)
        { };

        void play(string note) const
        {
            cout << "Violin::play with "
                  << "tune " << note << endl;
        }
};



void tune(Instrument& i)
{
    i.play("middleC");
}

int main()
{
    Piano P1("Yamaha");
    tune(P1);

    Flute F("PureTone");
    tune(F);

    Instrument *ptr_I = new Violin("Stradivarius");
    tune(*ptr_I);

    Piano P2("Bach");
    tune(P2);

    delete ptr_I;

    cout << "\nAll instrument brands" << endl;
    Instrument::display_brands();

    return 0;
}

