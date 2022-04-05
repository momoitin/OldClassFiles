main: main.o bstring.o
	g++ main.o bstring.o -o main
	./main

main.o: main.cpp bstring.h
	g++ -c main.cpp

bstring.o: bstring.cpp bstring.h
	g++ -c bstring.cpp

clean:
	rm *.o main