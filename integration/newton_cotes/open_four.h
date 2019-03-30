#ifndef OPEN_FOUR_H
#define OPEN_FOUR_H

#include "newton_cotes.h"

class OpenFour : public NewtonCotes{
protected:
    double calculate(double x_I, double x_F, double (*f)(double));
};

#endif