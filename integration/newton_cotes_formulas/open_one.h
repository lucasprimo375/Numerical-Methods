#ifndef OPEN_ONE_H
#define OPEN_ONE_H

#include "newton_cotes.h"

class OpenOne : public NewtonCotes{
protected:
    double calculate(double x_I, double x_F, double (*f)(double));
};

#endif