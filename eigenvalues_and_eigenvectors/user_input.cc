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

	switch( choice ) {
		case 1: return Method::RegularPowerMethod;

		case 2: return Method::InversePowerMethod;
	
		case 3: return Method::DisplacementPowerMethod;
	
		case 4: return Method::HouseHolderMethod;
	
		case 5: return Method::JacobiMethod;

		case 6: return Method::QRMethod;

		default: Method::RegularPowerMethod;
	}
}

std::string UserInput::get_matrix_file() {
	std::string file_name = "";

	std::ifstream matrix_file_stream;

	while( file_name != "" ) {
		std::cout << "Input matrix file name" << std::endl;
		std::cout << ">> ";
		std::cin >> file_name;

		matrix_file_stream.open( file_name.c_str(), std::ifstream::in );

		if( !matrix_file_stream ) {
			file_name = "";
		}
	}

	return file_name;
}

int get_matrix_size() {
	int size = 0;

	while( size <= 0 ) {
		std::cout << "Input matrix size" << std::endl;
		std::cout << ">> ";
		std::cin >> size;
	}

	return size;
}