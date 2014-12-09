#include <math.h>
#include "expression.h"

using namespace std;

//ser om givet värde är en lösning för något x
bool Expression::isRoot(double x) const
{
    //fabs räknar ut absolutbeloppet
    const double E = 1.0e-5;
    return (fabs(eval(x) - 0.00) < E);
}

//skriver till fil
ostream& operator<<(ostream& os, const Expression& E)
{
    E.print(os);//kallar på print i log eller poly
    return os;
}
