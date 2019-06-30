#include <iostream>
#include <iomanip>

#include "boundary_value_problem_solver.h"

int main(){
	std::cout << std::endl << "This program computes boundary value problems of equations in the form in the picture form.png using finite differences method" << std::endl;
	std::cout << "You can change functions f, g and z in the file functions.cpp" << std::endl;
	std::cout << "You may also change the boundary conditions in the file main.cpp" << std::endl;
	std::cout << "After you are done with your changes, you must compile the program again by running 'make all'. Then you can execute it by running './main'" << std::endl;

	int numberOfPartitions = 4;

	double boundaryCondition1 = 0.0;
	double boundaryCondition2 = 0.0;

	double lowerInterval1 = 0.2;
	double lowerInterval2 = 0.5;

	std::cout << std::fixed << std::setprecision(6);

	BoundaryValueProblemSolver boundaryValueProblemSolver(lowerInterval1, lowerInterval2, numberOfPartitions);

	boundaryValueProblemSolver.solve(boundaryCondition1, boundaryCondition1);

	return 0;
}