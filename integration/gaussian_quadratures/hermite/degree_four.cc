#include <cmath>
#include <iostream>

#include "degree_four.h"

DegreeFour::DegreeFour() {
    degree = 4;

    roots = new double[degree];
    roots[0] = -1.650680123885784555883;
    roots[1] = -0.5246476232752903178841;
    roots[2] = 0.5246476232752903178841;
    roots[3] = 1.650680123885784555883;

    weights = new double[degree];
    weights[0] = 0.081312835447245177143;
    weights[1] = 0.8049140900055128365061;
    weights[2] = 0.8049140900055128365061;
    weights[3] = 0.08131283544724517714304;
}
