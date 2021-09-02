/** \file
    \brief Contains functions for testing
    \authors FutheruS
    \version 0.1
    \date 09/01/2021
*/
#ifndef TESTS_H
#define TESTS_H

#include "Equation.h"
#include "UI.h"
#include <stdio.h>

bool check_roots(const Equation_coeffs* coeffs, const Equation_roots* roots);

void print_solution_error(FILE* const outfile_ptr, const Equation_coeffs* coeffs, const Equation_roots* roots);

#endif // TESTS_H
