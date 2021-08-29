///\file
#include "solve.h"

#define C coeffs->arr[0]
#define B coeffs->arr[1]
#define A coeffs->arr[2]
#define X1 &(roots->arr[0])
#define X2 &(roots->arr[1])
#define N_ROOTS &(roots->n_roots)

/// Discriminant of quadratic equation
double discriminant(const Equation_coeffs* coeffs)
{
    return B * B - 4 * A * C;
}

/** \brief Solves linear equation ax+b=0
    \return Returns root.
            If a == 0 && b == 0 returns NAN
            If a == 0 && b != 0 returns INFINITY or -INFINITY (depending on sign of b)
*/
double solve_lin_eq(double a, double b)
{
    if(a == 0)
        return (b < 0) ? INFINITY : (b > 0) ? -INFINITY : NAN;
    return -b / a;
}

/** \brief Solves quadratic equation
    \param coeffs Provides reading coeffs of equation
    \param roots Provides writing roots of equation and their number
    \warning Uses macros in solve.cpp
*/
void solve_quadr_eq(const Equation_coeffs* coeffs, Equation_roots* roots)
{
    assert(coeffs && roots);


    if(A == 0)
    {
        if(B == 0)
        {
            if(C == 0)
            {
                *N_ROOTS = NumOfRts::INF;

                return;
            }
            else
            {
                *N_ROOTS = NumOfRts::ZERO;

                return;
            }
        }
        else
        {
            *X1 = solve_lin_eq(B, C);
            *N_ROOTS = NumOfRts::ONE;

            return;
        }
    }

    if(C == 0)
    {
        *X1 = 0;
        *X2 = solve_lin_eq(A, B);
        *N_ROOTS = NumOfRts::TWO;
        return;
    }

    double discr = discriminant(coeffs);

    if(discr < 0)
    {
        *N_ROOTS = NumOfRts::ZERO;

        return;
    }
    if(discr == 0)
    {
        *X1 = -B / (2 * A);
        *N_ROOTS = NumOfRts::ONE;

        return;
    }

    *X1 = (-B + sqrt(discr)) / (2 * A);
    *X2 = (-B - sqrt(discr)) / (2 * A);
    *N_ROOTS = NumOfRts::TWO;

    return;
}

#undef A;
#undef B;
#undef C;
#undef X1;
#undef X2;
