#include "closed_two.h"
#include "functions.h"

using namespace Functions;

double ClosedTwo::calculate(double x_I, double x_F){
    double h = (x_F - x_I)/2.0;

    double x_0 = x_I;
    double x_1 = x_I + h;
    double x_2 = x_I + 2.0*h;

    return (h/3.0)*(G(x_0) + 4.0*G(x_1) + G(x_2));
}

double ClosedTwo::G(double x) {
	double x_I = f(x);
	double x_F = g(x);

	double h = (x_F - x_I)/2.0;

    double x_0 = x_I;
    double x_1 = x_I + h;
    double x_2 = x_I + 2.0*h;

    return (h/3.0)*(F(x, x_0) + 4.0*F(x, x_1) + F(x, x_2));
}