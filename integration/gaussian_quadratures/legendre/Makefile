all: main.o user_input.o gauss_quadrature.o degree_two.o degree_three.o degree_four.o
	g++ -o main main.o user_input.o gauss_quadrature.o degree_two.o degree_three.o degree_four.o

main.o: main.cc user_input.h
	g++ -c main.cc

degree_two.o: degree_two.cc degree_two.h
	g++ -c degree_two.cc

degree_three.o: degree_three.cc degree_three.h
	g++ -c degree_three.cc

degree_four.o: degree_four.cc degree_four.h
	g++ -c degree_four.cc

gauss_quadrature.o: gauss_quadrature.cc gauss_quadrature.h
	g++ -c gauss_quadrature.cc

user_input.o: user_input.cc user_input.h degree_two.h degree_three.h degree_four.h
	g++ -c user_input.cc
