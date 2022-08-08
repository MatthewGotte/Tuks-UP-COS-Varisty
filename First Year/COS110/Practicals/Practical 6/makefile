main: main.o fireControl.o laser.o missile.o weapon.o
	g++ -o main main.o fireControl.o laser.o missile.o weapon.o
	
main.o: main.cpp
	g++ -c main.cpp
	
fireControl.o: fireControl.h fireControl.cpp
	g++ -c fireControl.cpp
	
laser.o: laser.h laser.cpp
	g++ -c laser.cpp
	
missile.o: missile.h missile.cpp
	g++ -c missile.cpp
	
weapon.o: weapon.h weapon.cpp
	g++ -c weapon.h weapon.cpp
	
run:
	./main
	
clean:
	rm *.o main
	
tar:
	tar -cvz makefile *.cpp *.h -f Practical6.tar