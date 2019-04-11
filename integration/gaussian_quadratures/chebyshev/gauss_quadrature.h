#ifndef GAUSS_QUADRATURE_H
#define GAUSS_QUADRATURE_H

class GaussQuadrature {
public:
	double estimate(double (*f)(double));
protected:
	double x_s(int k);

	int degree;
	double* weights;
	double* roots;
};

#endif
