all: main.o newton_cotes.o functions.o closed_one.o closed_two.o user_input.o
	g++ -o main main.o newton_cotes.o functions.o closed_one.o closed_two.o user_input.o

main.o: main.cc newton_cotes.h closed_one.h closed_two.h user_input.h
	g++ -c main.cc

closed_one.o: closed_one.cc closed_one.h functions.h
	g++ -c closed_one.cc

closed_two.o: closed_two.cc closed_two.h functions.h
	g++ -c closed_two.cc

functions.o: functions.cc functions.h
	g++ -c functions.cc

newton_cotes.o: newton_cotes.cc newton_cotes.h
	g++ -c newton_cotes.cc

user_input.o: user_input.cc user_input.h
	g++ -c user_input.cc