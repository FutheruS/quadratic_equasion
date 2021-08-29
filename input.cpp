///\file
#include "input_output.h"

/// Reads input until newline
void clean_input(FILE* const infile_ptr)
{
    while(getc(infile_ptr) != '\n')
        ;
}

/** \brief Reads line
    \details Reads line, skips all whitespaces
    \param [in] infile_ptr FILE* pointer to input
    \param [out] line Pointer to target charachter array
    \param maxline Max amount of charachters to read
    \return Amount of read charachters
*/
size_t get_line(FILE* const infile_ptr, char line[], const size_t maxline)
{
    assert(infile_ptr);
    assert(line);

    size_t i = 0;
    while(i < maxline - 1)
    {
        char c = getc(infile_ptr);

        if(c == '\n' || c == EOF)
            break;

        if(!isspace(c))
        {
            line[i] = c;
            i++;
        }
    }
    line[i] = '\0';

    return i;
}

/** \brief Reads coefficients of equation
    \details Requested format: (double) (double) (double)
    \param [in] ifile_ptr FILE* pointer to input
    \param [out] coeffs Provides writing coeffs of equation
    \return Returns true if succeed and false otherwise
*/
bool get_coeffs(FILE* const infile_ptr, Equation_coeffs* coeffs)
{
    assert(infile_ptr);
    assert(coeffs);

    for(int i = coeffs->n_coeffs - 1; i >= 0; i--)
    {
        if(fscanf(infile_ptr, "%lf", &(coeffs->arr[i])) != 1)
        {
            clean_input(infile_ptr);

            return false;
        }
    }

    if(getc(infile_ptr) != '\n')
    {
        clean_input(infile_ptr);

        return false;
    }

    return true;
}
