#include <cmath>

#include "double_exp.h"

#define _USE_MATH_DEFINES

DoubleExp::DoubleExp(double a , double b) : ExpMethod(a, b) {}

double DoubleExp::x_s(double s) {
	return (a_ + b_)/2.0 + (b_ - a_)*std::tanh(M_PI*std::sinh(s)/2.0)/2.0;
}

double DoubleExp::dx_ds(double s) {
	return (M_PI*(b_ - a_)/2.0) * (1.0/std::pow(std::cosh(M_PI*std::sinh(s)/2.0), 2.0)) * std::cosh(s);
}