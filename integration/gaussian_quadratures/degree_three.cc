#include <cmath>
#include <iostream>

#include "degree_three.h"

DegreeThree::DegreeThree(double a, double b) : GaussQuadrature(a, b) {
    degree = 3;

    roots = new double[degree];
    roots[0] = -std::sqrt(static_cast<double>(3)/5);
    roots[1] = 0;
    roots[2] = std::sqrt(static_cast<double>(3)/5);

    weights = new double[degree];
    weights[0] = static_cast<double>(5)/9;
    weights[1] = static_cast<double>(8)/9;
    weights[2] = static_cast<double>(5)/9;
}
