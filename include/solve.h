/** \file

    \brief Contains calculating functions
*/

#ifndef SOLVE_H
#define SOLVE_H

#include <math.h>
#include <assert.h>
#include "Equation.h"
#include "UI.h"

/** \brief          Compares two doubles with preset precision

    \details        Precision is stored in PRECISION constant

    \param [in] a   First double argument
    \param [in] b   Second double argument

    \return         Returns 1 if a > b, 0 if a == b, -1 if a < b

*/
int cmp(double a, double b);

/** \brief          Discriminant of quadratic equation

    \details        Computational formula: b * b - 4 * a * c

    \param [in] a   First coefficient of quadratic equation
    \param [in] b   Second coefficient of quadratic equation
    \param [in] c   Third coefficient of quadratic equation

    \return         Returns discriminant value
*/
double discriminant(double a, double b, double c);

/** \brief          Solves linear equation ax+b=0

    \warning        Uses cmp(...), dividing by zero sets root to INFINITY or -INFINITY, 0/0 sets root to NAN

    \param [in]     a       First coefficient of linear equation
    \param [in]     b       Second coefficient of linear equation
    \param [out]    root    Used to return result
*/
void solve_lin_eq(double a, double b, double* root);

/** \brief          Solves quadratic equation

    \warning        Uses solve_lin_eq(...), dividing by zero sets root to INFINITY or -INFINITY, 0/0 sets root to NAN

    \param [in]     coeffs  Provides reading coeffs of equation
    \param [out]    roots   Provides writing roots of equation and their number
*/
void solve_quadr_eq(const Equation_coeffs* coeffs, Equation_roots* roots);

#endif // SOLVE_H
