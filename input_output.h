///\file
#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include "Equation.h"

//input block
void clean_input(FILE* const infile_ptr);

size_t get_line(FILE* const infile_ptr, char line[], const size_t maxline);

bool get_coeffs(FILE* const infile_ptr, Equation_coeffs* coeffs);

//output block
void critical_error(FILE* const outfile_ptr, char param[]);

void prompt(FILE* const outfile_ptr);

void prompt_coeffs(FILE* const outfile_ptr);

void print(FILE* const outfile_ptr, char param[]);

void print_roots(FILE* const outfile_ptr, const Equation_roots* roots);

#endif // INPUT_OUTPUT_H
