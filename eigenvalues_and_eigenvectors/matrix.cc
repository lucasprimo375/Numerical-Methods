#include <iostream>
#include <iomanip>

#include "matrix.h"
#include "vector.h"

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
	for( int i = 0; i < rows_; i++ ) {
		for( int j = 0; j < columns_; j++ ) {
			if( ( i != j ) && ( content_[i][j] != content_[j][i] ) )
				return false;
		}
	}

	return true;
}

void Matrix::print() {
	std::cout << std::fixed << std::setprecision(6);

	for( int i = 0; i < rows_; i++ ) {
		for( int j = 0; j < columns_; j++ ) {
			std::cout << content_[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

Vector* Matrix::operator * (Vector* v) {
	Vector* u = new Vector(v->getSize());

	for( int i = 0; i < v->getSize(); i++ ){
		double sum = 0;

		for( int j = 0; j < v->getSize(); j++ )
			sum += content_[i][j] * v->getElement(j);
		
		u->addElement(i, sum);
	}

	return u;
}

int Matrix::getSize(){
	return rows_;
}