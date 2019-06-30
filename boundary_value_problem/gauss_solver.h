#ifndef GAUSS_SOLVER_H
#define GAUSS_SOLVER_H

#include <tuple>

namespace GaussSolver {
	double* solve(double** A, double* b, int n);

	std::tuple<double**, double*>* gaussElimination(double** A, double* b, int n);

	double* solveSuperiorTriangular(double** A, double* b, int n);
};

#endif