#ifndef OPEN_THREE_H
#define OPEN_THREE_H

#include "newton_cotes.h"

class OpenThree : public NewtonCotes{
protected:
    double calculate(double x_I, double x_F, double (*f)(double));
};

#endif
