#include "Basics.h"

void VariablesAndDataTypes::swap_two_numbers(int& a, int& b, bool mutateOriginal)
{
	if (mutateOriginal)
	{
		swap_helper(a, b);
	}
	else
	{
		int tempA = a;
		int tempB = b;
		swap_helper(tempA, tempB);
	}
}

void VariablesAndDataTypes::swap_helper(int& a, int& b)
{
	std::cout << "Before Swap a: " << a << " and b: " << b << "\n";
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	std::cout << "After Swap a: " << a << " and b: " << b << "\n";
}

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

void print::swap_two_numbers()
{
	int a = 10;
	int b = 20;
	VariablesAndDataTypes::swap_two_numbers(a, b, false);
	std::cout << "A " << a << "B " << b << "\n";
	VariablesAndDataTypes::swap_two_numbers(a, b);
	printf("A: %d, B: %d \n", a, b);
}
