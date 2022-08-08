hello: hello.o
	ld -o hello hello.o

hello.o: hello.asm
	yasm -f elf64 -g dwarf2 -l hello.lst hello.asm

run:
	./hello

clean:
	rm *.o *.lst hello