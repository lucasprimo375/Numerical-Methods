#ifndef FOURTH_ORDER_H
#define FOURTH_ORDER_H

class FourthOrder {
public:
	FourthOrder(double initial_y, double initial_derivative, int steps, double step_size);

	void solve();

private:
	double dy_dx(double x, double y, double w);

	double dw_dx(double x, double y, double w);

	double* y_;
	double* z_;
	double* x_;

	int n_;
	double h_;
};

#endif