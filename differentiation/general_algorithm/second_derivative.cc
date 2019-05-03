#include <iostream>
#include <cmath>

#include "second_derivative.h"

double SecondDerivative::central(double* points, int point, int size, Accuracy accuracy, double delta_x){
	switch(accuracy){
		case Accuracy::Two:{
			if((point+1 < size) && (point-1 > -1)){
				return (points[point-1] - 2.0*points[point] + points[point+1])/std::pow(delta_x, 2);
			} else {
				std::cout << "Not possible to calculate second derivative - accuracy two - central to point " << point << ", with value " << points[point] << std::endl;
				
				if(point == 0) {
					std::cout << "Calculating with forward" << std::endl;
					return forward(points, point, size, Accuracy::Four, delta_x);
				} else if(point == size){
					std::cout << "Calculating with backward" << std::endl;
					return backward(points, point, size, Accuracy::Four, delta_x);
				}

				return 0;
			}
		}

		case Accuracy::Four:{
			if((point+2 < size) && (point-2 > -1)){
				return (-points[point-2]/12.0 + 4.0*points[point-1]/3.0 - 5.0*points[point]/2.0 + 4.0*points[point+1]/3.0 - 1.0*points[point+2]/12.0)/std::pow(delta_x, 2);
			} else {
				std::cout << "Not possible to calculate second derivative - accuracy four - central to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy Two" << std::endl;
				return central(points, point, size, Accuracy::Two, delta_x);
			}
			break;
		}

		case Accuracy::Six: {
			if((point+3 < size) && (point-3 > -1)){
				return (points[point-3]/90.0 - 3.0*points[point-2]/20.0 + 3.0*points[point-1]/2.0 - 49.0*points[point]/18.0 + 3.0*points[point+1]/2.0 - 3.0*points[point+2]/20.0 + points[point+3]/90.0)/std::pow(delta_x, 2);
			} else {
				std::cout << "Not possible to calculate second derivative - accuracy six - central for point " << point << ", with value " << points[point] << std::endl;
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

double SecondDerivative::forward(double* points, int point, int size, Accuracy accuracy, double delta_x) {
	switch( accuracy ) {
		case Accuracy::One : {
			if( point + 2 < size ) {
				return ( points[point] - 2.0*points[point + 1] + points[point + 2])/std::pow(delta_x, 2);
			} else {
				std::cout << "Not possible to calculate second derivative - accuracy one - forward to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with backward" << std::endl;

				return backward(points, point, size, Accuracy::Four, delta_x);
			}

			break;
		}

		case Accuracy::Two : {
			if( point + 3 < size ) {
				return ( 2.0*points[point] - 5.0*points[point + 1] + 4.0*points[point + 2] - points[point + 3])/std::pow(delta_x, 2);
			} else {
				std::cout << "Not possible to calculate second derivative - accuracy two - forward to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy One" << std::endl;
				return forward(points, point, size, Accuracy::One, delta_x);
			}

			break;
		}

		case Accuracy::Three : {
			if( point + 4 < size ) {
				return ( 35.0*points[point]/12.0 - 26.0*points[point + 1]/3 + 19.0*points[point + 2]/2.0 - 14.0*points[point + 3]/3.0 + 11.0*points[point + 4]/12)/std::pow(delta_x, 2);
			} else {
				std::cout << "Not possible to calculate second derivative - accuracy three - forward to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy Two" << std::endl;
				return forward(points, point, size, Accuracy::Two, delta_x);
			}

			break;
		}

		case Accuracy::Four : {
			if( point + 5 < size ) {
				return ( 15.0*points[point]/4.0 - 77.0*points[point + 1]/6.0 + 107.0*points[point + 2]/6.0 - 13.0*points[point + 3] + 61.0*points[point + 4]/12.0 - 5.0*points[point + 5]/6.0)/std::pow(delta_x, 2);
			} else {
				std::cout << "Not possible to calculate second derivative - accuracy four - forward to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy Three" << std::endl;
				return forward(points, point, size, Accuracy::Three, delta_x);
			}

			break;
		}

		default: {
			return 0;
			break;
		}		
	}
}

double SecondDerivative::backward(double* points, int point, int size, Accuracy accuracy, double delta_x) {
	switch( accuracy ) {
		case Accuracy::One : {
			if( point - 2 < size ) {
				return ( points[point] - 2.0*points[point - 1] + points[point - 2])/std::pow(delta_x, 2);
			} else {
				std::cout << "Not possible to calculate second derivative - accuracy one - forward to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with backward" << std::endl;

				return backward(points, point, size, Accuracy::Four, delta_x);
			}

			break;
		}

		case Accuracy::Two : {
			if( point - 3 < size ) {
				return ( 2.0*points[point] - 5.0*points[point - 1] + 4.0*points[point - 2] - points[point - 3])/std::pow(delta_x, 2);
			} else {
				std::cout << "Not possible to calculate second derivative - accuracy two - forward to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy One" << std::endl;
				return forward(points, point, size, Accuracy::One, delta_x);
			}

			break;
		}

		case Accuracy::Three : {
			if( point - 4 < size ) {
				return ( 35.0*points[point]/12.0 - 26.0*points[point - 1]/3 + 19.0*points[point - 2]/2.0 - 14.0*points[point - 3]/3.0 + 11.0*points[point - 4]/12)/std::pow(delta_x, 2);
			} else {
				std::cout << "Not possible to calculate second derivative - accuracy three - forward to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy Two" << std::endl;
				return forward(points, point, size, Accuracy::Two, delta_x);
			}

			break;
		}

		case Accuracy::Four : {
			if( point - 5 < size ) {
				return ( 15.0*points[point]/4.0 - 77.0*points[point - 1]/6.0 + 107.0*points[point - 2]/6.0 - 13.0*points[point - 3] + 61.0*points[point - 4]/12.0 - 5.0*points[point - 5]/6.0)/std::pow(delta_x, 2);
			} else {
				std::cout << "Not possible to calculate second derivative - accuracy four - forward to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy Three" << std::endl;
				return forward(points, point, size, Accuracy::Three, delta_x);
			}

			break;
		}

		default: {
			return 0;
			break;
		}		
	}
}