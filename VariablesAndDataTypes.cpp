#include "VariablesAndDataTypes.h"
#include <iostream>
#include <cstdio>

int main() {
	int a = 10;
	int b = 20;
	VariablesAndDataTypes::swap_two_numbers(a, b, false);
	std::cout << "A" << a << "B" << b << "\n";
	VariablesAndDataTypes::swap_two_numbers(a, b);
	std::cout << "A" << a << "B" << b << "\n";
	return 0;
}

void VariablesAndDataTypes::swap_two_numbers(int &a, int &b, bool mutateOriginal)
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
	int temp;
	temp = a;
	a = b;
	b = temp;
	std::cout << "After Swap a: " << a << " and b: " << b << "\n";
}