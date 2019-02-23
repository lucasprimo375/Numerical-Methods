#include <iostream>
#include <vector>
#include <fstream>

#include "utils/utils.h"

double discrete_backward_derivative(std::vector<double>& points, int index, double delta_x);
double discrete_forward_derivative(std::vector<double>& points, int index, double delta_x);
double discrete_central_derivative(std::vector<double>& points, int index, double delta_x);

std::vector<double> *read_points_file(std::string file_name);

double discrete_derivative(std::vector<double>& points, int index, double delta_x);

int main(int argc, char *argv[]) {
    std::vector<double> points;

    utils();

    //std::cout << discrete_derivative(points, 0, 1) << std::endl;

    if(argc >= 2){
        read_points_file(argv[1]);
    } else {
        std::cout << "you must specify the a file (global path) where the points are located" << std::endl;
    }

    return 0;
}

double discrete_backward_derivative(std::vector<double> &points, int index, double delta_x){
    return (points[index] - points[index-1])/delta_x;
}

double discrete_forward_derivative(std::vector<double> &points, int index, double delta_x){
    return (points[index+1] - points[index])/delta_x;
}

double discrete_central_derivative(std::vector<double> &points, int index, double delta_x){
    return (points[index+1] - points[index-1])/(2*delta_x);
}

std::vector<double>* read_points_file(std::string file_name){
    std::ifstream points_input_stream;
    points_input_stream.open(file_name.c_str(), std::ifstream::in);

    if(!points_input_stream){
        std::cout << "your file could not be opened" << std::endl;
        return NULL;
    }

    std::string line;
    while(points_input_stream >> line){
        std::cout << line << std::endl;
    }
}

double discrete_derivative(std::vector<double> &points, int index, double delta_x){
    int number_of_points = points.size();

    if(number_of_points <= 1){
        std::cout << "there must be at least two points in the vector" << std::endl;
        return 0;
    }

    if(index != 0 && index != number_of_points-1){
        return discrete_central_derivative(points, index, delta_x);
    }

    if(index == 0){
        return discrete_forward_derivative(points, index, delta_x);
    }

    if(index == number_of_points-1){
        return discrete_backward_derivative(points, index, delta_x);
    }

    std::cout << "chosen index (" << index << ") is out of range" << std::endl;
    return 0;
}
