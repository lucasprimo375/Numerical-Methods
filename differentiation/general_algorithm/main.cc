#include <iostream>
#include <string>

#include "user_input.h"
#include "utils.h"
#include "first_derivative.h"
#include "second_derivative.h"
#include "third_derivative.h"
#include "derivative.h"

int main(int argc, char *argv[]) {

	std::string data_file_global_path = get_file_global_path();
	int number_of_points = get_number_of_points();
    double delta_x = get_delta_x();
	
	double* data_points = get_data_points(data_file_global_path, &number_of_points);

    if(data_points == nullptr){
        return 0;
    }

    Derivative derivative_ = get_user_derivative_choice();

    Accuracy accuracy = get_user_accuracy_choice();

    Philosophy philosophy = get_philosophy_from_user();
	
	double* result = new double[number_of_points];

	for(int i=0; i<number_of_points; i++){
        result[i] = derivative(derivative_, accuracy, philosophy, data_points, i, number_of_points, delta_x);
		/*third_derivative_central_accuracy_two[i] = ThirdDerivative::central(data_points, i, number_of_points, Accuracy::Two, delta_x);
        third_derivative_central_accuracy_four[i] = ThirdDerivative::central(data_points, i, number_of_points, Accuracy::Four, delta_x);
        third_derivative_central_accuracy_six[i] = ThirdDerivative::central(data_points, i, number_of_points, Accuracy::Six, delta_x);

        third_derivative_forward_accuracy_one[i] = ThirdDerivative::forward(data_points, i, number_of_points, Accuracy::One, delta_x);
        third_derivative_forward_accuracy_two[i] = ThirdDerivative::forward(data_points, i, number_of_points, Accuracy::Two, delta_x);
        third_derivative_forward_accuracy_three[i] = ThirdDerivative::forward(data_points, i, number_of_points, Accuracy::Three, delta_x);
        third_derivative_forward_accuracy_four[i] = ThirdDerivative::forward(data_points, i, number_of_points, Accuracy::Four, delta_x);

        third_derivative_backward_accuracy_one[i] = ThirdDerivative::backward(data_points, i, number_of_points, Accuracy::One, delta_x);
        third_derivative_backward_accuracy_two[i] = ThirdDerivative::backward(data_points, i, number_of_points, Accuracy::Two, delta_x);
        third_derivative_backward_accuracy_three[i] = ThirdDerivative::backward(data_points, i, number_of_points, Accuracy::Three, delta_x);
        third_derivative_backward_accuracy_four[i] = ThirdDerivative::backward(data_points, i, number_of_points, Accuracy::Four, delta_x);*/
	}

    write_result_to_file(result, number_of_points, get_output_file_name_from_user());
}
