#include "solve.h"
#include "math.h"

#define C       coeffs->arr[0]
#define B       coeffs->arr[1]
#define A       coeffs->arr[2]
#define X1      &(roots->arr[0])
#define X1_FIN  &(roots->is_finite[0])
#define X2      &(roots->arr[1])
#define X2_FIN  &(roots->is_finite[1])
#define N_ROOTS &(roots->n_roots)

int cmp(double a, double b)
{
    double diff = a - b;

    if(fabs(diff) < PRECISION)
        return 0;
    if(diff < 0)
        return -1;

    return 1;
}

double discriminant(const Equation_coeffs* coeffs)
{
    return B * B - 4 * A * C;
}

void solve_lin_eq(double a, double b, double* root)
{
    assert(root);

    if(cmp(a, 0) == 0)
    {
        if(cmp(b, 0) < 0)
            *root = INFINITY;
        else if (cmp(b, 0) > 0)
            *root = -INFINITY;
        else if (cmp(b, 0) == 0)
            *root = NAN;

        return;
    }
    if(cmp(b, 0) == 0)
    {
        *root = 0;

        return;
    }

    *root = -b / a;

    return;
}

void solve_quadr_eq(const Equation_coeffs* coeffs, Equation_roots* roots)
{
    assert(coeffs && roots);

    if(cmp(A, 0) == 0)
    {
        if(cmp(B, 0) == 0)
        {
            if(cmp(C, 0) == 0)
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
            solve_lin_eq(B, C, X1);
            *X1_FIN = isfinite(*X1);
            *N_ROOTS = NumOfRts::ONE;


            return;
        }
    }

    if(cmp(C, 0) == 0)
    {
        *X1 = 0;

        solve_lin_eq(A, B, X2);

        if(cmp(*X1, *X2) == 0)
        {
            *N_ROOTS = NumOfRts::ONE;

            return;
        }

        *X1_FIN = isfinite(*X1);
        *X2_FIN = isfinite(*X2);
        *N_ROOTS = NumOfRts::TWO;

        return;
    }

    double discr = discriminant(coeffs);

    if(cmp(discr, 0) < 0)
    {
        *N_ROOTS = NumOfRts::ZERO;

        return;
    }
    if(cmp(discr, 0) == 0)
    {
        solve_lin_eq(2 * A, B, X1);
        *X1_FIN = isfinite(*X1);
        *N_ROOTS = NumOfRts::ONE;

        return;
    }

    solve_lin_eq(2 * A, B - sqrt(discr), X1);
    solve_lin_eq(2 * A, B + sqrt(discr), X2);
    *N_ROOTS = NumOfRts::TWO;

    *X1_FIN = isfinite(*X1);
    *X2_FIN = isfinite(*X2);

    return;
}

#undef A;
#undef B;
#undef C;
#undef X1;
#undef X2;
#undef X1_FIN;
#undef X2_FIN;
#undef N_ROOTS;
