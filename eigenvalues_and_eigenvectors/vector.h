#ifndef VECTOR_H
#define VECTOR_H

class Vector {
public:
	Vector( int size );

	void addElement( int index, double value );

	void normalize();

	Vector* newNormalized();

	double getElement(int index);

	int getSize();

	double operator * (Vector* v);

	void print();
private:
	double length();

	int size_;
	double* content_;
};

#endif