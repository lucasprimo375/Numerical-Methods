#include <cmath>
#include <iostream>

#include "chebyshev.h"

#define _USE_MATH_DEFINES

Chebyshev::Chebyshev(int degree) {
	this->degree = degree;

	weights = new double[degree];

	for( int i = 0; i < degree; i++ ) {
		weights[i] = M_PI/degree;
	}
}

double Chebyshev::estimate(double (*f)(double)) {
	double I = 0;

	for(int i = 0; i < degree; i++) {
		I += f(x_s(i+1)) * weights[i];
	}

	return I;
}

double Chebyshev::x_s(int k){
	return std::cos(((k - 1.0/2)*M_PI)/degree);
}
