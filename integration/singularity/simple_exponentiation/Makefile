all: main.o user_input.o utils.o
	g++ -o main main.o user_input.o utils.o

main.o: main.cc user_input.h
	g++ -c main.cc

user_input.o: user_input.cc user_input.h
	g++ -c user_input.cc

utils.o: utils.cc utils.h
	g++ -c utils.cc