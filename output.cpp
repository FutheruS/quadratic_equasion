#include "input_output.h"

void print(FILE* const outfile_ptr, MsgType param)
{
    switch(param)
    {
    case MsgType::BAD_CMD:
    {
        fprintf(outfile_ptr, QUADR_EQ_BAD_CMD);
        break;
    }
    case MsgType::BAD_COEFF:
    {
        fprintf(outfile_ptr, QUADR_EQ_BAD_COEFF);
        break;
    }
    case MsgType::BUFF_OVRFLW:
    {
        fprintf(outfile_ptr, BUFFER_OVERFLOW);
        break;
    }
    case MsgType::HELP:
    {
        fprintf(outfile_ptr, QUADR_EQ_HELP);
        break;
    }
    case MsgType::INTRO:
    {
        fprintf(outfile_ptr, QUADR_EQ_INTRO);
        break;
    }
    case MsgType::PRMPT:
    {
        fprintf(outfile_ptr, PROMPT);
        break;
    }
    case MsgType::PRMPT_COEFF:
    {
        fprintf(outfile_ptr, QUADR_EQ_PROMPT_COEFFS);
        break;
    }
    case MsgType::NOT_FINITE_COEFF:
    {
        fprintf(outfile_ptr, QUADR_EQ_NOT_FINITE_COEFF);
        break;
    }
    }
}

void print_roots(FILE* const outfile_ptr, const Equation_roots* roots)
{
    assert(roots);

    NumOfRts n_roots = roots->n_roots;

    const double x1 = roots->arr[0];
    const double x2 = roots->arr[1];
    const bool x1_fin = roots->is_finite[0];
    const bool x2_fin = roots->is_finite[1];

    if(n_roots == NumOfRts::INF)
        fprintf(outfile_ptr, "Infinte amount of roots \n");
    else if(n_roots == NumOfRts::ZERO)
        fprintf(outfile_ptr, "No real roots \n");
    else if(n_roots == NumOfRts::ONE)
    {
        if(x1_fin)
            fprintf(outfile_ptr, "One root: %lf\n", x1);
        else
            fprintf(outfile_ptr, "No real roots\n");
    }
    else if(n_roots == NumOfRts::TWO)
    {
        if(x1_fin && x2_fin)
            fprintf(outfile_ptr, "Two roots: x1 = %lf, x2 = %lf\n", x1, x2);
        else if(!x1_fin && !x2_fin)
            fprintf(outfile_ptr, "No real roots\n");
        else if(x1_fin)
            fprintf(outfile_ptr, "One root: %lf\n", x1);
        else if(x2_fin)
            fprintf(outfile_ptr, "One root: %lf\n", x2);
    }

}
