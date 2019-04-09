#include <cmath>

#include "degree_two.h"

DegreeTwo::DegreeTwo(){
	degree = 2;
	
	roots = new double[degree];
	roots[0] = -0.7071067811865475244008;
	roots[1] = 0.7071067811865475244008;
	
	weights = new double[degree];
	weights[0] = 1.570796326794896619231;
	weights[1] = 1.570796326794896619231;
}
