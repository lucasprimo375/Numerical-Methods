all: functions.o fourth_order.o main.o
	g++ -o main functions.o fourth_order.o main.o

main.o: main.cc fourth_order.h
	g++ -c main.cc

functions.o: functions.cc functions.h
	g++ -c functions.cc

fourth_order.o: fourth_order.cc fourth_order.h functions.h
	g++ -c fourth_order.cc