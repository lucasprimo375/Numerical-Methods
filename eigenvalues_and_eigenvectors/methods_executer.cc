#include <cmath>
#include <iostream>

#include "methods_executer.h"
#include "methods.h"
#include "matrix.h"
#include "vector.h"
#include "gauss_solver.h"
#include "utils.h"

#define _USE_MATH_DEFINES

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
			MethodsExecuter::jacobi_method(matrix, precision);
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

	Matrix* H = Utils::generateIdentityMatrix( A->getRows() );

	for( int i = 0; i < A->getRows() - 2; i++ ) {
		Matrix* H_c = MethodsExecuter::build_house_holder_index( A_bar, i );
	
		A_bar = *((*H_c)*A_bar)*H_c;

		H = (*H)*H_c;
	}

	return A_bar;
}

Matrix* MethodsExecuter::build_house_holder_index( Matrix* A, int i ) {
	Vector* v = new Vector( A->getRows(), true );

	for( int j = i + 1; j < v->getSize(); j++ )
		v->addElement( j, A->getElement(j, i) );

	double L_v = v->length();

	Vector* v_bar = new Vector( A->getRows(), true );

	if( v->getElement( i + 1 ) >= 0 )
		v_bar->addElement( i + 1, L_v );
	else v_bar->addElement( i + 1, -L_v );

	Vector* n = (*v) - v_bar;
	n->normalize();

	return (*Utils::generateIdentityMatrix( A->getRows() )) - (*Utils::multiplyVectors(n, n))*2.0;
}

void MethodsExecuter::jacobi_method(Matrix* matrix, double precision) {
	Matrix* A_bar = matrix->copy();

	Matrix* J = MethodsExecuter::generate_house_holder_matrix(matrix);

	double max_old = 0;
	double max_new = 0;

	do {
		max_old = max_new;
		
		Matrix* P = Utils::generateIdentityMatrix( A_bar->getRows() );

		for(int j = 0; j < A_bar->getRows() - 1; j++){
			for(int i = j + 1; i < A_bar->getRows(); i++){
				Matrix* P_i_j = MethodsExecuter::calculate_P_i_j(A_bar, i, j);

				A_bar = *((*P_i_j->transpose())*A_bar)*P_i_j;

				P = *P*P_i_j;
			}
		}

		J = *J*P;

		max_new = MethodsExecuter::get_max_not_diagonal(A_bar);

	} while( (std::abs(max_new - max_old))/max_new > precision );

	std::cout << std::endl << "The eigenvectors matrix is" << std::endl;

	J->print();

	std::cout << std::endl << "The eigenvalues matrix is" << std::endl;

	A_bar->print();
}

Matrix* MethodsExecuter::calculate_P_i_j(Matrix* matrix, int i, int j){
	double theta;

	if(matrix->getElement(j, j) == matrix->getElement(i, i))
		theta = M_PI/4.0;
	else theta = std::atan(2.0*matrix->getElement(i, j)/(matrix->getElement(j, j) - matrix->getElement(i, i)))/2.0;

	Matrix* P_i_j = Utils::generateIdentityMatrix(matrix->getRows());

	P_i_j->addElement(i, i, std::cos(theta));
	P_i_j->addElement(i, j, std::sin(theta));
	P_i_j->addElement(j, i, -std::sin(theta));
	P_i_j->addElement(j, j, std::cos(theta));

	return P_i_j;
}

double MethodsExecuter::get_max_not_diagonal( Matrix* A ) {
	double max = std::abs(A->getElement(0, 1));

	for( int i = 0; i < A->getRows(); i++ ) {
		for( int j = 0; j < A->getColumns(); j++ ) {
			if( (i != j) && (std::abs(A->getElement(i, j)) > max) )
				max = std::abs(A->getElement(i, j));
		}
	}

	return max;
}