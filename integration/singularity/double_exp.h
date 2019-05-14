#ifndef DOUBLE_EXP_H
#define DOUBLE_EXP_H

#include "exp_method.h"

class DoubleExp : public ExpMethod {
public:
	DoubleExp(double a , double b);

protected:
	double x_s(double s);

	double dx_ds(double s);
};

#endif