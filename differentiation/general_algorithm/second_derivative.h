#ifndef SECOND_DERIVATIVE_H
#define SECOND_DERIVATIVE_H

#include "utils.h"

namespace SecondDerivative {
	double central(double* points, int point, int size, Accuracy accuracy, double delta_x);
	double forward(double* points, int point, int size, Accuracy accuracy, double delta_x);
	double backward(double* points, int point, int size, Accuracy accuracy, double delta_x);
};

#endif