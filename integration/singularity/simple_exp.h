#ifndef SIMPLE_EXP_H
#define SIMPLE_EXP_H

#include "exp_method.h"

class SimpleExp : public ExpMethod {
public:
	SimpleExp(double a , double b);

protected:
	double x_s(double s);

	double dx_ds(double s);
};

#endif