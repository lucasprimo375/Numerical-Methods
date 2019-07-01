#include <iostream>
#include <cmath>

#include "fourth_order.h"
#include "functions.h"

using namespace Functions;

FourthOrder::FourthOrder(double initial_x, double initial_y, double initial_derivative, double target, double step_size, double tolerance){
	h_ = step_size;

	tolerance_ = tolerance;

	target_ = target;

	initial_x_ = initial_x;

	initial_y_ = initial_y;

	initial_derivative_ = initial_derivative;
}

void FourthOrder::solve(){
	double y_new = solve_iterative();

	double y_old;

	int iteration_count = 0;

	do{
		std::cout << std::endl << "ITERATION " << iteration_count << std::endl;
		std::cout << "Step size is " << h_ << std::endl;
		std::cout << "y is " << y_new << std::endl;

		y_old = y_new;

		h_ /= 2.0;

		y_new = solve_iterative();

		iteration_count++;
	}while( std::abs((y_new - y_old)/y_new) > tolerance_ );

	std::cout << std::endl << "Final step size is " << h_ << std::endl;
	std::cout << "Final y is " << y_new << std::endl;
}

double FourthOrder::solve_iterative() {
	n_ = std::ceil((target_ - initial_x_)/h_) + 1;

	y_ = new double[n_];
	y_[0] = initial_y_;

	z_ = new double[n_];
	z_[0] = initial_derivative_;

	x_ = new double[n_];
	for(int i = 0; i < n_; i++)
		x_[i] = initial_x_ + h_*i;

	for(int i = 1; i < n_; i++){
		double k_0 = h_*dy_dx(x_[i - 1], y_[i - 1], z_[i - 1]);
		double l_0 = h_*dw_dx(x_[i - 1], y_[i - 1], z_[i - 1]);

		double k_1 = h_*dy_dx(x_[i - 1] + h_/2.0, y_[i - 1] + k_0/2.0, z_[i - 1] + l_0/2.0);
		double l_1 = h_*dw_dx(x_[i - 1] + h_/2.0, y_[i - 1] + k_0/2.0, z_[i - 1] + l_0/2.0);

		double k_2 = h_*dy_dx(x_[i - 1] + h_/2.0, y_[i - 1] + k_1/2.0, z_[i - 1] + l_1/2.0);
		double l_2 = h_*dw_dx(x_[i - 1] + h_/2.0, y_[i - 1] + k_1/2.0, z_[i - 1] + l_1/2.0);

		double k_3 = h_*dy_dx(x_[i - 1] + h_, y_[i - 1] + k_2, z_[i - 1] + l_2);
		double l_3 = h_*dw_dx(x_[i - 1] + h_, y_[i - 1] + k_2, z_[i - 1] + l_2);

		y_[i] = y_[i - 1] + (k_0 + 2.0*k_1 + 2.0*k_2 + k_3)/6.0;
		z_[i] = z_[i - 1] + (l_0 + 2.0*l_1 + 2.0*l_2 + l_3)/6.0;
	}

	return y_[n_ - 1];
}

double FourthOrder::dy_dx(double x, double y, double w){
	return w;
}

double FourthOrder::dw_dx(double x, double y, double w){
	return -f(x)*w - g(x)*y + z(x);
}