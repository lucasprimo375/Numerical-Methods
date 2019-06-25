#include <string>
#include <iostream>

#include "methods.h"
#include "user_input.h"
#include "utils.h"
#include "matrix.h"

int main() {
	Method method = UserInput::get_method();
	std::string matrix_file = UserInput::get_matrix_file();
	int matrix_size = UserInput::get_matrix_size();

	Matrix* matrix = Utils::readMatrixFile(matrix_file, matrix_size);

	if( matrix == nullptr ) {
		std::cout << std::endl << "There was an error while trying to read the matrix" << std::endl;
		std::cout << "Your file does not exist, our could not be read or your matrix is malformed" << std::endl;
		
		return 1;
	}

	matrix->print();

	return 0;
}