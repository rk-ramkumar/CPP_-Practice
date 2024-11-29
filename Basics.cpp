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
};

bool Loops::is_prime(int n) // Trial Division Method
{
	if (n <= 1) return false;
	for (size_t i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

std::vector<int> Loops::get_prime_numbers(int n)
{ 
	// Using Sieve of Eratosthenes Algorithm
	std::vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++)
	{
		if (is_prime[i])
		{
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
	std::vector<int> primes;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
		}
	}


	return primes;
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

void print::prime_numbers(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d is %s \n", i, (Loops::is_prime(i)) ? "a prime number": "not a prime number");
	}
	std::cout << "Prime numbers up to " << n << ":";
	for (int prime : Loops::get_prime_numbers(n)) {
		std::cout << prime << " ";
	}
}

void print::find_min_and_max()
{
	std::vector<int> arr = { 12, 7, 15, 3, 10 };
	std::cout << "Array: ";
	for (int num : arr) {
		std::cout << num << " ";
	}
	std::cout << "\n";
	std::cout << "Using custom function: \n";
	std::map<std::string, int> res = Arrays::get_min_and_max(arr);
	std::cout << "Minimum: " << res["min"] << "\n";
	std::cout << "Maximum: " << res["max"] << "\n";
	std::cout << "Using build-in function: \n";
	std::cout << "Minimum: " << *std::min_element(arr.begin(), arr.end()) << "\n";
	std::cout << "Maximum: " << *std::max_element(arr.begin(), arr.end()) << "\n";
}

void print::calc_factorial()
{
	std::cout << factorial(5) << "\n";
}

void print::dm_sum_of_elements()
{
	int n;
	std::cout << "Enter the size of an array: ";
	std::cin >> n;
	std::cout << "Size of an array is: " << n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		int num;
		std::cout << "Enter " << i + 1 << " item value: ";
		std::cin >> num;
		arr[i] = num;
	}
	std::cout << "Sum of the elements is: " << sum(arr, n);
	delete[] arr;
}

std::map<std::string, int> Arrays::get_min_and_max(std::vector<int> arr)
{
	std::map<std::string, int> result;
	result["min"] = arr[0];
	result["max"] = arr[0];
	for (int num : arr)
	{
		if (num > result["max"]) {
			result["max"]= num;
		}
		if (num < result["min"])
		{
			result["min"] = num;
		}
	}
	
	return result;
}

int factorial(int n) {
	if (n < 0) {
		throw std::invalid_argument("Factorial is not defined for negative numbers.");
	}

	if (n <= 1) {
		return 1;
	}

	return n * factorial(n - 1);
}

int sum(int* arr, int size)
{
	int res = 0;
	for (int i=0; i < size; i++)
	{
		res += arr[i];
	}
	return res;
}
