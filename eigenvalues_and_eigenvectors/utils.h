#ifndef UTILS_H
#define UTILS_H

#include <string>

#include "matrix.h"

namespace Utils {
	Matrix* readMatrixFile(std::string file_name, int matrix_size);

	bool addLineToMatrix(std::string line, Matrix* matrix, int row, int matrix_size);

	Matrix* generateIdentityMatrix(int size);

	Matrix* generateShiftedPowerMethodMatrix(Matrix* matrix, double lambda_0);
};

#endif