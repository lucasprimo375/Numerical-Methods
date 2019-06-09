#include <iostream>
#include <string>

#include "user_input.h"
#include "utils.h"

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
        std::cout << "Input derivative choice - 1, 2 or 3." << std::endl;
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
        
        default:
        	return Derivative::First;
    }
}

Accuracy get_user_accuracy_choice() {
	int choice = 0;

    while((choice < 1) || (choice > 6)){
        std::cout << "Input accuracy choice - 1, 2, 3, 4, 5, 6. Be aware that some accuracies are not available for some methods" << std::endl;
        std::cout << ">> ";

        std::cin >> choice;
    }

    switch(choice){
        case 1:
            return Accuracy::One;

        case 2:
            return Accuracy::Two;

        case 3:
            return Accuracy::Three;

        case 4:
            return Accuracy::Four;

        case 5:
            return Accuracy::Five;

        case 6:
            return Accuracy::Six;
        
        default:
        	return Accuracy::One;
    }	
}

std::string get_output_file_name_from_user() {
    std::string file_name;

    std::cout << "Input the output file name: ";    

    std::cin >> file_name;

    return file_name;
}

Philosophy get_philosophy_from_user() {
    int choice = 0;

    while( (choice < 1) || (choice > 3) ) {
        std::cout << "Input the philosophy" << std::endl;
        std::cout << "1 - Backward, 2 - Central, 3 - Forward" << std::endl;
        std::cout << ">> ";
        std::cin >> choice; 
    }

    switch( choice ) {
        case 1: return Philosophy::Backward;

        case 2: return Philosophy::Central;

        case 3: return Philosophy::Forward;

        default: return Philosophy::Central;
    }
}