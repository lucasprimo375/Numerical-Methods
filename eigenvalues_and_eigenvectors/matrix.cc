#include "matrix.h"

Matrix::Matrix(int rows, int columns) {
	rows_ = rows;
	columns_ = columns;

	content_ = new double*[rows_];

	for( int i = 0; i < rows_; i++ ) {
		content_[i] = new double[columns_];
	}
}

void Matrix::addElement(int row, int column, double value) {
	if( (row < rows_) && (column < columns_) && (row >= 0) && (column >= 0) )
		content_[row][column] = value;
}

bool Matrix::isSymmetric() {
	
}