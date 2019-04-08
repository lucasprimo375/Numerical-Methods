#include <cmath>

#include "degree_two.h"

DegreeTwo::DegreeTwo(){
	degree = 2;
	
	roots = new double[degree];
	roots[0] = 0.5857864376269049511983;
	roots[1] = 3.414213562373095048802;
	
	weights = new double[degree];
	weights[0] = 0.8535533905932737622004;
	weights[1] = 0.1464466094067262377996;
}
