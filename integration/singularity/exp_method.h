#ifndef EXP_METHOD_H
#define EXP_METHOD_H

class ExpMethod {
public:
	ExpMethod(double a, double b);

protected:
	double f(double x);

	virtual double x_s(double s) = 0;

	virtual double dx_ds(double s) = 0;

	double g_s(double s);

	double a_, b_;
};

#endif