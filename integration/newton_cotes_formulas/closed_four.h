#ifndef CLOSED_FOUR_H
#define CLOSED_FOUR_H

#include "newton_cotes.h"

class ClosedFour : public NewtonCotes{
protected:
    double calculate(double x_I, double x_F, double (*f)(double));
};

#endif
