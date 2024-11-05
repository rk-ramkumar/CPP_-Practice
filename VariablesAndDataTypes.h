#pragma once
class VariablesAndDataTypes
{
public:
	// swap two numbers
	static void swap_two_numbers(int &a, int &b, bool mutateOriginal = true);

private:
	static void swap_helper(int& a, int& b);
};

namespace print {
	class Fn 
	{
		public:
			static void swap_two_numbers();
	};
};

void fn();