#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:
	Matrix(int rows, int columns_);

	void addElement(int row, int column, double value);

	bool isSymmetric();

	void print();
private:
	double** content_;

	int rows_;
	int columns_;
};

#endif