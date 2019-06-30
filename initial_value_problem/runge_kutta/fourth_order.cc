#include <iostream>

#include "fourth_order.h"
#include "functions.h"

using namespace Functions;

FourthOrder::FourthOrder(double initial_y, double initial_derivative, int steps, double step_size){
	n_ = steps;

	y_ = new double[n_];
	y_[0] = initial_y;

	z_ = new double[n_];
	z_[0] = initial_derivative;

	x_ = new double[n_];
	for(int i = 0; i < n_; i++)
		x_[i] = step_size*i;

	h_ = step_size;
}

void FourthOrder::solve() {
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

	for(int i = 0; i < n_; i++){
		std::cout << "x[" << i << "] = " << x_[i] << std::endl;
		std::cout << "y[" << i << "] = " << y_[i] << std::endl;
		std::cout << "z[" << i << "] = " << z_[i] << std::endl;
		
		if( i != n_ - 1)
			std::cout << std::endl;
	}
}

double FourthOrder::dy_dx(double x, double y, double w){
	return w;
}

double FourthOrder::dw_dx(double x, double y, double w){
	return -f(x)*w - g(x)*y + z(x);
}