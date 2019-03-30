#include <iostream>
#include <iomanip>
#include <string>

#include "user_input.h"
#include "gauss_quadrature.h"
#include "degree_two.h"
#include "degree_three.h"
#include "degree_four.h"

Degree get_user_choice() {
	int choice = -1;
	while((choice < 2) || (choice > 4)) {
		std::cout << "input degree choice (2-Two, 3-Three, 4-Four)" << std::endl
					<< "Your choice: " ;
		std::cin >> choice;
	}

	if(choice == 2) return kDegreeTwo;

	if(choice == 3) return kDegreeThree;

	return kDegreeFour;
}

static double f(double x) {
	return x*x*x*x;
}

void calculate_integral() {
    std::cout << std::setprecision(6) << std::fixed;

	Degree degree_choice = get_user_choice();

	GaussQuadrature* gauss_quadrature;
	double result;
    double* limits = get_limits();

	switch(degree_choice){
		case kDegreeTwo:
			gauss_quadrature = new DegreeTwo(limits[0], limits[1]);
			break;
		case kDegreeThree:
            gauss_quadrature = new DegreeThree(limits[0], limits[1]);
			break;
		case kDegreeFour:
            gauss_quadrature = new DegreeFour(limits[0], limits[1]);
			break;
	}

	result = gauss_quadrature->estimate(&f);

	std::cout << "result: " << result << std::endl;

    delete gauss_quadrature;
    delete[] limits;
}

double get_limit(std::string message) {
    double limit;

    std::cout << "input " << message << " limit" << std::endl
                << "Your choice: ";
    std::cin >> limit;
    return limit;
}

double* get_limits() {
    std::string lower_limit_message = "lower";
    std::string higher_limit_message = "higher";

    double lower_limit = 1;
    double higher_limit = 0;

    while(lower_limit > higher_limit){
        lower_limit = get_limit(lower_limit_message);
        higher_limit = get_limit(higher_limit_message);
    }

    double* limits = new double[2];
    limits[0] = lower_limit;
    limits[1] = higher_limit;

    return limits;
}