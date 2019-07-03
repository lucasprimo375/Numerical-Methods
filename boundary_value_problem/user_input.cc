#include <iostream>
#include <fstream>

#include "user_input.h"

int* UserInput::get_values() {
	int size = 6;
	int* v = new int[size];

	std::cout << std::endl << "Input values" << std::endl;

	for( int i = 0; i < size; i++ ) {
		std::cout << "Input element " << i << std::endl;
		std::cout << ">> ";

		int element;
		std::cin >> element;

		v[i] = element;
	}
	
	return v;
}