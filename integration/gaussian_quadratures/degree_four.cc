#include <cmath>
#include <iostream>

#include "degree_four.h"

DegreeFour::DegreeFour(double a, double b) : GaussQuadrature(a, b) {
    degree = 4;

    roots = new double[degree];
    roots[0] = static_cast<double>(std::sqrt((3 - 2*std::sqrt(6/5))/7));
    roots[1] = -static_cast<double>(std::sqrt((3 - 2*std::sqrt(6/5))/7));
    roots[2] = static_cast<double>(std::sqrt((3 + 2*std::sqrt(6/5))/7));
    roots[3] = -static_cast<double>(std::sqrt((3 + 2*std::sqrt(6/5))/7));

    weights = new double[degree];
    weights[0] = static_cast<double>((18 + std::sqrt(30))/36);
    weights[1] = static_cast<double>((18 + std::sqrt(30))/36);
    weights[2] = static_cast<double>((18 - std::sqrt(30))/36);
    weights[3] = static_cast<double>((18 - std::sqrt(30))/36);
}
