/** \file
    \brief Contains basic structs of equation
    \authors FutheruS
    \version 0.1
    \date 09/01/2021
*/
#ifndef EQUATION_H
#define EQUATION_H

#include <stddef.h>
/** \brief Amount of coefficients in equation
    \warning Only COEFFS_AMOUNT == 3 is valid
*/
const size_t COEFFS_AMOUNT = 3;

/// \brief Amount of roots in equation
const size_t ROOTS_AMOUNT = COEFFS_AMOUNT - 1;

enum NumOfRts {
    ZERO = 0,
    ONE,
    TWO,
    INF
};

/// Stores coeffs and their amount
struct Equation_coeffs
{
    size_t n_coeffs = COEFFS_AMOUNT;
    double arr[COEFFS_AMOUNT] = {0};
};

/// Stores roots and their amount
struct Equation_roots
{
    NumOfRts n_roots = NumOfRts::ZERO;
    bool is_finite[ROOTS_AMOUNT] = {0};
    double arr[ROOTS_AMOUNT] = {0};
};

#endif // EQUATION_H
