/** \file

    \brief Contains input/output functions
*/

#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include "Equation.h"
#include "UI.h"

const char QUADR_EQ_INTRO[]             = " _________________________\n"
                                          "\/                         \\\n"
                                          "|Quadratic equation solver|\n"
                                          "\\_________________________\/\n"
                                          "\n"
                                          "Enter 'h' or 'help' for help\n";

const char PROMPT[]                     = ">";
const char QUADR_EQ_PROMPT_COEFFS[]     = "Enter three cooficients: ";
const char QUADR_EQ_HELP[]              = "Enter 's' or 'solve' to solve equation, enter 'q' or 'quit' to quit\n";
const char QUADR_EQ_BAD_CMD[]           = "Unknown command\n"
                                          "(enter 'q' to close the program, 'h' to open reference)\n";

const char QUADR_EQ_BAD_COEFF[]         = "Wrong format of coefficients\n"
                                          "Example: 1 2 1\n"
                                          "(goes for ax2 + bx + c = 0, a = 1, b = 2, c = 1)\n";

const char QUADR_EQ_NOT_FINITE_COEFF[]  = "Too large number as coefficient\n";
const char BUFFER_OVERFLOW[]            = "Buffer overflow: number contains too many symbols\n"
                                          "(try using exponential form)\n";

/// Used to connect input and output
enum MsgType
{
    NOMSG = 1,              /// no output
    INTRO,                  /// print intro
    PRMPT,                  /// print prompt
    PRMPT_COEFF,            /// prompt coeffs
    HELP,                   /// print reference
    BAD_COEFF,              /// message for bad input for coeff
    NOT_FINITE_COEFF,       /// message for double overflow in coeff
    BAD_CMD,                /// message for bad input for command
    BUFF_OVRFLW             /// message for buffer-overflowing input
};

/// Reads input until newline (including it)
void clean_input(FILE* const infile_ptr);

/** \brief      Reads line

    \details    Reads line, skips all whitespaces, cleans input till end of line (including it)

    \param [in]     infile_ptr  FILE* pointer to input file
    \param [out]    line        Pointer to target charachter array
    \param [in]     maxline     Max amount of charachters to read

    \return     Amount of read charachters
*/
size_t get_line(FILE* const infile_ptr, char line[], const size_t maxline);

/** \brief      Reads charachter sequence to buffer

    \details    Cuts whitespaces before sequence, ends reading on whitespace (excluding it), closes sequence with EOF in buffer

    \param [in]     infile_ptr  FILE* pointer to input file
    \param [out]    buf Char    array buffer
    \param [in]     maxsize     Max size of read sequence

    \return     Returns MsgType::NOMSG if succeded, MsgType::BUFF_OVRFLW if sequence is too long
*/
MsgType fscan_buf(FILE* const infile_ptr, char buf[], const size_t maxsize);

/** \brief      Reads coefficients of equation

    \details    Requested format: (double) (double) (double)

    \param [in]     ifile_ptr   FILE* pointer to input file
    \param [out]    coeffs      Provides writing coeffs of equation

    \return     Returns true if succeed and false otherwise
*/
MsgType get_coeffs(FILE* const infile_ptr, Equation_coeffs* coeffs);

/** \brief      Prints message
    \param [out]    outfile_ptr FILE* pointer to output file
    \param [out]    param       Specifies response message
*/
void print(FILE* const outfile_ptr, MsgType param);

/** \brief      Prints roots of equation
    \param [out]    outfile_ptr FILE* pointer to output file
    \param [in]     roots       Provides reading coeffs of equation
*/
void print_roots(FILE* const outfile_ptr, const Equation_roots* roots);

#endif // INPUT_OUTPUT_H
