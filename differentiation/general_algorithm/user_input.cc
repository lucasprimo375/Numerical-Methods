#include <iostream>
#include <string>

#include "user_input.h"

std::string get_file_global_path() {
	std::string file_name;

	std::cout << "Input file global path: ";

	std::cin >> file_name;

	return file_name;
}

int get_number_of_points(){
	int number_of_points = -1;
	
	while(number_of_points < 1){
		std::cout << "Input number of points: ";
		
		std::cin >> number_of_points;
	}
	
	return number_of_points;
}

double get_delta_x() {
	double delta_x = 0;

	while( delta_x <= 0 ) {
		std::cout << "Input delta x: ";

		std::cin >> delta_x;
	}

	return delta_x;
}


Derivative get_user_derivative_choice() {
    int choice = 0;

    while((choice < 1) || (choice > 3)){
        std::cout << "Input derivative choice. 1, 2 or 3." << std::endl;
        std::cout << ">> ";

        std::cin >> choice;
    }

    switch(choice){
        case 1:
            return Derivative::First;

        case 2:
            return Derivative::Second;

        case 3:
            return Derivative::Third;
    }
}