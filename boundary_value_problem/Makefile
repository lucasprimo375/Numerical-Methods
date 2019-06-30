all: functions.o boundary_value_problem_solver.o gauss_solver.o main.o
	g++ -o main main.o functions.o boundary_value_problem_solver.o gauss_solver.o

main.o: main.cc boundary_value_problem_solver.h
	g++ -c main.cc

functions.o: functions.cc functions.h
	g++ -c functions.cc

boundary_value_problem_solver.o: boundary_value_problem_solver.cc boundary_value_problem_solver.h gauss_solver.h
	g++ -c boundary_value_problem_solver.cc

gauss_solver.o: gauss_solver.cc gauss_solver.h
	g++ -c gauss_solver.cc