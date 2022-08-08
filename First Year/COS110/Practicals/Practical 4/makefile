prac4.out: main.o tome.o
	g++ tome.o main.o -o prac4.out
	
main.o: main.cpp
	g++ -c main.cpp
	
tome.o: tome.cpp
	g++ -c tome.cpp
	
run:
	./prac4.out
	
clean:
	rm *.o *.out

tar:	
	tar -cvz makefile *.h *.cpp -f Prac4.tar