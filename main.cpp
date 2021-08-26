#include <stdio.h>
#include "UI.h"

int main()
{
    intro();
    while(process_command());
    return 0;
}
