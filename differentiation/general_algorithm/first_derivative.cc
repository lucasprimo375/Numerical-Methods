#include <iostream>

#include "first_derivative.h"

double FirstDerivative::central(double* points, int point, int size, Accuracy accuracy){
	switch(accuracy){
		case Accuracy::Two:{
			if((point+1 < size) && (point-1 > -1)){
				return points[point+1]/2.0 - points[point-1]/2.0;
			} else {
				std::cout << "Not possible to calculate first derivative - accuracy two - central to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Returning zero" << std::endl;
				return 0;
			}
		}

		case Accuracy::Four:{
			if((point+2 < size) && (point-2 > -1)){
				return points[point-2]/12.0 - 2.0*points[point-1]/3.0 + 2.0*points[point+1]/3.0 - 1.0*points[point+2]/12.0;
			} else {
				std::cout << "Not possible to calculate first derivative - accuracy four - central to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy Two" << std::endl;
				return central(points, point, size, Accuracy::Two);
			}
			break;
		}

		case Accuracy::Six: {
			if((point+3 < size) && (point-3 > -1)){
				return -points[point-3]/60.0 + 3.0*points[point-2]/20.0 - 3.0*points[point-1]/4.0 + 3.0*points[point+1]/4.0 - 3.0*points[point+2]/20.0 + points[point+3]/60.0;
			} else {
				std::cout << "Not possible to calculate first derivative - accuracy six - central for point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Calculating with accuracy Four" << std::endl;
				return central(points, point, size, Accuracy::Four);
			}
			break;
		}

		default: {
			return 0;
			break;
		}
	}
}
