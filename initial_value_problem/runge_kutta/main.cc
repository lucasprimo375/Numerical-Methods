#include <iostream>
#include <iomanip>

#include "fourth_order.h"

int main(){
	std::cout << std::fixed << std::setprecision(10);

	double initial_x = 0;
	double initial_y = 0;
	double initial_derivative = 0;
	double target = 1.2;
	double step_size = 0.1;
	double tolerance = 0.0000001;

	FourthOrder fourthOrder(initial_x, initial_y, initial_derivative, target, step_size, tolerance);

	fourthOrder.solve();

	std::cout << std::endl << "This program solves initial value problem for linear second order ordinary differential equation with Fourth Order Runge-Kutta" << std::endl;
	std::cout << "It solves equation in the form y'' + f(x)*y' + g(x)*y = z(x) with initial values for y and y'' of course" << std::endl;
	std::cout << "You may change f, g and z in the file functions.cc. Then, you must compile the program again by running 'make all'. Finally, you can execute it by running './main'" << std::endl;

	return 0;
}