/*********************************************************
* Class Expression member functions implementation       *
* TNG033: Lab 3                                          *
**********************************************************/

#include "expression.h"
#include <cmath>

using namespace std;

bool Expression::isRoot(double v) const
{
    if(fabs( (*this)(v) ) < EPSILON)
    {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const Expression& E)
{
    E.print(os); //Call print function in subclasses
    return os;
}
