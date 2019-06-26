all: main.o user_input.o methods_executer.o utils.o matrix.o vector.o
	g++ -o main main.o user_input.o methods_executer.o utils.o matrix.o vector.o

main.o: main.cc methods.h user_input.h utils.h matrix.h methods_executer.h vector.h
	g++ -c main.cc -std=c++11

user_input.o: user_input.cc user_input.h methods.h vector.h
	g++ -c user_input.cc -std=c++11

methods_executer.o: methods_executer.cc methods_executer.h methods.h matrix.h
	g++ -c methods_executer.cc -std=c++11

utils.o: utils.cc utils.h matrix.h
	g++ -c utils.cc -std=c++11

matrix.o: matrix.cc matrix.h vector.h
	g++ -c matrix.cc

vector.o: vector.cc vector.h
	g++ -c vector.cc