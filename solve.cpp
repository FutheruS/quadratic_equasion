/*Solves equation, returns number of roots and sets roots to x1, x2*/

#include <math.h>
#include "solve.h"

 NumOfRts solve(double a, double b, double c, double* x1, double* x2)
{
    if(a==0) {
        if(b==0) {
            if(c==0) return NumOfRts::INF;
            else return NumOfRts::ZERO;
        }
        else {
            *x1=-c/b;
            return NumOfRts::ONE;
        }
    }
    if((b*b-4*a*c)<0) return NumOfRts::ZERO;
    if((b*b-4*a*c)==0) {
        *x1=-b/(2*a);
        return NumOfRts::ONE;
    }
    *x1=(-b+sqrt(b*b-4*a*c))/(2*a);
    *x2=(-b-sqrt(b*b-4*a*c))/(2*a);
    return NumOfRts::TWO;
}
