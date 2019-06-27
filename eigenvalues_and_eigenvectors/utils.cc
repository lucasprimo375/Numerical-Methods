#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>

#include "utils.h"
#include "matrix.h"

Matrix* Utils::readMatrixFile(std::string file_name, int matrix_size) {
	std::ifstream matrix_stream;

	matrix_stream.open( file_name.c_str(), std::ifstream::in );

	if( !matrix_stream ) return nullptr;

	Matrix* matrix = new Matrix(matrix_size, matrix_size);

	std::string line;

	int row = 0;

	while( std::getline( matrix_stream, line ) ) {
		bool isMalFormed = Utils::addLineToMatrix(line, matrix, row, matrix_size);

		if( isMalFormed ) return nullptr;

		row++;
	}

	return matrix;
}

bool Utils::addLineToMatrix(std::string line, Matrix* matrix, int row, int matrix_size) {
	try {
		int column = 0;

		std::string delimiter = " ";

		size_t pos = line.find(delimiter);

		while( (pos != std::string::npos) && (column < matrix_size) ) {
			std::string token = line.substr(0, pos);

			matrix->addElement(row, column, std::stod(token));

			line = line.substr(pos + 1, line.size() - pos);

			pos = line.find(delimiter);

			column++;
		}

		if( column != matrix_size - 1 ) return true;

		matrix->addElement(row, column, std::stod(line));

		return false;
	} catch( std::invalid_argument e ) {
		return true;
	}
}

Matrix* Utils::generateIdentityMatrix(int size) {
	Matrix* A = new Matrix(size, size);

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if( i == j ) A->addElement(i, j, 1);
			else A->addElement(i, j, 0);
		}
	}

	return A;
}

Matrix* Utils::generateShiftedPowerMethodMatrix(Matrix* matrix, double lambda_0) {
	Matrix* I = Utils::generateIdentityMatrix( matrix->getSize() );

	Matrix* A = (*I) * lambda_0;

	return (*matrix) - A;
}