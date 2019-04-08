#ifndef GAUSS_QUADRATURE_H
#define GAUSS_QUADRATURE_H

class GaussQuadrature {
public:
	double estimate(double (*f)(double));
protected:
	int degree;
	double* weights;
	double* roots;
};

#endif
