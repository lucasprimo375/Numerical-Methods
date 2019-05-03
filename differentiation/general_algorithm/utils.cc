#include <fstream>
#include <iostream>

#include "utils.h"

double* get_data_points(std::string file_path, int* number_of_points){
	std::ifstream points_input_stream;
    points_input_stream.open(file_path.c_str(), std::ifstream::in);

    if(!points_input_stream){
        std::cout << "your input file could not be opened or does not exist" << std::endl;
        return nullptr;
    }

    double* points = new double[*number_of_points];

    std::string line;
    int i = 0;
    while((i < *number_of_points) && (points_input_stream >> line)){
        points[i] = std::stod(line);
        i++;
    }

    points_input_stream.close();

	*number_of_points = i;

    return points;
}

void write_result_to_file(double* points, int number_of_points, std::string output_file_name){
	std::ofstream points_output_stream;
    points_output_stream.open(output_file_name.c_str(), std::ifstream::out);
    
    if(!points_output_stream){
        std::cout << "Your output file could not be opened or created" << std::endl;
    } else {
        for(int i=0; i<number_of_points; i++){
            if(i != number_of_points-1){
                points_output_stream << points[i] << std::endl;
            } else {
                points_output_stream << points[i];
            }
        }

        std::cout << "The results have been written to " << output_file_name << std::endl;
    }

    points_output_stream.close();
}