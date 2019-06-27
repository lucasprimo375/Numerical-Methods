#ifndef GAUSS_SOLVER_H
#define GAUSS_SOLVER_H

#include <tuple>

#include "vector.h"
#include "matrix.h"

namespace GaussSolver {
	Vector* solve( Matrix* A, Vector* b);

	std::tuple<Matrix*, Vector*>* gaussElimination( Matrix* A, Vector* b );

	Vector* solveSuperiorTriangular( Matrix* A, Vector* b );
};

#endif