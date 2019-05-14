all: main.o user_input.o exp_method.o simple_exp.o double_exp.o newton_cotes.o closed_two.o
	g++ -o main main.o user_input.o exp_method.o simple_exp.o double_exp.o newton_cotes.o closed_two.o

main.o: main.cc user_input.h
	g++ -c main.cc

user_input.o: user_input.cc user_input.h
	g++ -c user_input.cc

exp_method.o: exp_method.cc exp_method.h newton_cotes.h closed_two.h
	g++ -c exp_method.cc -std=c++11

simple_exp.o: simple_exp.cc simple_exp.h exp_method.h
	g++ -c simple_exp.cc

double_exp.o: double_exp.cc double_exp.h exp_method.h
	g++ -c double_exp.cc

newton_cotes.o: newton_cotes.cc newton_cotes.h
	g++ -c newton_cotes.h -std=c++11
	g++ -c newton_cotes.cc -std=c++11

closed_two.o: closed_two.cc closed_two.h
	g++ -c closed_two.h -std=c++11
	g++ -c closed_two.cc -std=c++11