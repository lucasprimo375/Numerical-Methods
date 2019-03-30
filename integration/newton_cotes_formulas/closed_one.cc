#include "closed_one.h"

double ClosedOne::calculate(double x_I, double x_F, double (*f)(double)){
    double h = (x_F - x_I)/2;

    return h*(f(x_I) + f(x_F));
}