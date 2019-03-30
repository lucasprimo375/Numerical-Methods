#include "open_three.h"

double OpenThree::calculate(double x_I, double x_F, double (*f)(double)){
    double h = (x_F - x_I)/5;

    double x_0 = x_I + h;
    double x_1 = x_I + 2*h;
    double x_2 = x_I + 3*h;
    double x_3 = x_I + 4*h;

    return (5*(h/24))*(11*f(x_0) + f(x_1) + f(x_2) + 11*f(x_3));
}