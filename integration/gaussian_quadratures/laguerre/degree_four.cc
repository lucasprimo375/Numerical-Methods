#include <cmath>
#include <iostream>

#include "degree_four.h"

DegreeFour::DegreeFour(){
    degree = 4;

    roots = new double[degree];
    roots[0] = 0.3225476896193923118004;
    roots[1] = 1.745761101158346575687;
    roots[2] = 4.536620296921127983279;
    roots[3] = 9.395070912301133129234;

    weights = new double[degree];
    weights[0] = 0.603154104341633601636;
    weights[1] = 0.3574186924377996866415;
    weights[2] = 0.03888790851500538427244;
    weights[3] = 0.0005392947055613274501038;
}
