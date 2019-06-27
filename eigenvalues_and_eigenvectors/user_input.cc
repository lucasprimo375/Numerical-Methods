#include <iostream>
#include <fstream>

#include "user_input.h"
#include "methods.h"
#include "vector.h"

Method UserInput::get_method() {
	int choice = 0;

	while( (choice < 1) || (choice > 6) ) {
		std::cout << std::endl << "Input desired method" << std::endl;
		std::cout << "1 - Regular Power Method, 2 - Inverse Power Method, 3 - Shifted Power Method, 4 - House Holder Method, 5 - Jacobi Method, 6 - QR Method" << std::endl;
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
			method = Method::ShiftedPowerMethod;
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

double UserInput::get_precision() {
	double precision = -1;

	while( precision <= 0 ) {
		std::cout << std::endl << "Input the desired precision" << std::endl;
		std::cout << ">> ";
		std::cin >> precision;
	}

	return precision;
}

Vector* UserInput::get_initial_guess(int size){
	Vector* v = new Vector(size);

	std::cout << std::endl << "Input initial guess" << std::endl;

	for( int i = 0; i < size; i++ ) {
		std::cout << "Input element " << i << std::endl;
		std::cout << ">> ";

		double element;
		std::cin >> element;

		v->addElement(i, element);
	}

	return v;
}

double UserInput::get_initial_eigenvalue() {
	double eigenvalue;

	std::cout << std::endl << "Input the initial eigenvalue" << std::endl;
	std::cout << ">> ";
	std::cin >> eigenvalue;

	return eigenvalue;
}