#include "Conditionals.h"

std::string Conditionals::determine_parity(int num)
{
    if (num % 2 == 0)
    {
        return "even";
    }
    else
    {
        return "odd";
    }
}

void print::determine_parity()
{
    for (size_t i = 0; i < 5; i++)
    {
        printf("Number %zu is %s \n", i, Conditionals::determine_parity(i).c_str());
    }
}
