#include <iostream>

#include "user_input.h"
#include "gauss_quadrature.h"
#include "degree_two.h"

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
	return x*x;
}

void calculate_integral() {
	Degree degree_choice = get_user_choice();
	
	GaussQuadrature* gauss_quadrature;
	double result;
	
	switch(degree_choice){
		case kDegreeTwo:
			gauss_quadrature = new DegreeTwo(1, 2);
			break;
		case kDegreeThree:
			break;
		case kDegreeFour:
			break;
	}
	
	result = gauss_quadrature->estimate(&f);
	
	std::cout << "result: " << result << std::endl;
}
