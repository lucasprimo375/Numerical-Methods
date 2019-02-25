#include <iostream>
#include <vector>
#include <fstream>

double discrete_backward_derivative(std::vector<double>* points, int index, double delta_x);
double discrete_forward_derivative(std::vector<double>* points, int index, double delta_x);
double discrete_central_derivative(std::vector<double>* points, int index, double delta_x);

std::vector<double>* read_points_file(std::string file_name);
void calculate_discrete_derivative(std::vector<double>* points, double delta_x, std::string output_file_name);

double discrete_derivative(std::vector<double>* points, int index, double delta_x);

int main(int argc, char *argv[]) {
    std::vector<double>* points;

    if(argc >= 3){
        points = read_points_file(argv[1]);
        if(points != nullptr){
            double delta_x;
            std::cout << "input delta x:";
            std::cin >> delta_x;

            calculate_discrete_derivative(points, delta_x, argv[2]);
        }
    } else {
        std::cout << "you must specify the files (global path) where the points are located and where to write the results" << std::endl
                    << "first the input file name then the output file name" << std::endl;
    }

    return 0;
}

void calculate_discrete_derivative(std::vector<double>* points, double delta_x, std::string output_file_name){
    int number_of_points = points->size();

    std::ofstream points_output_stream;
    points_output_stream.open(output_file_name.c_str(), std::ifstream::out);

    if(!points_output_stream){
        std::cout << "your output file could not be opened" << std::endl;
    } else {
        for(int i=0; i<number_of_points; i++){
            if(i != number_of_points-1){
                points_output_stream << discrete_derivative(points, i, delta_x) << std::endl;
            } else {
                points_output_stream << discrete_derivative(points, i, delta_x);
            }
        }

        std::cout << "the results have been written to " << output_file_name << std::endl;
    }

    points_output_stream.close();
}

double discrete_backward_derivative(std::vector<double> *points, int index, double delta_x){
    return (points->at(index) - points->at(index-1))/delta_x;
}

double discrete_forward_derivative(std::vector<double> *points, int index, double delta_x){
    return (points->at(index+1) - points->at(index))/delta_x;
}

double discrete_central_derivative(std::vector<double> *points, int index, double delta_x){
    return (points->at(index+1) - points->at(index-1))/(2*delta_x);
}

std::vector<double>* read_points_file(std::string file_name){
    std::ifstream points_input_stream;
    points_input_stream.open(file_name.c_str(), std::ifstream::in);

    if(!points_input_stream){
        std::cout << "your input file could not be opened" << std::endl;
        return nullptr;
    }

    std::vector<double>* points = new std::vector<double>;

    std::string line;
    while(points_input_stream >> line){
        points->push_back(std::stod(line));
    }

    points_input_stream.close();

    return points;
}

double discrete_derivative(std::vector<double> *points, int index, double delta_x){
    int number_of_points = points->size();

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
