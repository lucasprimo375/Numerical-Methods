#include <iostream>

double* get_limits() {
	double lower_limit = 1;
	double higher_limit = 0;

	while(higher_limit < lower_limit) {
		std::cout << "Input lower limit" << std::endl
					<< "Your choice: ";
		std::cin >> lower_limit;

		std::cout << "Input higher limit" << std::endl
					<< "Your choice: ";
		std::cin >> higher_limit;
	}

	double* limits = new double[2];
	limits[0] = lower_limit;
	limits[1] = higher_limit;

	return limits;
}

void execute() {
	double* limits = get_limits();

	std::cout << "The result is: " << std::endl;
}