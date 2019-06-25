#ifndef CHEBYSHEV_H
#define CHEBYSHEV_H

class Chebyshev {
public:
	Chebyshev(int degree);

	double estimate(double (*f)(double));
protected:
	double x_s(int k);

	int degree;
	double* weights;
};

#endif
