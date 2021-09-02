#include "UI.h"

int main()
{
    FILE* const infile_ptr = stdin;
    FILE* const outfile_ptr = stdout;

    if(infile_ptr == nullptr)
    {
        printf("Error: input file cannot be opened");
        return 0;
    }
    if(outfile_ptr == nullptr)
    {
        printf("Error: output file cannot be opened");
        return 0;
    }
    quadr_eq_client(infile_ptr, outfile_ptr);

    return 0;
}
