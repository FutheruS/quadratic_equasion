#include "tests.h"

#define C       coeffs->arr[0]
#define B       coeffs->arr[1]
#define A       coeffs->arr[2]
#define X1      &(roots->arr[0])
#define X1_FIN  &(roots->is_finite[0])
#define X2      &(roots->arr[1])
#define X2_FIN  &(roots->is_finite[1])
#define N_ROOTS &(roots->n_roots)

bool check_roots(const Equation_coeffs* coeffs, const Equation_roots* roots)
{
    assert(coeffs && roots);

    if(roots->n_roots == NumOfRts::ONE)
    {
        if(X1_FIN)
        {
            double result1 = A * (*X1) * (*X1) + B * (*X1) + C;

            if(cmp(result1, 0) != 0)
                return false;
        }
    }

    if(roots->n_roots == NumOfRts::TWO)
    {
        if(X1_FIN)
        {
            double result1 = A * (*X1) * (*X1) + B * (*X1) + C;

            if(cmp(result1, 0) != 0)
                return false;
        }

        if(X2_FIN)
        {
            double result2 = A * (*X2) * (*X2) + B * (*X2) + C;

            if(cmp(result2, 0) != 0)
                return false;

        }
    }

    return true;
}

void print_solution_error(FILE* const outfile_ptr, const Equation_coeffs* coeffs, const Equation_roots* roots)
{
    fprintf(outfile_ptr, "Solution error\n"
                         "Equation: %lfx2+%lfx+%lf\n",
                         coeffs->arr[2], coeffs->arr[1], coeffs->arr[0]);
}

#undef A
#undef B
#undef C
#undef X1
#undef X2
#undef X1_FIN
#undef X2_FIN
#undef N_ROOTS
