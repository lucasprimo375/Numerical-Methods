all: main.o user_input.o methods_executer.o utils.o matrix.o
	g++ -o main main.o user_input.o methods_executer.o utils.o matrix.o

main.o: main.cc
	g++ -c main.cc

user_input.o: user_input.cc user_input.h methods.h
	g++ -c user_input.cc -std=c++11

methods_executer.o: methods_executer.cc methods_executer.h
	g++ -c methods_executer.cc -std=c++11

utils.o: utils.cc utils.h
	g++ -c utils.cc

matrix.o: matrix.cc matrix.h
	g++ -c matrix.cc