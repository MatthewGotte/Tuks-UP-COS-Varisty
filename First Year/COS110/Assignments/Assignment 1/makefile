task2.out: main.o piece.o board.o solver.o
	g++ main.o piece.o board.o solver.o -o task2.out
	
main.o: main.cpp
	g++ -c main.cpp
	
piece.o: piece.cpp
	g++ -c piece.cpp
	
board.o: board.cpp
	g++ -c board.cpp
	
solver.o: solver.cpp
	g++ -c solver.cpp

run:
	./task2.out
	
clean:
	rm *.o task2.out
	
tar:
	tar -cvz makefile main.cpp piece.h piece.cpp board.cpp board.h solver.cpp solver.h game1.txt game2.txt game3.txt game4.txt list.txt -f Task3.tar