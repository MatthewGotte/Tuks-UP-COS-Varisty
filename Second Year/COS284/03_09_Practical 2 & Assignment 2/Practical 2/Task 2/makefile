task2: task2.o
	ld -o task2 task2.o

task2.o: task2.asm
	yasm -f elf64 -g dwarf2 -l task2.lst task2.asm

run:
	./task2

clean:
	rm *.o *.lst task2