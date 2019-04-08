#include <cmath>
#include <iostream>

#include "degree_three.h"

DegreeThree::DegreeThree(){
    degree = 3;

    roots = new double[degree];
    roots[0] = 0.4157745567834790833115;
    roots[1] = 2.29428036027904171982;
    roots[2] = 6.289945082937479196866;

    weights = new double[degree];
    weights[0] = 0.71109300992917301545;
    weights[1] = 0.2785177335692408488014;
    weights[2] = 0.01038925650158613574897;
}
