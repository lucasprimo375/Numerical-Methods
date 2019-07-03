#include "functions.h"
#include <iostream>

double Functions::f(double x){
	return -1.0/x;
}

double Functions::g(double x){
	return 0.0;	
}

double Functions::z(int* v, double x){
	return -((double)(v[3]+v[4]+v[5]))/((double)(v[0]+v[1]+v[2]));
}