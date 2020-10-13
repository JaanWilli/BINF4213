all: main

main: main.o fraction.o
	g++ -o main main.o fraction.o

main.o: main.cpp rpn.h ../ex1_2/fraction.h
	g++ -c main.cpp

fraction.o: ../ex1_2/fraction.cpp ../ex1_2/fraction.h
	g++ -c ../ex1_2/fraction.cpp

clean:
	rm -f main *.o