#include <cmath>
#include <iostream>

#include "gauss_quadrature.h"

#define _USE_MATH_DEFINES

double GaussQuadrature::estimate(double (*f)(double)) {
	double I = 0;

	for(int i = 0; i < degree; i++) {
		std::cout << I << std::endl;
		I += f(x_s(i+1)) * weights[i];
	}

	return I;
}

double GaussQuadrature::x_s(int k){
	return std::cos(((k - 1.0/2)*M_PI)/degree);
}
