#include <cmath>

#include "utils.h"

double f(double x) {
	return 1.0/x;
}

double x_s(double s, double a, double b) {
	return (a+b)/2.0 + ((b-a)/2.0)*std::tanh(s);
}

double dx_ds(double s, double a, double b) {
	return (b-a)/(2.0*std::pow(std::cos(s), 2));
}

double g_s(double s, double a, double b) {
	return f(x_s(s, a, b))/dx_ds(s, a, b);
}