#include <iostream>

#include "first_derivative.h"

double FirstDerivative::central(double* points, int point, int size, Accuracy accuracy){
	switch(accuracy){
		case Accuracy::One:{
			if((point+1 < size) && (point-1 > -1)){
				return points[point+1]/2.0 - points[point-1]/2.0;
			} else {
				std::cout << "Not possible to calculate first derivative - accuracy one - central to point " << point << ", with value " << points[point] << std::endl;
				std::cout << "Returning zero" << std::endl;
				return 0;
			}
		}
	}
}
