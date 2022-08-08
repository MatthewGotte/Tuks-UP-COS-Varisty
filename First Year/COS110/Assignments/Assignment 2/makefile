main: main.o matrix.o
	g++ -o main main.o matrix.o
	
main.o: main.cpp matrix.o
	g++ -c main.cpp
	
matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp
	
run:
	./main
	
clean:
	rm *.o main

tar:
	tar -cvz makefile *.h *.txt *.cpp -f Assignment2Task3.tar