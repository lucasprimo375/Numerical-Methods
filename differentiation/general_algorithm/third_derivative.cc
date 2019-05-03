#include <iostream>
#include <cmath>

#include "third_derivative.h"

double ThirdDerivative::central(double* points, int point, int size, Accuracy accuracy, double delta_x){
	switch(accuracy){
		case Accuracy::Two:{
			if((point+2 < size) && (point-2 > -1)){
				return (-points[point - 2]/2.0 + points[point - 1] - points[point + 1] + points[point + 2]/2.0)/std::pow(delta_x, 3);
			} else {
				std::cout << "Not possible to calculate third derivative - accuracy two - central to point " << point << ", with value " << points[point] << std::endl;
				
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
			if((point+3 < size) && (point-3 > -1)){
				return (points[point-3]/8.0 - points[point-2] + 13.0*points[point-1]/8.0 - 13.0*points[point+1]/8.0 + points[point+2] - points[point+3]/8)/std::pow(delta_x, 3);
			} else {
				std::cout << "Not possible to calculate third derivative - accuracy four - central to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy Two" << std::endl;
				return central(points, point, size, Accuracy::Two, delta_x);
			}
			break;
		}

		case Accuracy::Six: {
			if((point+4 < size) && (point-4 > -1)){
				return (-7.0*points[point-4]/240.0 + 3.0*points[point-3]/10.0 - 169.0*points[point-2]/120.0 + 61.0*points[point-1]/30.0 - 61.0*points[point+1]/30.0 + 169.0*points[point+2]/120.0 - 3.0*points[point+3]/10.0 + 7.0*points[point+4]/240.0)/std::pow(delta_x, 2);
			} else {
				std::cout << "Not possible to calculate third derivative - accuracy six - central for point " << point << ", with value " << points[point] << std::endl;
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

double ThirdDerivative::forward(double* points, int point, int size, Accuracy accuracy, double delta_x) {
	switch( accuracy ) {
		case Accuracy::One : {
			if( point + 3 < size ) {
				return ( -points[point] + 3.0*points[point + 1] - 3.0*points[point + 2] + points[point+3])/std::pow(delta_x, 3);
			} else {
				std::cout << "Not possible to calculate third derivative - accuracy one - forward to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with backward" << std::endl;

				return backward(points, point, size, Accuracy::Four, delta_x);
			}

			break;
		}

		case Accuracy::Two : {
			if( point + 4 < size ) {
				return ( -5.0*points[point]/2.0 + 9.0*points[point + 1] - 12.0*points[point + 2] + 7.0*points[point + 3] - 3.0*points[point+4]/2.0)/std::pow(delta_x, 3);
			} else {
				std::cout << "Not possible to calculate third derivative - accuracy two - forward to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy One" << std::endl;
				return forward(points, point, size, Accuracy::One, delta_x);
			}

			break;
		}

		case Accuracy::Three : {
			if( point + 5 < size ) {
				return ( -17.0*points[point]/4.0 + 71.0*points[point + 1]/4 - 59.0*points[point + 2]/2.0 + 49.0*points[point + 3]/2.0 - 41.0*points[point + 4]/4.0 + 7.0*points[point+5])/std::pow(delta_x, 3);
			} else {
				std::cout << "Not possible to calculate third derivative - accuracy three - forward to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy Two" << std::endl;
				return forward(points, point, size, Accuracy::Two, delta_x);
			}

			break;
		}

		case Accuracy::Four : {
			if( point + 6 < size ) {
				return ( -49.0*points[point]/8.0 + 29.0*points[point + 1] - 461.0*points[point + 2]/8.0 + 62.0*points[point + 3] - 307.0*points[point + 4]/8.0 + 13.0*points[point + 5] - 15.0*points[point+6]/8)/std::pow(delta_x, 3);
			} else {
				std::cout << "Not possible to calculate third derivative - accuracy four - forward to point " << point << ", with value " << points[point] << std::endl;
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

double ThirdDerivative::backward(double* points, int point, int size, Accuracy accuracy, double delta_x) {
	switch( accuracy ) {
		case Accuracy::One : {
			if( point - 3 > -1 ) {
				return ( points[point] - 3.0*points[point + 1] + 3.0*points[point + 2] - points[point+3])/std::pow(delta_x, 3);
			} else {
				std::cout << "Not possible to calculate third derivative - accuracy one - forward to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with backward" << std::endl;

				return backward(points, point, size, Accuracy::Four, delta_x);
			}

			break;
		}

		case Accuracy::Two : {
			if( point - 4 > -1 ) {
				return ( 5.0*points[point]/2.0 - 9.0*points[point + 1] + 12.0*points[point + 2] - 7.0*points[point + 3] + 3.0*points[point+4]/2.0)/std::pow(delta_x, 3);
			} else {
				std::cout << "Not possible to calculate third derivative - accuracy two - forward to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy One" << std::endl;
				return forward(points, point, size, Accuracy::One, delta_x);
			}

			break;
		}

		case Accuracy::Three : {
			if( point - 5 > -1 ) {
				return ( 17.0*points[point]/4.0 - 71.0*points[point + 1]/4 + 59.0*points[point + 2]/2.0 - 49.0*points[point + 3]/2.0 + 41.0*points[point + 4]/4.0 - 7.0*points[point+5])/std::pow(delta_x, 3);
			} else {
				std::cout << "Not possible to calculate third derivative - accuracy three - forward to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy Two" << std::endl;
				return forward(points, point, size, Accuracy::Two, delta_x);
			}

			break;
		}

		case Accuracy::Four : {
			if( point - 6 > -1 ) {
				return ( 49.0*points[point]/8.0 - 29.0*points[point + 1] + 461.0*points[point + 2]/8.0 - 62.0*points[point + 3] + 307.0*points[point + 4]/8.0 - 13.0*points[point + 5] + 15.0*points[point+6]/8)/std::pow(delta_x, 3);
			} else {
				std::cout << "Not possible to calculate third derivative - accuracy four - forward to point " << point << ", with value " << points[point] << std::endl;
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