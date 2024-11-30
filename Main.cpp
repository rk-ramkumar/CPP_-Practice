#include "Main.h"

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

	return 0;
}