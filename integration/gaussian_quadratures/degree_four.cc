#include <cmath>
#include <iostream>

#include "degree_four.h"

DegreeFour::DegreeFour(double a, double b) : GaussQuadrature(a, b) {
    degree = 4;

    roots = new double[degree];
    roots[0] = -std::sqrt(std::sqrt(static_cast<double>(525) - 70*std::sqrt(30)))/35;
    roots[1] = std::sqrt(std::sqrt(static_cast<double>(525) - 70*std::sqrt(30)))/35;
    roots[2] = -std::sqrt(std::sqrt(static_cast<double>(525) + 70*std::sqrt(30)))/35;
    roots[3] = std::sqrt(std::sqrt(static_cast<double>(525) + 70*std::sqrt(30)))/35;

    weights = new double[degree];
    weights[0] = (static_cast<double>(18) + std::sqrt(30))/36;
    weights[1] = (static_cast<double>(18) + std::sqrt(30))/36;
    weights[2] = (static_cast<double>(18) - std::sqrt(30))/36;
    weights[3] = (static_cast<double>(18) - std::sqrt(30))/36;
}
