add: add.o
	ld -o add add.o

add.o: add.asm
	yasm -f elf64 -g dwarf2 -l add.lst add.asm

run:
	./add

clean:
	rm *.o *.lst add

# add: add.asm 
# 	yasm -f elf64 -g dwarf2 -l add.lst add.asm 
# 	ld -o add add.o