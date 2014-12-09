#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


/************************
* Class AA definition   *
*************************/

class AA
{
public:

    AA(string s) : name(s)
    {
        NO_FRIENDS++;
    };

    virtual ~AA()
    {
        if (!friends.size())
            NO_FRIENDS--;
    }

    static int friendless()
    {
        return NO_FRIENDS;
    }

    virtual bool is_shy() const = 0;

    virtual void talk() const
    {
        cout << name << ": Hej! I am " << name << endl;
    };

    AA& operator+=(AA& fr)
    {
        if (friends.size() == 0)
            NO_FRIENDS--;

        friends.push_back(&fr);

        return (*this);
    }

    AA& operator-=(string s)
    {
        if (friends.size() == 0)
            return (*this);

        for(vector<AA*>::iterator it = friends.begin();
                it != friends.end(); it++)
        {
            if ( (*it)->name == s)
            {
                friends.erase(it);
                break;
            }
        }

        if (!friends.size())
            NO_FRIENDS++;

        return (*this);
    }


protected:

    string name;

    //The component type of containers like vectors
    //must be Assignable.
    //References are not assignable
    //(you can only initialize them once when they are declared,
    //and you cannot make them reference something else later).
    //Other non-assignable types are also not allowed
    //as components of containers,
    //e.g. vector<const int> is not allowed.
    // vector<AA&> friends; -- DOES NOT COMPILE
    vector<AA*> friends;

    static int NO_FRIENDS;
};

int AA::NO_FRIENDS = 0;



/************************
* Class BB definition   *
*************************/


class BB : public AA
{
public:

    BB(string s, bool f = false) : AA(s), shy(f)
    { };

    virtual bool is_shy() const
    {
        return shy;
    };

    virtual void talk() const
    {
        AA::talk();

        if (!shy)
        {
            cout << name << ": I have " << friends.size()
                 << " friends!" << endl;

            if (friends.size())
                cout << name << "'s friends ..." << endl;

            for(int i = 0; i < friends.size(); i++)
                friends[i]->talk();
        }
    };


protected:
    const bool shy;
};



/************************
* Class CC definition   *
*************************/

class CC : public AA
{
public:

    CC(string s) : AA(s)
    { };

    virtual bool is_shy() const
    {
        return false;
    };
};



/*********************
* Main function      *
**********************/


int main()
{
    const int MAX = 6;

    AA* characters[MAX];
    int howMany = 4;

    BB b1("TinTin");
    BB b2("Donald");
    const BB b3("Garfield", true);

    characters[0] = &b1;
    characters[1] = new BB("Golan", true); //deallocate explicitly
    characters[2] = new CC("Simpson"); //deallocate explicitly
    characters[3] = &b2;

    cout << "\n** All characters talk..." << endl;
    for(int i= 0; i < howMany; i++)
        characters[i]->talk();

    cout << "\n** Tintin gets friends..." << endl;
    b1 += *characters[1];
    b1 += *characters[2];
    b1 += *characters[3];

    b1.talk();

    cout << "\n** Donald gets a friend..." << endl;
    b2 += *characters[1];

    b1.talk();

    cout << "\nThere are " << AA::friendless()
         << " characters without friends!!" << endl;

    string name = "Golan" ;

    cout << "\n** Donald looses his friend..." << endl;
    b2 -= name;

    cout << "\nThere are " << AA::friendless()
         << " characters without friends!!" << endl;

    if (b3.is_shy())
        cout << "\nGarfiled is shy!!" << endl;

    return 0;
}
