#include <iostream>
#include <iomanip>
#include <string>

#include "user_input.h"
#include "chebyshev.h"

int get_user_choice() {
	int choice = -1;
	
	while( choice <= 0 ) {
		std::cout << "Input degree choice" << std::endl
					<< "Your choice: " ;
		std::cin >> choice;
	}

	return choice;
}

static double f(double x) {
	return x*x;
}

void calculate_integral() {
    std::cout << std::setprecision(6) << std::fixed;

	int degree_choice = get_user_choice();

	Chebyshev chebyshev( degree_choice );
	double result;

	result = chebyshev.estimate(&f);

	std::cout << std::setprecision(22);

	std::cout << "result: " << result << std::endl;
}