sub: sub.o
	ld -o sub sub.o

sub.o: sub.asm
	yasm -f elf64 -g dwarf2 -l sub.lst sub.asm

run:
	./sub

clean:
	rm *.o *.lst sub