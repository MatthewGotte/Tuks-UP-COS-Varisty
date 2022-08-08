mul: mul.o
	ld -o mul mul.o

mul.o: mul.asm
	yasm -f elf64 -g dwarf2 -l mul.lst mul.asm

run:
	./mul

clean:
	rm *.o *.lst mul