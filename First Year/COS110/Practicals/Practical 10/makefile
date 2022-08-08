main: *.o
	g++ -o main *.o
	
*.o: *.h *.cpp
	g++ -c *.cpp
	
run:
	./main
	
clean:
	rm *.o main
	
tar:
	tar -cvz makefile *.h *.cpp -f Practical10.tar
	
