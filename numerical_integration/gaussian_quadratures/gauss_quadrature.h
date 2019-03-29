#ifndef GAUSS_QUADRATURE_H
#define GAUSS_QUADRATURE_H

class GaussQuadrature {
public:
	GaussQuadrature(double a, double b);
	double estimate(double (*f)(double));
protected:
	double x_s(double s);
	int degree;
	double a, b;
	double* weights;
	double* roots;
};

#endif
