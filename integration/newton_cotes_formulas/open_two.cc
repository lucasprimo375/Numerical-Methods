#include "open_two.h"

double OpenTwo::calculate(double x_I, double x_F, double (*f)(double)){
    double h = (x_F - x_I)/4;

    double x_0 = x_I + h;
    double x_1 = x_I + 2*h;
    double x_2 = x_I + 3*h;

    return (4*(h/3))*(2*f(x_0) - f(x_1) + 2*f(x_2));
}