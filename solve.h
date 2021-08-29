///\file
#ifndef SOLVE_H
#define SOLVE_H

#include <math.h>
#include <assert.h>
#include "Equation.h"

double discriminant(double a, double b, double c);

double solve_lin_eq(double a, double b);

/*Solves equation, returns number of roots and sets roots to x1, x2*/
void solve_quadr_eq(const Equation_coeffs* coeffs, Equation_roots* roots);

#endif // SOLVE_H
