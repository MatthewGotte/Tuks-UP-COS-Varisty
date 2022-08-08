prac2.out: main.o team.o creature.o
	g++ main.o team.o creature.o -o prac2.out
	
main.o: main.cpp
	g++ -c main.cpp
	
team.o: team.cpp
	g++ -c team.cpp
	
creature.o: creature.cpp
	g++ -c creature.cpp
	
run:
	./prac2.out
	
clean:
	rm *.o prac2.out
	
tar:
	tar -cvz makefile team.h team.cpp creature.cpp creature.h main.cpp -f Practical2.tar