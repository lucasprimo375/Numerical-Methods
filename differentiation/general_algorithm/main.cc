#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "user_input.h"
#include "utils.h"
#include "first_derivative.h"

int main(int argc, char *argv[]) {

	std::string data_file_global_path = get_file_global_path();
	int number_of_points = get_number_of_points();
    double delta_x = get_delta_x();
	
	double* data_points = get_data_points(data_file_global_path, &number_of_points);
	
	double* first_derivative_central_accuracy_two = new double[number_of_points];
	double* first_derivative_central_accuracy_four = new double[number_of_points];
    double* first_derivative_central_accuracy_six = new double[number_of_points];

    double* first_derivative_forward_accuracy_one = new double[number_of_points];
    double* first_derivative_forward_accuracy_two = new double[number_of_points];
    double* first_derivative_forward_accuracy_three = new double[number_of_points];
    double* first_derivative_forward_accuracy_four = new double[number_of_points];

	for(int i=0; i<number_of_points; i++){
		first_derivative_central_accuracy_two[i] = FirstDerivative::central(data_points, i, number_of_points, Accuracy::Two, delta_x);
        first_derivative_central_accuracy_four[i] = FirstDerivative::central(data_points, i, number_of_points, Accuracy::Four, delta_x);
        first_derivative_central_accuracy_six[i] = FirstDerivative::central(data_points, i, number_of_points, Accuracy::Six, delta_x);

        first_derivative_forward_accuracy_one[i] = FirstDerivative::forward(data_points, i, number_of_points, Accuracy::One, delta_x);
        first_derivative_forward_accuracy_two[i] = FirstDerivative::forward(data_points, i, number_of_points, Accuracy::Two, delta_x);
        first_derivative_forward_accuracy_three[i] = FirstDerivative::forward(data_points, i, number_of_points, Accuracy::Three, delta_x);
        first_derivative_forward_accuracy_four[i] = FirstDerivative::forward(data_points, i, number_of_points, Accuracy::Four, delta_x);
	}

	write_result_to_file(first_derivative_central_accuracy_two, number_of_points, "first_derivative_central_accuracy_two.txt");
    write_result_to_file(first_derivative_central_accuracy_four, number_of_points, "first_derivative_central_accuracy_four.txt");
    write_result_to_file(first_derivative_central_accuracy_six, number_of_points, "first_derivative_central_accuracy_six.txt");

    write_result_to_file(first_derivative_forward_accuracy_one, number_of_points, "first_derivative_forward_accuracy_one.txt");
    write_result_to_file(first_derivative_forward_accuracy_two, number_of_points, "first_derivative_forward_accuracy_two.txt");
    write_result_to_file(first_derivative_forward_accuracy_three, number_of_points, "first_derivative_forward_accuracy_three.txt");
    write_result_to_file(first_derivative_forward_accuracy_four, number_of_points, "first_derivative_forward_accuracy_four.txt");
}
