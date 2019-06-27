all: main.o user_input.o methods_executer.o utils.o matrix.o vector.o gauss_solver.o
	g++ -o main main.o user_input.o methods_executer.o utils.o matrix.o vector.o gauss_solver.o

main.o: main.cc methods.h user_input.h utils.h matrix.h methods_executer.h vector.h
	g++ -c main.cc -std=c++11

user_input.o: user_input.cc user_input.h methods.h vector.h
	g++ -c user_input.cc -std=c++11

methods_executer.o: methods_executer.cc methods_executer.h methods.h matrix.h gauss_solver.h utils.h
	g++ -c methods_executer.cc -std=c++11

utils.o: utils.cc utils.h matrix.h vector.h
	g++ -c utils.cc -std=c++11

matrix.o: matrix.cc matrix.h vector.h
	g++ -c matrix.cc

vector.o: vector.cc vector.h
	g++ -c vector.cc

gauss_solver.o: gauss_solver.cc gauss_solver.h vector.h matrix.h
	g++ -c gauss_solver.cc -std=c++11