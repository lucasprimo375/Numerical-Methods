all: main.o user_input.o gauss_quadrature.o degree_two.o
	g++ -o main main.o user_input.o gauss_quadrature.o degree_two.o

main.o: main.cc user_input.h
	g++ -c main.cc

degree_two.o: degree_two.cc degree_two.h
	g++ -c degree_two.cc

gauss_quadrature.o: gauss_quadrature.cc gauss_quadrature.h
	g++ -c gauss_quadrature.cc

user_input.o: user_input.cc user_input.h degree_two.h
	g++ -c user_input.cc
