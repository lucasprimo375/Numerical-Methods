#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

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
	return std::pow(x, 8);
}

void calculate_integral() {
    std::cout << std::setprecision(6) << std::fixed;

	Degree degree_choice = get_user_choice();

	GaussQuadrature* gauss_quadrature;
	double result;

	switch(degree_choice){
		case kDegreeTwo:
			gauss_quadrature = new DegreeTwo();
			break;
		case kDegreeThree:
            gauss_quadrature = new DegreeThree();
			break;
		case kDegreeFour:
            gauss_quadrature = new DegreeFour();
			break;
	}

	result = gauss_quadrature->estimate(&f);

	std::cout << "result: " << result << std::endl;

    delete gauss_quadrature;
}