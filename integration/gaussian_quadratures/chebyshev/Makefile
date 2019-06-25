all: main.o user_input.o chebyshev.o
	g++ -o main main.o user_input.o chebyshev.o

main.o: main.cc user_input.h
	g++ -c main.cc

chebyshev.o: chebyshev.cc chebyshev.h
	g++ -c chebyshev.cc

user_input.o: user_input.cc user_input.h chebyshev.h
	g++ -c user_input.cc
