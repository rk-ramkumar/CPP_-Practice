#include "VariablesAndDataTypes.h"
#include <iostream>


int main() {
	VariablesAndDataTypes::swap_two_numbers(10, 20);
	return 0;
}

void VariablesAndDataTypes::swap_two_numbers(int a, int b)
{
	std::cout << "Before Swap a: " << a << " and b: " << b << "\n";
	int temp;
	temp = a;
	a = b;
	b = temp;
	std::cout << "After Swap a: " << a << " and b: " << b << "\n";

}
