#ifndef FOURTH_ORDER_H
#define FOURTH_ORDER_H

class FourthOrder {
public:
	FourthOrder(double initial_x, double initial_y, double initial_derivative, double target, double step_size, double tolerance);

	void solve();

	double solve_iterative();

private:
	double dy_dx(double x, double y, double w);

	double dw_dx(double x, double y, double w);

	double* y_;
	double* z_;
	double* x_;

	int n_;
	double h_;

	double tolerance_;

	double target_;

	double initial_x_;
	double initial_y_;
	double initial_derivative_;
};

#endif