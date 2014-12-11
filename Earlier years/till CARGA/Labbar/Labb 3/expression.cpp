#include <math.h>
#include "expression.h"

using namespace std;

//ser om givet v�rde �r en l�sning f�r n�got x
bool Expression::isRoot(double x) const
{
    const double E = 1.0e-5;
    return (fabs(eval(x) - 0.0) < E);
}

//skriver till fil
ostream& operator<<(ostream& os, const Expression& E)
{     
    E.print(os);//kallar p� print i log eller poly
    return os;
}
