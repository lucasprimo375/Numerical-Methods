#include <cmath>
#include <iostream>

#include "boundary_value_problem_solver.h"
#include "functions.h"
#include "gauss_solver.h"

using namespace Functions;

BoundaryValueProblemSolver::BoundaryValueProblemSolver(int* v, double a, double b, int n){
	a_ = a;
	b_ = b;
	n_ = n + 1;
	h_ = (b_ - a_)/n;
	v_ = v;
}

void BoundaryValueProblemSolver::solve(double c1, double c2){
	double* b = new double[n_];

	b[0] = c1;
	b[n_ - 1] = c2;
	for(int i = 1; i < n_ - 1; i++)
		b[i] = z(v_, x(i));

	std::cout << std::endl << "Vector b:" << std::endl;

	std::cout << std::endl << "(";
	for(int i = 0; i < n_; i++){
		if( i != n_ - 1 ) std::cout << b[i] << ", ";
		else std::cout << b[i];
	}
	std::cout << ")" << std::endl;

	double** A = new double*[n_];
	for( int i = 0; i < n_; i++ ){
		A[i] = new double[n_];

		for( int j = 0; j< n_; j++ )
			A[i][j] = 0.0;
	}

	A[0][0] = 1;
	A[n_ - 1][n_ - 1] = 1;

	for( int i = 1; i < n_ - 1; i++ ){
		A[i][i - 1] = 1.0/std::pow(h_, 2.0) + f(x(i))/(2.0*h_);
		A[i][i] = -2.0/std::pow(h_,2.0) - g(x(i));
		A[i][i + 1] = 1.0/std::pow(h_, 2.0) - f(x(i))/(2.0*h_);
	}

	std::cout << std::endl << "Matrix A: " << std::endl;

	for( int i = 0; i < n_; i++ ){
		for(int j = 0; j < n_ ; j++)
			std::cout << A[i][j] << " ";

		std::cout << std::endl;
	}
	std::cout << std::endl;

	double* s = GaussSolver::solve(A, b, n_);

	for( int i = 0; i < n_; i++ )
		std::cout << "The solution for (" << x(i) << ") is " << s[i] << std::endl;
}

double BoundaryValueProblemSolver::x(int i){
	return a_ + i*h_;
}