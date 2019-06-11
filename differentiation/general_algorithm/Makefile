all: main.o user_input.o utils.o first_derivative.o second_derivative.o third_derivative.o derivative.o
	g++ -o main main.o user_input.o utils.o first_derivative.o second_derivative.o third_derivative.o derivative.o

main.o: main.cc user_input.h utils.h first_derivative.h third_derivative.h
	g++ -c main.cc -std=c++11

first_derivative.o: first_derivative.cc first_derivative.h utils.h
	g++ -c first_derivative.cc -std=c++11

second_derivative.o: second_derivative.cc second_derivative.h utils.h
	g++ -c second_derivative.cc -std=c++11

third_derivative.o: third_derivative.cc third_derivative.h utils.h
	g++ -c third_derivative.cc -std=c++11

utils.o: utils.cc utils.h
	g++ -c utils.cc -std=c++11

user_input.o: user_input.cc user_input.h
	g++ -c user_input.cc -std=c++11

derivative.o: derivative.cc derivative.h
	g++ -c derivative.cc