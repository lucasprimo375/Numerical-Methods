#include <cmath>
#include <functional>
#include <iostream>

#include "exp_method.h"
#include "newton_cotes.h"
#include "closed_two.h"

const double kInitialGuess = 0.001;
const double kAddGuess = 0.001;

ExpMethod::ExpMethod(double a, double b) {
	a_ = a;
	b_ = b;
}

double ExpMethod::execute(double precision_1, double precision_2) {
	NewtonCotes* newton_cotes = new ClosedTwo();

	double c = kInitialGuess;

	std::function<double(double)> f = [this](double s) -> double {
		return this->g_s(s);
	};

	double I_new = newton_cotes->estimate(-c, c, precision_2, f);
	double I;

	do {
		I = I_new;

		c += kAddGuess;

		I_new = newton_cotes->estimate(-c, c, precision_2, f);

		std::cout << "std::abs((I_new - I)/I_new) : " << std::abs((I_new - I)/I_new) << std::endl;
	} while( std::abs((I_new - I)/I_new) > precision_1 );

	return I_new;
}

double ExpMethod::f(double x) {
	return 1.0/x;
}

double ExpMethod::g_s(double s) {
	return f(x_s(s))/dx_ds(s);
}