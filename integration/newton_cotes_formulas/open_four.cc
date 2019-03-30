#include "open_four.h"

double OpenFour::calculate(double x_I, double x_F, double (*f)(double)){
    double h = (x_F - x_I)/6;

    double x_0 = x_I + h;
    double x_1 = x_I + 2*h;
    double x_2 = x_I + 3*h;
    double x_3 = x_I + 4*h;
    double x_4 = x_I + 5*h;

    return (6*(h/20))*(11*f(x_0) - 14*f(x_1) + 26*f(x_2) - 14*f(x_3) + 11*f(x_4));
}