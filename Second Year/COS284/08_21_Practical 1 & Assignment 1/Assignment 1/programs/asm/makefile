main: main.o
	ld -o main main.o

main.o: main.asm
	yasm -f elf64 -g dwarf2 -l main.lst main.asm

run:
	./main

clean:
	rm *.o *.lst main
