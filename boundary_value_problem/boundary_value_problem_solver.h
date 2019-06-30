#ifndef BOUNDARY_VALUE_PROBLEM_SOLVER_H
#define BOUNDARY_VALUE_PROBLEM_SOLVER_H

class BoundaryValueProblemSolver {
public:
	BoundaryValueProblemSolver(double a, double b, int n);

	void solve(double c1, double c2);
private:
	double x(int i);

	double a_;
	double b_;
	double h_;
	int n_;
};

#endif