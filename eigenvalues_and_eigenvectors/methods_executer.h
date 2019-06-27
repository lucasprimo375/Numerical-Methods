#ifndef METHODS_EXECUTER_H
#define METHODS_EXECUTER_H

#include "methods.h"
#include "matrix.h"
#include "vector.h"

namespace MethodsExecuter {
	void execute_method( Method method, Matrix* matrix, double precision, Vector* x_0, double lambda_0 );

	void regular_power_method( Matrix* matrix, double precision, Vector* x_0 );

	void inverse_power_method( Matrix* matrix, double precision, Vector* x_0 );

	void shifted_power_method( Matrix* matrix, double precision, Vector* x_0, double lambda_0 );
};

#endif