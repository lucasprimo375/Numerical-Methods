#include <cmath>

#include "degree_two.h"

DegreeTwo::DegreeTwo() {
	degree = 2;

	roots = new double[degree];
	roots[0] = -0.7071067811865475244008;
	roots[1] = 0.7071067811865475244008;

	weights = new double[degree];
	weights[0] = 0.8862269254527580136491;
	weights[1] = 0.886226925452758013649;
}
