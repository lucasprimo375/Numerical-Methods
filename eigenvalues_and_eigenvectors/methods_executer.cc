#include <cmath>
#include <iostream>

#include "methods_executer.h"
#include "methods.h"
#include "matrix.h"
#include "vector.h"

void MethodsExecuter::execute_method( Method method, Matrix* matrix, double precision, Vector* x_0 ) {
	switch( method ) {
		case Method::RegularPowerMethod:
			MethodsExecuter::regular_power_method(matrix, precision, x_0);
			break;

		case Method::InversePowerMethod: 
			break;
	
		case Method::DisplacementPowerMethod:
			break;
	
		case Method::HouseHolderMethod:
			break;
	
		case Method::JacobiMethod:
			break;

		case Method::QRMethod:
			break;

		default: 
			break;
	}
}

void MethodsExecuter::regular_power_method( Matrix* matrix, double precision, Vector* x_0 ) {
	Vector* q = x_0->newNormalized();

	Vector* x = (*matrix) * q;

	double lambda = (*q) * x;

	double lambda_0;

	do {
		lambda_0 = lambda;
	
		delete q;
		q = x->newNormalized();
		//q->print();
	
		delete x;
		x = (*matrix) * q;
		x->print();

		lambda =  (*q) * x;
	} while( std::abs((lambda - lambda_0)/lambda) > precision );

	std::cout << lambda_0 << std::endl;
}