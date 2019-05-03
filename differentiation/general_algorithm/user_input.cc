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