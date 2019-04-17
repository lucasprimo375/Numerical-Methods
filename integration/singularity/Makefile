all: main.o user_input.o exp_method.o simple_exp.o
	g++ -o main main.o user_input.o exp_method.o simple_exp.o

main.o: main.cc user_input.h
	g++ -c main.cc

user_input.o: user_input.cc user_input.h
	g++ -c user_input.cc

exp_method.o: exp_method.cc exp_method.h
	g++ -c exp_method.cc

simple_exp.o: simple_exp.cc simple_exp.h
	g++ -c simple_exp.cc