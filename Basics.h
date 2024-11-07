#pragma once
#include <iostream>
#include <cstdio>

namespace print
{
	void determine_parity();
	void swap_two_numbers();
	void prime_numbers(int n);
};

class Conditionals
{
public:
	static std::string determine_parity(int num);
};

class VariablesAndDataTypes
{
public:
	static void swap_two_numbers(int& a, int& b, bool mutateOriginal = true);

private:
	static void swap_helper(int& a, int& b);
};

class Loops
{
public:
	static bool is_prime(int n);
	static void get_prime_numbers(int n);
};