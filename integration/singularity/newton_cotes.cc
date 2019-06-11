#include <cmath>
#include <iostream>
#include <iomanip>
#include <functional>

#include "newton_cotes.h"

double NewtonCotes::estimate(double x_I, double x_F, double precision, std::function<double(double)> f){
    int n = 1;

    double I = calculatePartitions(x_I, x_F, n, f);
    double I_old;

    std::cout << std::setprecision(6);

    do{
        I_old = I;
        n = 2*n;
        I = calculatePartitions(x_I, x_F, n, f);
    } while(std::abs(I - I_old) > precision);

    return I;
}

double NewtonCotes::calculatePartitions(double x_I, double x_F, int number_of_partitions, std::function<double(double)> f){
    double I = 0;
    double delta_x = (x_F - x_I)/number_of_partitions;

    for(int i = 0; i < number_of_partitions; i++){
        double x_i_I = x_I + i*delta_x;
        double x_i_F = x_i_I + delta_x;
        I = I + calculate(x_i_I, x_i_F, f);
    }

    //std::cout << "with " << number_of_partitions << " partitions: " << I << std::endl;

    return I;
}