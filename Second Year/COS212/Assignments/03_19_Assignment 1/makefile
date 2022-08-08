main: linkedList.o main.o
	g++ -o main main.o
	
linkedList.o: linkedList.h linkedList.cpp
	g++ -c linkedList.cpp
	
main.o: main.cpp
	g++ -c main.cpp
	
run:
	./main
	
clean:
	rm *.o main