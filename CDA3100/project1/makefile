run: project1 machine
	./project1 testcode.txt

project1: project1.cpp
	g++ project1.cpp -o project1

machine: assembler testcode.asm
	./assembler testcode.asm testcode.txt

assembler: LC3101a.c
	gcc LC3101a.c -o assembler

clean:
	rm assembler testcode.txt project1