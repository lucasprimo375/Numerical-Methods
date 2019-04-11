#include <cmath>
#include <iostream>

#include "degree_three.h"

DegreeThree::DegreeThree(){
    degree = 3;

    roots = new double[degree];
    roots[0] = -0.8660254037844386467637;
    roots[1] = 0;
    roots[2] = 0.8660254037844386467637;

    weights = new double[degree];
    weights[0] = 1.047197551196597746154;
    weights[1] = 1.047197551196597746154;
    weights[2] = 1.047197551196597746154;
}
