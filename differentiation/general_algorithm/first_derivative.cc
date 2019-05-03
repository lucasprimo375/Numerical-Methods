#include <iostream>

#include "first_derivative.h"

double FirstDerivative::central(double* points, int point, int size, Accuracy accuracy, double delta_x){
	switch(accuracy){
		case Accuracy::Two:{
			if((point+1 < size) && (point-1 > -1)){
				return (points[point+1]/2.0 - points[point-1]/2.0)/delta_x;
			} else {
				std::cout << "Not possible to calculate first derivative - accuracy two - central to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Returning zero" << std::endl;
				return 0;
			}
		}

		case Accuracy::Four:{
			if((point+2 < size) && (point-2 > -1)){
				return (points[point-2]/12.0 - 2.0*points[point-1]/3.0 + 2.0*points[point+1]/3.0 - 1.0*points[point+2]/12.0)/delta_x;
			} else {
				std::cout << "Not possible to calculate first derivative - accuracy four - central to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy Two" << std::endl;
				return central(points, point, size, Accuracy::Two, delta_x);
			}
			break;
		}

		case Accuracy::Six: {
			if((point+3 < size) && (point-3 > -1)){
				return (-points[point-3]/60.0 + 3.0*points[point-2]/20.0 - 3.0*points[point-1]/4.0 + 3.0*points[point+1]/4.0 - 3.0*points[point+2]/20.0 + points[point+3]/60.0)/delta_x;
			} else {
				std::cout << "Not possible to calculate first derivative - accuracy six - central for point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy Four" << std::endl;
				return central(points, point, size, Accuracy::Four, delta_x);
			}
			break;
		}

		default: {
			return 0;
			break;
		}
	}
}

double FirstDerivative::forward(double* points, int point, int size, Accuracy accuracy, double delta_x) {
	switch( accuracy ) {
		case Accuracy::One : {
			if( point + 1 < size ) {
				return ( -points[point] + points[point + 1] )/delta_x;
			} else {
				std::cout << "Not possible to calculate first derivative - accuracy one - forward to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Returning zero" << std::endl;
				return 0;
			}

			break;
		}

		case Accuracy::Two : {
			if( point + 2 < size ) {
				return ( -3.0*points[point]/2.0 + 2.0*points[point + 1] - points[point + 2]/2.0)/delta_x;
			} else {
				std::cout << "Not possible to calculate first derivative - accuracy two - forward to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy One" << std::endl;
				return forward(points, point, size, Accuracy::One, delta_x);
			}

			break;
		}

		case Accuracy::Three : {
			if( point + 3 < size ) {
				return ( -11.0*points[point]/6.0 + 3.0*points[point + 1] - 3.0*points[point + 2]/2.0 + points[point + 3]/3)/delta_x;
			} else {
				std::cout << "Not possible to calculate first derivative - accuracy three - forward to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy Two" << std::endl;
				return forward(points, point, size, Accuracy::Two, delta_x);
			}

			break;
		}

		case Accuracy::Four : {
			if( point + 4 < size ) {
				return ( -25.0*points[point]/12.0 + 4.0*points[point + 1] - 3.0*points[point + 2] + 4.0*points[point + 3]/3 - points[point + 4]/4)/delta_x;
			} else {
				std::cout << "Not possible to calculate first derivative - accuracy four - forward to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy Three" << std::endl;
				return forward(points, point, size, Accuracy::Three, delta_x);
			}

			break;
		}		
	}
}