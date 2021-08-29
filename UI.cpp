///\file
#include "UI.h"


const int MAXCOMMAND = 100;

void quadr_eq_client(FILE* const infile_ptr, FILE* const outfile_ptr)
{
    assert(outfile_ptr && infile_ptr);

    print(outfile_ptr, "intro");

    while(true)
    {
        prompt(outfile_ptr);

        char command[MAXCOMMAND];
        get_line(infile_ptr, command, MAXCOMMAND);

        if(strcmp(command, "s") == 0 || strcmp(command, "solve") == 0)
        {
            prompt_coeffs(outfile_ptr);

            Equation_coeffs coeffs;
            Equation_roots roots;

            if(!get_coeffs(infile_ptr, &coeffs))
            {
                print(outfile_ptr, "bad_coeff");

                continue;
            }

            solve_quadr_eq(&coeffs, &roots);

            print_roots(outfile_ptr, &roots);
        }
        else if(strcmp(command, "q") == 0 || strcmp(command, "quit") == 0)
        {
            break;
        }
        else if(strcmp(command, "h") == 0 || strcmp(command, "help") == 0)
        {
            print(outfile_ptr, "help");
        }
        else
        {
            print(outfile_ptr, "bad_cmd");
        }
    }
}
