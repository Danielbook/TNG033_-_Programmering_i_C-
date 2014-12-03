/*********************************************************
* Class Expression member functions implementation       *
* TNG033: Lab 3                                          *
**********************************************************/

#include "expression.h"
#include <cmath>

using namespace std;

bool Expression::isRoot(double v) const
{
    const double EPSILON = 1.0e-5;
    return(fabs( (*this)(v) - 0.0) < EPSILON);
}

ostream& operator<<(ostream& os, const Expression& E)
{
    E.print(os); //Call print function in subclasses
    return os;
}
