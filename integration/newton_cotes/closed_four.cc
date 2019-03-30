#include "closed_four.h"

double ClosedFour::calculate(double x_I, double x_F, double (*f)(double)){
    double h = (x_F - x_I)/4;

    double x_0 = x_I;
    double x_1 = x_I + h;
    double x_2 = x_I + 2*h;
    double x_3 = x_I + 3*h;
    double x_4 = x_I + 4*h;

    return (2*(h/45))*(7*f(x_0) + 32*f(x_1) + 12*f(x_2) + 32*f(x_3) + 7*f(x_4));
}