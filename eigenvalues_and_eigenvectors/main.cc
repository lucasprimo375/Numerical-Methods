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

	std::cout << std::endl << "Printing matrix in given file" << std::endl << std::endl;

	matrix->print();

	if( !matrix->isSymmetric() ) {
		std::cout << std::endl << "The input matrix is not symmetric" << std::endl;
		std::cout << "The methods implemented here require the matrix to be symmetric in order to produce acceptable results" << std::endl;

		return 1;
	}

	return 0;
}