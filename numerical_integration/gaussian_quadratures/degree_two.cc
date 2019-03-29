#include <cmath>

#include "degree_two.h"

DegreeTwo::DegreeTwo(double a, double b) : GaussQuadrature(a, b) {
	degree = 2;
	
	roots = new double[degree];
	roots[0] = -std::sqrt(3)/3;
	roots[1] = std::sqrt(3)/3;
	
	weights = new double[degree];
	weights[0] = 1;
	weights[1] = 1;
}
