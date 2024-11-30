#include "Main.h"
#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

int main()
{
	print::swap_two_numbers();
	print::determine_parity();
	print::prime_numbers(10);
	print::find_min_and_max();
	print::calc_factorial();
	print::dm_sum_of_elements();

	Car myCar(50);
	printf("Current speed: %d\n", myCar.getSpeed());
	myCar.accelerate(30);
	printf("Current speed after apply accelerate of 30: %d\n", myCar.getSpeed());
	myCar.brake(35);
	printf("Current speed after apply brake of 35: %d\n", myCar.getSpeed());

	ofstream outFile("output.txt");

	if (!outFile)
	{
		cout << "Error opening file for writing \n";
		return 1;
	}
	
	outFile << "Hello world";
	outFile.close();
	cout << "Data written to output.txt successfully!\n";

	ifstream inFile("output.txt");

	if (!inFile) {
		cout << "Error opening file for reading!" << endl;
		return 1;
	}

	string line;

	while (getline(inFile, line)) {
		cout << line << endl;
	}

	inFile.close();

	return 0;
}