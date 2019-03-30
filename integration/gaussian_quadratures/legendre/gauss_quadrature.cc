#include "gauss_quadrature.h"

GaussQuadrature::GaussQuadrature(double a, double b) {
	this->a = a;
	this->b = b;
}

double GaussQuadrature::estimate(double (*f)(double)) {
	double I = 0;

	for(int i = 0; i < degree; i++) {
		I += f(x_s(roots[i])) * weights[i];
	}

	return ((b-a)/2)*I;
}

double GaussQuadrature::x_s(double s) {
	return (a+b)/2 + s*(b-a)/2;
}
