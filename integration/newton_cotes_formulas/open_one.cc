#include "open_one.h"

double OpenOne::calculate(double x_I, double x_F, double (*f)(double)){
    double h = (x_F - x_I)/3;

    double x_0 = x_I + h;
    double x_1 = x_I + 2*h;

    return ((3*h)/2)*(f(x_0) + f(x_1));
}