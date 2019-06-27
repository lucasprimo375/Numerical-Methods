#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

class Matrix {
public:
	Matrix(int rows, int columns_);

	void addElement(int row, int column, double value);

	bool isSymmetric();

	void print();

	Vector* operator * (Vector* v);

	int getSize();

	Matrix* copy();

	double getElement( int row, int column );
private:
	double** content_;

	int rows_;
	int columns_;
};

#endif