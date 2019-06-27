#ifndef VECTOR_H
#define VECTOR_H

class Vector {
public:
	Vector( int size, bool zeros = false );

	void addElement( int index, double value );

	void normalize();

	Vector* newNormalized();

	double getElement(int index);

	int getSize();

	double operator * (Vector* v);

	Vector* operator - (Vector* v);

	void print();

	Vector* copy();

	double length();
private:
	int size_;
	double* content_;
};

#endif