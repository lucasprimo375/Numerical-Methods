#include "closed_one.h"
#include "functions.h"

using namespace Functions;

double ClosedOne::calculate(double x_I, double x_F){
    return ( G(x_F) - G(x_I) ) * ( G(x_F) + G(x_I) ) / 2.0;
}

double ClosedOne::G(double x) {
	return ( F(x, g(x)) - F(x, f(x)) ) * ( F(x, g(x)) + F(x, f(x)) ) / 2.0;
}