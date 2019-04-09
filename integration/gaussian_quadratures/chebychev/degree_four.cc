#include <cmath>
#include <iostream>

#include "degree_four.h"

DegreeFour::DegreeFour(){
    degree = 4;

    roots = new double[degree];
    roots[0] = -0.9238795325112867561282;
    roots[1] = -0.3826834323650897717285;
    roots[2] = 0.3826834323650897717285;
    roots[3] = 0.9238795325112867561282;

    weights = new double[degree];
    weights[0] = 0.7853981633974483096157;
    weights[1] = 0.7853981633974483096157;
    weights[2] = 0.7853981633974483096157;
    weights[3] = 0.7853981633974483096157;
}
