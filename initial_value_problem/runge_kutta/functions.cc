#include "functions.h"

double Functions::f(double x) {
	return 0.2;
}

double Functions::g(double x) {
	return 4.0;
}

double Functions::z(double x) {
	if(x >= 0 && x <= 0.5) return 4.0*x;
	else if(x > 0.5 && x <= 1) return -4.0*x + 4.0;
	else return 0;
}