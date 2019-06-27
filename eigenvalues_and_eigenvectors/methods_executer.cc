#include <cmath>
#include <iostream>

#include "methods_executer.h"
#include "methods.h"
#include "matrix.h"
#include "vector.h"
#include "gauss_solver.h"

void MethodsExecuter::execute_method( Method method, Matrix* matrix, double precision, Vector* x_0 ) {
	switch( method ) {
		case Method::RegularPowerMethod:
			MethodsExecuter::regular_power_method(matrix, precision, x_0);
			break;

		case Method::InversePowerMethod: 
			MethodsExecuter::inverse_power_method(matrix, precision, x_0);
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
	double lambda_new = 0;
	Vector* x_old = x_0->newNormalized();

	int k = 1;

	double lambda_old;
	do {
		lambda_old = lambda_new;

		Vector* y_new = (*matrix) * x_old;

		Vector* x_new = y_new->newNormalized();

		lambda_new = (*x_old) * y_new;

		x_old = x_new;

		std::cout << std::endl << "Iteration " << k << std::endl;

		std::cout << "The eigenvector is " << std::endl;
		x_new->print();

		std::cout << "The greatest eigenvalue is " << lambda_new << std::endl;

		k++;
	} while(std::abs((lambda_new - lambda_old)/lambda_new) > precision);
}

void MethodsExecuter::inverse_power_method( Matrix* matrix, double precision, Vector* x_0 ) {
	double lambda_new = 0;
	Vector* x_old = x_0->newNormalized();

	int k = 1;

	double lambda_old;
	do {
		lambda_old = lambda_new;

		// bla
		Vector* y_new = GaussSolver::solve(matrix, x_old);

		Vector* x_new = y_new->newNormalized();

		lambda_new = (*x_old) * y_new;

		x_old = x_new;

		std::cout << std::endl << "Iteration " << k << std::endl;

		std::cout << "The eigenvector is " << std::endl;
		x_new->print();

		std::cout << "The lowest eigenvalue is " << 1.0/lambda_new << std::endl;

		k++;
	} while(std::abs((lambda_new - lambda_old)/lambda_new) > precision);
}