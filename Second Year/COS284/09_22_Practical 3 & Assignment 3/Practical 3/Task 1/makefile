task1: task1.o
	ld -o task1 task1.o

task1.o: task1.asm
	yasm -f elf64 -g dwarf2 -l task1.lst task1.asm

run:
	./task1

clean:
	rm *.o *.lst task1