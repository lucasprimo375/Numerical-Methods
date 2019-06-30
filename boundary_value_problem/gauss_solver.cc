#include <tuple>

#include "gauss_solver.h"

double* GaussSolver::solve( double** A, double* b, int n ) {
	std::tuple<double**, double*>* Bc = GaussSolver::gaussElimination( A, b, n );

	double** B;
	double* c;

	std::tie(B, c) = *Bc;

	return GaussSolver::solveSuperiorTriangular( B, c, n );
}

std::tuple<double**, double*>* GaussSolver::gaussElimination( double** A, double* b, int n ) {
	for( int k = 0; k < n - 1; k++ ) {
		for( int i = k + 1; i < n; i++ ){
			double m = -A[i][k]/A[k][k];

			A[i][k] = 0;

			for(int j = k + 1; j < n; j++)
				A[i][j] = A[i][j] + m*A[k][j];

			b[i] = b[i] + m*b[k];
		}
	}

	std::tuple<double**, double*>* Bc = new std::tuple<double**, double*>(A, b);

	return Bc;
}

double* GaussSolver::solveSuperiorTriangular( double** A, double* b, int n ) {
    double* x = new double[n];

    x[n - 1] = b[n - 1]/A[n - 1][n - 1];

    for( int k = n - 2; k > -1; k-- ){
    	double sum = 0;

    	for( int j = k + 1; j < n; j++ )
    		sum += A[k][j]*x[j];

    	x[k] = (b[k] - sum)/A[k][k];
    }

    return x;
}