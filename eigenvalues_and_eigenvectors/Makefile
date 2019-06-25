all: main.o user_input.o methods_executer.o utils.o matrix.o
	g++ -o main main.o user_input.o methods_executer.o utils.o matrix.o

main.o: main.cc methods.h user_input.h utils.h matrix.h
	g++ -c main.cc -std=c++11

user_input.o: user_input.cc user_input.h methods.h
	g++ -c user_input.cc -std=c++11

methods_executer.o: methods_executer.cc methods_executer.h
	g++ -c methods_executer.cc -std=c++11

utils.o: utils.cc utils.h matrix.h
	g++ -c utils.cc -std=c++11

matrix.o: matrix.cc matrix.h
	g++ -c matrix.cc