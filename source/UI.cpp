#include "UI.h"

void quadr_eq_client(FILE* const infile_ptr, FILE* const outfile_ptr)
{
    assert(outfile_ptr && infile_ptr);

    print(outfile_ptr, MsgType::INTRO);

    while(true)
    {
        print(outfile_ptr, MsgType::PRMPT);

        char command[MAX_CMD_LEN];
        get_line(infile_ptr, command, MAX_CMD_LEN);

        if(strcmp(command, "s") == 0 || strcmp(command, "solve") == 0)
        {
            print(outfile_ptr, MsgType::PRMPT_COEFF);

            Equation_coeffs coeffs {};
            Equation_roots roots {};

            MsgType get_coeffs_res = get_coeffs(infile_ptr, &coeffs);
            if(get_coeffs_res == MsgType::BAD_COEFF)
            {
                print(outfile_ptr, MsgType::BAD_COEFF);

                continue;
            }
            if(get_coeffs_res == MsgType::BUFF_OVRFLW)
            {
                print(outfile_ptr, MsgType::BUFF_OVRFLW);

                continue;
            }
            if(get_coeffs_res == MsgType::NOT_FINITE_COEFF)
            {
                print(outfile_ptr, MsgType::NOT_FINITE_COEFF);

                continue;
            }
            solve_quadr_eq(&coeffs, &roots);

            print_roots(outfile_ptr, &roots);

        #ifdef TESTS
            if(!check_roots(&coeffs, &roots))
                print_solution_error(outfile_ptr, &coeffs, &roots);
        #endif
        }
        else if(strcmp(command, "q") == 0 || strcmp(command, "quit") == 0)
        {
            break;
        }
        else if(strcmp(command, "h") == 0 || strcmp(command, "help") == 0)
        {
            print(outfile_ptr, MsgType::HELP);
        }
        else
        {
            print(outfile_ptr, MsgType::BAD_CMD);
        }
    }
}
