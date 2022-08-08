main: main.o train.o bin.o
	g++ -o main main.o train.o bin.o
	
bin.o: bin.cpp bin.h
	g++ -c bin.cpp
	
train.o: train.cpp train.h
	g++ -c train.cpp
	
main.o: main.cpp
	g++ -c main.cpp
	
run:
	./main
	
clean:
	rm *.o main
	
tar:
	tar -cvz makefile *.h *.cpp -f Practical7.tar