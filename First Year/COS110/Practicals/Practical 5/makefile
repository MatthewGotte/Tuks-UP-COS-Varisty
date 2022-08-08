main: vehicle.o locomotive.o dieselLocomotive.o electricLocomotive.o main.o
	g++ -o main vehicle.o locomotive.o dieselLocomotive.o electricLocomotive.o main.o
	
vehicle.o: vehicle.cpp vehicle.h
	g++ -c vehicle.cpp
	
locomotive.o: locomotive.cpp locomotive.h
	g++ -c locomotive.cpp
	
dieselLocomotive.o: dieselLocomotive.cpp dieselLocomotive.h
	g++ -c dieselLocomotive.cpp
	
electricLocomotive.o: electricLocomotive.cpp electricLocomotive.cpp
	g++ -c electricLocomotive.cpp
	
main.o: main.cpp
	g++ -c main.cpp
	
run:
	./main
	
clean:
	rm *.o main
	
tar:
	tar -cvz makefile *.txt *.h *.cpp -f Practical5.tar