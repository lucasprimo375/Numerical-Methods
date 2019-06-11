#include "derivative.h"
#include "first_derivative.h"
#include "second_derivative.h"
#include "third_derivative.h"
#include "utils.h"
#include "user_input.h"

double derivative(Derivative derivative, Accuracy accuracy, Philosophy philosophy, double* data_points, int point, int number_of_points, double delta_x) {
	switch( derivative ) {
		case First: {
			switch( philosophy ) {
				case Backward: return FirstDerivative::backward(data_points, point, number_of_points, accuracy, delta_x);

				case Central: return FirstDerivative::central(data_points, point, number_of_points, accuracy, delta_x);
			
				case Forward: return FirstDerivative::forward(data_points, point, number_of_points, accuracy, delta_x);
			}
		}

		case Second: {
			switch( philosophy ) {
				case Backward: return SecondDerivative::backward(data_points, point, number_of_points, accuracy, delta_x);

				case Central: return SecondDerivative::central(data_points, point, number_of_points, accuracy, delta_x);
			
				case Forward: return SecondDerivative::forward(data_points, point, number_of_points, accuracy, delta_x);
			}
		}

		case Third: {
			switch( philosophy ) {
				case Backward: return ThirdDerivative::backward(data_points, point, number_of_points, accuracy, delta_x);

				case Central: return ThirdDerivative::central(data_points, point, number_of_points, accuracy, delta_x);
			
				case Forward: return ThirdDerivative::forward(data_points, point, number_of_points, accuracy, delta_x);
			}
		}
	}
}