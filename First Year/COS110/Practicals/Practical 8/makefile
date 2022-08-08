main: main.o item.o LL.o
	g++ -o main main.o item.o LL.o
	
main.o: main.cpp
	g++ -c main.cpp
	
item.o: item.cpp item.h
	g++ -c item.cpp

LL.o: LL.cpp LL.h
	g++ -c LL.cpp
	
run:
	./main
	
clean:
	rm *.o main
	
tar:
	tar -cvz makefile *.cpp *.h -f Practical8.tar