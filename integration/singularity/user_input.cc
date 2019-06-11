#include <iostream>

#include "exp_method.h"
#include "simple_exp.h"
#include "double_exp.h"

double* get_limits() {
	double lower_limit = 1;
	double higher_limit = 0;

	while(higher_limit < lower_limit) {
		std::cout << "Input lower limit" << std::endl
					<< "Suggestion: use 0" << std::endl
					<< "Your choice: ";
		std::cin >> lower_limit;

		std::cout << "Input higher limit" << std::endl
					<< "Suggestion: use 1" << std::endl
					<< "Your choice: ";
		std::cin >> higher_limit;
	}

	double* limits = new double[2];
	limits[0] = lower_limit;
	limits[1] = higher_limit;

	return limits;
}

double get_precision(std::string message, double suggestion) {
	double precision = 0;

	while( precision <= 0 ) {
		std::cout << "Input " << message << " precision: " << std::endl << "Suggestion: use " << suggestion << std::endl << ">> ";

		std::cin >> precision;
	}

	return precision;
}

double* get_precisions(){
	double precision_1 = get_precision("exponentiation", 0.01);

	double precision_2 = get_precision("closed, degree 2 newton-cotes", 0.0001);

	double* precisions = new double[2];

	precisions[0] = precision_1;
	precisions[1] = precision_2;

	return precisions;
}

void execute() {
	double* limits = get_limits();
	double* precisions = get_precisions();

	std::cout << "Running Simple Exponentiation Method" << std::endl << std::endl;

	ExpMethod* exp_method = new SimpleExp(limits[0], limits[1]);

	std::cout << std::endl << "The result for Simple Exponentiation is: " << exp_method->execute(precisions[0], precisions[1]) << std::endl << std::endl;


	std::cout << "Running Double Exponentiation Method" << std::endl << std::endl;

	exp_method = new DoubleExp(limits[0], limits[1]);

	std::cout << std::endl << std::endl << "The result for Double Exponentiation is: " << exp_method->execute(precisions[0], precisions[1]) << std::endl;
}