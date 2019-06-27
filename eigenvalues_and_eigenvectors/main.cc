#include <string>
#include <iostream>

#include "methods.h"
#include "user_input.h"
#include "utils.h"
#include "matrix.h"
#include "methods_executer.h"
#include "vector.h"

int main() {
	Method method = UserInput::get_method();
	std::string matrix_file = UserInput::get_matrix_file();
	int matrix_size = UserInput::get_matrix_size();
	double precision = UserInput::get_precision();

	Matrix* matrix = Utils::readMatrixFile(matrix_file, matrix_size);

	if( matrix == nullptr ) {
		std::cout << std::endl << "There was an error while trying to read the matrix" << std::endl;
		std::cout << "Your file does not exist, our could not be read or your matrix is malformed" << std::endl;
		
		return 1;
	}

	std::cout << std::endl << "Printing matrix in given file" << std::endl << std::endl;

	matrix->print();

	/*if( !matrix->isSymmetric() ) {
		std::cout << std::endl << "The input matrix is not symmetric" << std::endl;
		std::cout << "The methods implemented here require the matrix to be symmetric in order to produce acceptable results" << std::endl;

		return 1;
	}*/

	Vector* x_0 = nullptr;
	double lambda_0;

	if( (method == Method::RegularPowerMethod) || (method == Method::InversePowerMethod) || (method == Method::ShiftedPowerMethod) )
		x_0 = UserInput::get_initial_guess(matrix->getSize());

	if(method == Method::ShiftedPowerMethod)
		lambda_0 = UserInput::get_initial_eigenvalue();

	MethodsExecuter::execute_method( method, matrix, precision, x_0, lambda_0 );

	return 0;
}