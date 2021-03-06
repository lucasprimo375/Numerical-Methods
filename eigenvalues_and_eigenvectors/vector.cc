#include <cmath>
#include <iomanip>
#include <iostream>

#include "vector.h"

Vector::Vector( int size, bool zeros ) {
	size_ = size;

	content_ = new double[size_];

	if( zeros ) {
		for( int i = 0; i < size_; i++ )
			content_[i] = 0;
	}
}

void Vector::addElement( int index, double value ) {
	if( index < size_ ) content_[index] = value;
}

void Vector::normalize() {
	double len = length();

	for( int i = 0; i < size_; i++ )
		content_[i] /= len;
}

Vector* Vector::newNormalized() {
	Vector* v = new Vector(size_);

	for( int i = 0; i < size_; i++ )
		v->addElement(i, content_[i]);

	v->normalize();

	return v;
}

double Vector::getElement(int index){
	return content_[index];
}

int Vector::getSize(){
	return size_;
}

double Vector::operator * (Vector* v){
	double sum = 0;

	for( int i = 0; i < size_; i++ )
		sum += content_[i] * v->getElement(i);

	return sum;
}

Vector* Vector::operator - (Vector* v) {
	Vector* u = new Vector( size_ );

	for( int i = 0; i < size_; i++ )
		u->addElement( i, content_[i] - v->getElement(i) );

	return u;
}

void Vector::print(){
	std::cout << std::fixed << std::setprecision(6);

	for( int i = 0; i < size_; i++ ) {
		std::cout << content_[i] << " ";
	}

	std::cout << std::endl;
}

Vector* Vector::copy() {
	Vector* v = new Vector( size_ );

	for( int i = 0; i < size_; i++ )
		v->addElement(i, content_[i]);

	return v;
}

double Vector::length() {
	double sum = 0;

	for( int i = 0; i < size_; i++ )
		sum += std::pow(content_[i], 2.0);

	return std::sqrt(sum);
}