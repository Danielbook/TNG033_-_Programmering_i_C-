#ifndef EXP_H
#define EXP_H

#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

//Base class
//går alltid igång först, slutar sist
class Expression{
public:

    virtual ~Expression() { }; //deletar objekt

    virtual double eval(double x) const = 0; //finns en likadana funktioner i log & poly (dotterklass, derived class),
    bool isRoot(double x) const;
    friend ostream& operator<<(ostream& os, const Expression& E);
    virtual Expression* clone() const = 0;

protected:
    virtual void print(ostream &os) const = 0; //virtual - en funktion för alla klasser

};

#endif
