#include "closed_three.h"

double ClosedThree::calculate(double x_I, double x_F, double (*f)(double)){
    double h = (x_F - x_I)/3;

    double x_0 = x_I;
    double x_1 = x_I + h;
    double x_2 = x_I + 2*h;
    double x_3 = x_I + 3*h;

    return (3*(h/8))*(f(x_0) + 3*f(x_1) + 3*f(x_2) + f(x_3));
}