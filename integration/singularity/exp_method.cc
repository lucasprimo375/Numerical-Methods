#include "exp_method.h"

ExpMethod::ExpMethod(double a, double b) {
	a_ = a;
	b_ = b;
}

double ExpMethod::f(double x) {
	return 1.0/x;
}

double ExpMethod::g_s(double s) {
	return f(x_s(s))/dx_ds(s);
}