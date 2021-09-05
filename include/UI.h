/** \file

    \brief Contains base constants, includes low-level headers of application
*/

#ifndef UI_H
#define UI_H

#include <string.h>
#include "solve.h"
#include "input_output.h"

//#define TESTS
#ifdef TESTS
    #include "tests.h"
#endif

const double PRECISION          = 1.0e-6;
const size_t MAX_NUMBER_SIZE    = 17;
const size_t MAX_BUFFER_SIZE    = MAX_NUMBER_SIZE + 1;
const size_t MAX_CMD_LEN        = 100;

/** \brief CUI for Quadratic equation solver

    \param infile_ptr  FILE* pointer to input file
    \param outfile_ptr FILE* pointer to output file
*/
void quadr_eq_client(FILE* const infile_ptr, FILE* const outfile_ptr);

#endif // UI_H
