#ifndef DERIVATIVE_H
#define DERIVATIVE_H

#include "utils.h"
#include "user_input.h"

double derivative(Derivative derivative, Accuracy accuracy, Philosophy philosophy, double* data_points, int point, int number_of_points, double delta_x);

#endif