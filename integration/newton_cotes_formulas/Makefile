all: newton_cotes.o closed_one.o user_input.o main.o open_one.o closed_two.o open_two.o closed_three.o open_three.o closed_four.o open_four.o
	g++ -o main main.o user_input.o closed_one.o newton_cotes.o open_one.o closed_two.o open_two.o closed_three.o open_three.o closed_four.o open_four.o

main.o: main.cc user_input.h
	g++ -c main.cc

closed_one.o: closed_one.cc closed_one.h newton_cotes.h
	g++ -c closed_one.cc

closed_two.o: closed_two.cc closed_two.h closed_two.h
	g++ -c closed_two.cc

closed_three.o: closed_three.cc closed_three.h closed_three.h
	g++ -c closed_three.cc

closed_four.o: closed_four.cc closed_four.h closed_four.h
	g++ -c closed_four.cc

open_one.o: open_one.cc open_one.h newton_cotes.h
	g++ -c open_one.cc

open_two.o: open_two.cc open_two.h open_two.h
	g++ -c open_two.cc

open_three.o: open_three.cc open_three.h open_three.h
	g++ -c open_three.cc

open_four.o: open_four.cc open_four.h open_four.h
	g++ -c open_four.cc

newton_cotes.o: newton_cotes.cc newton_cotes.h
	g++ -c newton_cotes.cc

user_input.o: user_input.cc user_input.h newton_cotes.h closed_one.h open_one.h closed_two.h open_two.h closed_three.h open_three.h closed_four.h open_four.h
	g++ -c user_input.cc