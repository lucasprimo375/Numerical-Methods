#include <iostream>
#include <fstream>

#include "user_input.h"
#include "methods.h"

Method UserInput::get_method() {
	int choice = 0;

	while( (choice < 1) || (choice > 6) ) {
		std::cout << std::endl << "Input desired method" << std::endl;
		std::cout << "1 - Regular Power Method, 2 - Inverse Power Method, 3 - Displacement Power Method, 4 - House Holder Method, 5 - Jacobi Method, 6 - QR Method" << std::endl;
		std::cout << ">> ";
		std::cin >> choice;
	}

	Method method;

	switch( choice ) {
		case 1: 
			method = Method::RegularPowerMethod;
			break;

		case 2: 
			method = Method::InversePowerMethod;
			break;
	
		case 3: 
			method = Method::DisplacementPowerMethod;
			break;
	
		case 4: 
			method = Method::HouseHolderMethod;
			break;
	
		case 5: 
			method = Method::JacobiMethod;
			break;

		case 6: 
			method = Method::QRMethod;
			break;

		default: 
			method = Method::RegularPowerMethod;
			break;
	}

	return method;
}

std::string UserInput::get_matrix_file() {
	std::string file_name = "";

	std::ifstream matrix_file_stream;

	while( file_name == "" ) {
		std::cout << std::endl << "Input matrix file name" << std::endl;
		std::cout << ">> ";
		std::cin >> file_name;

		matrix_file_stream.open( file_name.c_str(), std::ifstream::in );

		if( !matrix_file_stream ) {
			std::cout << std::endl << "Your file could not be opened or does not exist" << std::endl;
			file_name = "";
		}
	}

	return file_name;
}

int UserInput::get_matrix_size() {
	int size = 0;

	while( size <= 0 ) {
		std::cout << std::endl << "Input matrix size" << std::endl;
		std::cout << ">> ";
		std::cin >> size;
	}

	return size;
}