#include <stdio.h>
#include "UI.h"
#include "solve.h"

#define INTRO "Quadratic_equation solver\nEnter 'h' for help\n"
#define PROMPT ">"
#define PROMPT_EQ "Enter three cooficients: "
#define HELP "Enter 's' to set equation, enter 'q' to quit\n"
#define BADINPUT "Bad input\n"
#define TOOMANYCOOFS "Too many cooficients\n"

void intro()
{
    printf(INTRO);
}
void clean_input()
{
    while(getchar()!='\n');
}
bool get_cooficients(double& a, double& b, double& c)
{
    if(scanf("%lf", &a)==0 || scanf("%lf", &b)==0 || scanf("%lf", &c)==0) {
        printf(BADINPUT);
        clean_input();
        return false;
    }
    if(getchar()!='\n') {
        printf(TOOMANYCOOFS);
        clean_input();
        return false;
    }
    return true;
}
void print_roots(NumOfRts nor, double x1, double x2)
{
    if(nor==NumOfRts::INF) printf("Infinte amount of roots \n");
    else if(nor==NumOfRts::ZERO) printf("No real roots \n");
    else if(nor==NumOfRts::ONE) printf("One root, x=%f \n", x1);
    else if(nor==NumOfRts::TWO) printf("Two roots, x1=%f, x2=%f \n", x1, x2);
}
bool process_command()
{
    printf(PROMPT);
    int c=getchar();
    switch (c) {
    case 's': {
        printf(PROMPT_EQ);
        double a, b, c, x1, x2;
        a=b=c=x1=x2=0;
        if(!get_cooficients(a, b, c)) break;
        NumOfRts nor=solve(a, b, c, &x1, &x2);
        print_roots(nor, x1, x2);
        break;
    }
    case 'q':
        return false;
    case 'h':
        clean_input();
        printf(HELP);
        break;
    default:
        clean_input();
        printf(BADINPUT);
        break;
    }
    return true;
}
