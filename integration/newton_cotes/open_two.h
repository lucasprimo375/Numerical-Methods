#ifndef OPEN_TWO_H
#define OPEN_TWO_H

#include "newton_cotes.h"

class OpenTwo : public NewtonCotes{
protected:
    double calculate(double x_I, double x_F, double (*f)(double));
};

#endif