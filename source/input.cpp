#include "input_output.h"

void clean_input(FILE* const infile_ptr)
{
    char c;
    do
    {
        c = getc(infile_ptr);
    } while (c != '\n' && c != EOF);
}

size_t get_line(FILE* const infile_ptr, char line[], const size_t maxline)
{
    assert(infile_ptr);
    assert(line);

    size_t curr_len = 0;
    while(true)
    {
        if(curr_len == maxline - 1) //check for overflow
        {
            clean_input(infile_ptr);
            break;
        }

        char ch = getc(infile_ptr);

        if(ch == '\n' || ch == EOF) //check for end of line or EOF
            break;

        if(!isspace(ch)) //skips whitespaces
        {
            line[curr_len] = ch;
            curr_len++;
        }
    }
    line[curr_len] = '\0'; //c-style string

    return curr_len;
}

MsgType fscan_buf(FILE* const infile_ptr, char buf[], const size_t maxsize)
{
    size_t i = 0;
    char c = 0;

    while(fscanf(infile_ptr, "%c", &c) && isspace(c))
        ;
    ungetc(c, infile_ptr);

    while(fscanf(infile_ptr, "%c", &c) && !isspace(c) && isdigit(c)) {
        if(i == maxsize+1)
            return MsgType::BUFF_OVRFLW;

        buf[i] = c;
        i++;
    }

    ungetc(c, infile_ptr);

    buf[i] = EOF;

    return MsgType::NOMSG;
}

MsgType get_coeffs(FILE* const infile_ptr, Equation_coeffs* coeffs)
{
    assert(infile_ptr);
    assert(coeffs);

    char buf[MAX_BUFFER_SIZE];

    for(int i = coeffs->n_coeffs - 1; i >= 0; i--) //size_t is unsigned
    {
        if(fscan_buf(infile_ptr, buf, MAX_NUMBER_SIZE) == MsgType::BUFF_OVRFLW)
        {
            clean_input(infile_ptr);

            return MsgType::BUFF_OVRFLW;
        }

        double temp_coeff = 0;

        if(sscanf(buf, "%lf", &temp_coeff) != 1)
        {
            clean_input(infile_ptr);

            return MsgType::BAD_COEFF;
        }

        if(!isfinite(temp_coeff))
        {
            clean_input(infile_ptr);

            return MsgType::NOT_FINITE_COEFF;
        }

        coeffs->arr[i] = temp_coeff;
    }

    if(getc(infile_ptr) != '\n')
    {
        clean_input(infile_ptr);

        return MsgType::BAD_COEFF;
    }

    return MsgType::NOMSG;
}
