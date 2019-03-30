#ifndef CLOSED_ONE_H
#define CLOSED_ONE_H

#include "newton_cotes.h"

class ClosedOne : public NewtonCotes{
protected:
    double calculate(double x_I, double x_F, double (*f)(double));
};

#endif