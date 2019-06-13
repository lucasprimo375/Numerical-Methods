#include <iostream>

#include "user_input.h"

double* get_integration_limits() {
	double a = 1;
	double b = 0;

	while( a > b ) {
		std::cout << std::endl << "Input integration limits" << std::endl;

		std::cout << std::endl << "Input lower limit" << std::endl;
		std::cout << ">> ";
		std::cin >> a;

		std::cout << std::endl << "Input higher limit" << std::endl;
		std::cout << ">> ";
		std::cin >> b;
	}

	double* limits = new double[2];

	limits[0] = a;
	limits[1] = b;

	return limits;
}

double get_precision() {
	double precision = -1;

	while( precision <= 0 ) {
		std::cout << std::endl << "Input the precision" << std::endl;

		std::cout << ">> ";

		std::cin >> precision;
	}

	return precision;
}