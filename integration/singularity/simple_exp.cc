#include <cmath>

#include "simple_exp.h"

SimpleExp::SimpleExp(double a , double b) : ExpMethod(a, b) {}

double SimpleExp::x_s(double s) {
	return (a_ + b_)/2.0 + (b_ - a_)*std::tanh(s)/2;
}

double SimpleExp::dx_ds(double s) {
	return (b_ - a_)/(2.0 * std::pow(std::cosh(s), 2.0));
}