prac3.out: main.o ingredient.o cauldron.o
	g++ main.o ingredient.o cauldron.o -o prac3.out
	
main.o: main.cpp
	g++ -c main.cpp
	
ingredient.o: ingredient.cpp
	g++ -c ingredient.cpp
	
cauldron.o: cauldron.cpp
	g++ -c cauldron.cpp

run:
	./prac3.out
	
clean:
	rm *.o prac3.out

tar:
	tar -cvz *.h *.cpp *.txt makefile -f prac3.tar
	