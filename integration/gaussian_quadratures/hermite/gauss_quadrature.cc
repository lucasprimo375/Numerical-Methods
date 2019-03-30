#include "gauss_quadrature.h"

double GaussQuadrature::estimate(double (*f)(double)) {
	double I = 0;

	for(int i = 0; i < degree; i++) {
		I += f(roots[i]) * weights[i];
	}

	return I;
}
