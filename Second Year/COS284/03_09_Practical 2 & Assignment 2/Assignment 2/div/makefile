div: div.o
	ld -o div div.o

div.o: div.asm
	yasm -f elf64 -g dwarf2 -l div.lst div.asm

run:
	./div

clean:
	rm *.o *.lst div