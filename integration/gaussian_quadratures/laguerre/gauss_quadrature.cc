#include "gauss_quadrature.h"
#include <iostream>

double GaussQuadrature::estimate(double (*f)(double)) {
	double I = 0;

	for(int i = 0; i < degree; i++) {
		std::cout << I << std::endl;
		I += f(roots[i]) * weights[i];
	}

	return I;
}
