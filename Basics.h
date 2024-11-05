#pragma once
#include <iostream>
#include <cstdio>

class Conditionals
{
public:
	static std::string determine_parity(int num);
};

namespace print
{
	void determine_parity();
	void swap_two_numbers();
}

class VariablesAndDataTypes
{
public:
	static void swap_two_numbers(int& a, int& b, bool mutateOriginal = true);

private:
	static void swap_helper(int& a, int& b);
};
