///\file
#include "input_output.h"

const char QUADR_EQ_INTRO[]             = "Quadratic equation solver\n"
                                          "Enter 'h' or 'help' for help\n";

const char PROMPT[]                     = ">";
const char QUADR_EQ_PROMPT_COEFFS[]     = "Enter three cooficients: ";
const char QUADR_EQ_HELP[]              = "Enter 's' or 'solve' to solve equation, enter 'q' or 'quit' to quit\n";
const char BADINPUT_CMD[]               = "Unknown command\n"
                                          "(enter 'q' to close the program, 'h' to open reference)\n";
const char BADINPUT_COEFF[]             = "Wrong format of coefficients\n"
                                          "Example: 1 2 1\n"
                                          "(goes for ax2+bx+c=0, a=1, b=2, c=1)\n";

/** \brief Prints prompt
    \details Prompt string in PROMPT
*/
void prompt(FILE* const outfile_ptr)
{
    fprintf(outfile_ptr, PROMPT);
}

/** \brief Prints prompt for entering coefficients
    \details Prompt string in QUADR_EQ_PROMPT_COEFFS
    \param outfile_ptr FILE* pointer to output
*/
void prompt_coeffs(FILE* const outfile_ptr)
{
    fprintf(outfile_ptr, QUADR_EQ_PROMPT_COEFFS);
}

/** \brief Prints
void print(FILE* const outfile_ptr, char param[])
{
    if(strcmp(param, "bad_cmd") == 0)
        fprintf(outfile_ptr, BADINPUT_CMD);
    else if(strcmp(param, "bad_coeff") == 0)
        fprintf(outfile_ptr, BADINPUT_COEFF);
    else if(strcmp(param, "help") == 0)
        fprintf(outfile_ptr, QUADR_EQ_HELP);
    else if(strcmp(param, "intro") == 0)
        fprintf(outfile_ptr, QUADR_EQ_INTRO);
}

void print_roots(FILE* const outfile_ptr, const Equation_roots* roots)
{
    assert(roots);

    NumOfRts n_roots = roots->n_roots;

    double x1 = roots->arr[0];
    double x2 = roots->arr[1];

    if(n_roots == NumOfRts::INF)
        fprintf(outfile_ptr, "Infinte amount of roots \n");
    else if(n_roots == NumOfRts::ZERO)
        fprintf(outfile_ptr, "No real roots \n");
    else if(n_roots == NumOfRts::ONE)
        fprintf(outfile_ptr, "One root, x=%lf \n", x1);
    else if(n_roots == NumOfRts::TWO)
        fprintf(outfile_ptr, "Two roots, x1=%lf, x2=%lf \n", x1, x2);
}
