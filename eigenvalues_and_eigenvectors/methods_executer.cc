#include <cmath>
#include <iostream>

#include "methods_executer.h"
#include "methods.h"
#include "matrix.h"
#include "vector.h"
#include "gauss_solver.h"
#include "utils.h"

void MethodsExecuter::execute_method( Method method, Matrix* matrix, double precision, Vector* x_0, double lambda_0 ) {
	switch( method ) {
		case Method::RegularPowerMethod:
			MethodsExecuter::regular_power_method(matrix, precision, x_0);
			break;

		case Method::InversePowerMethod: 
			MethodsExecuter::inverse_power_method(matrix, precision, x_0);
			break;
	
		case Method::ShiftedPowerMethod:
			MethodsExecuter::shifted_power_method(matrix, precision, x_0, lambda_0);
			break;
	
		case Method::HouseHolderMethod: {
			Matrix* A = MethodsExecuter::generate_house_holder_matrix( matrix );
			
			std::cout << std::endl << "This method only shows the House Holder Matrix" << std::endl;

			A->print();
			
			break;	
		}
	
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

void MethodsExecuter::shifted_power_method( Matrix* matrix, double precision, Vector* x_0, double lambda_0 ) {
	Matrix* A = Utils::generateShiftedPowerMethodMatrix( matrix, lambda_0 );

	double lambda_new = 0;
	Vector* x_old = x_0->newNormalized();

	int k = 1;

	double lambda_old;
	do {
		lambda_old = lambda_new;

		Vector* y_new = GaussSolver::solve(A, x_old);

		Vector* x_new = y_new->newNormalized();

		lambda_new = (*x_old) * y_new;

		x_old = x_new;

		std::cout << std::endl << "Iteration " << k << std::endl;

		std::cout << "The eigenvector is " << std::endl;
		x_new->print();

		std::cout << "The closest eigenvalue is " << 1.0/lambda_new + lambda_0 << std::endl;

		k++;
	} while(std::abs((lambda_new - lambda_old)/lambda_new) > precision);
}

Matrix* MethodsExecuter::generate_house_holder_matrix( Matrix* A ) {
	Matrix* A_bar = A->copy();

	Matrix* H = Utils::generateIdentityMatrix( A->getSize() );

	for( int i = 0; i < A->getSize() - 2; i++ ) {
		Matrix* H_c = MethodsExecuter::build_house_holder_index( A_bar, i );

		std::cout << std::endl << "H_c" << std::endl;
		H_c->print();
	
		A_bar = *((*H_c)*A_bar)*H_c;

		H = (*H)*H_c;
	}

	return A_bar;
}

Matrix* MethodsExecuter::build_house_holder_index( Matrix* A, int i ) {
	Vector* v = new Vector( A->getSize(), true );

	for( int j = i + 1; j < v->getSize(); j++ )
		v->addElement( j, A->getElement(j, i) );

	double L_v = v->length();

	Vector* v_bar = new Vector( A->getSize(), true );

	if( v->getElement( i + 1 ) >= 0 )
		v_bar->addElement( i + 1, L_v );
	else v_bar->addElement( i + 1, -L_v );

	Vector* n = (*v) - v_bar;
	n->normalize();

	return (*Utils::generateIdentityMatrix( A->getSize() )) - (*Utils::multiplyVectors(n, n))*2.0;
}