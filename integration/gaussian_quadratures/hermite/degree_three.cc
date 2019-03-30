#include <cmath>
#include <iostream>

#include "degree_three.h"

DegreeThree::DegreeThree() {
    degree = 3;

    roots = new double[degree];
    roots[0] = -1.224744871391589049099;
    roots[1] = 0;
    roots[2] = 1.224744871391589049099;

    weights = new double[degree];
    weights[0] = 0.295408975150919337883;
    weights[1] = 1.181635900603677351532;
    weights[2] = 0.295408975150919337883;
}
