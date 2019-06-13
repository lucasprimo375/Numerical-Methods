#include <iostream>

#include "newton_cotes.h"
#include "closed_one.h"
#include "closed_two.h"
#include "user_input.h"

int main() {
	double* limits = get_integration_limits();
	double a = limits[0];
	double b = limits[1];

	double precision = get_precision();

	std::cout << std::endl << std::endl << "Running Newton Cotes Closed Degree One" << std::endl;
	NewtonCotes* newtonCotes = new ClosedOne();
	newtonCotes->estimate(a, b, precision);

	std::cout << std::endl << std::endl << "Running Newton Cotes Closed Degree Two" << std::endl;
	newtonCotes = new ClosedTwo();
	newtonCotes->estimate(a, b, precision);

	std::cout << std::endl << std::endl << "You can check the image 'double_integration.png' to see what is being integrated." << std::endl;
	std::cout << "And you can change the functions the file 'functions.cc'." << std::endl;
	std::cout << "Then you have to recompile with 'make all' and then './main'" << std::endl;

	return 0;
}