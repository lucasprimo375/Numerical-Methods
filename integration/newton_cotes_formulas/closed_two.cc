#include "closed_two.h"

double ClosedTwo::calculate(double x_I, double x_F, double (*f)(double)){
    double h = (x_F - x_I)/2;

    double x_0 = x_I;
    double x_1 = x_I + h;
    double x_2 = x_I + 2*h;

    return (h/3)*(f(x_0) + 4*f(x_1) + f(x_2));
}