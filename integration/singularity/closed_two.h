#ifndef CLOSED_TWO_H
#define CLOSED_TWO_H

#include <functional>

#include "newton_cotes.h"

class ClosedTwo : public NewtonCotes{
protected:
    double calculate(double x_I, double x_F, std::function<double(double)> f);
};

#endif