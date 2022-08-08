task3: task3.o
	ld -o task3 task3.o

task3.o: task3.asm
	yasm -f elf64 -g dwarf2 -l task3.lst task3.asm

run:
	./task3

clean:
	rm *.o *.lst task3