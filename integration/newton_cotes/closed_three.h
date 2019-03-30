#ifndef CLOSED_THREE_H
#define CLOSED_THREE_H

#include "newton_cotes.h"

class ClosedThree : public NewtonCotes{
protected:
    double calculate(double x_I, double x_F, double (*f)(double));
};

#endif