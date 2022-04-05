test:
	./menu < testFile.txt

menu: menu.o store.o book.o
	g++ menu.o store.o book.o -o menu

menu.o: menu.cpp store.h book.h store.cpp book.cpp
	g++ -c menu.cpp

store.o: book.h store.h store.cpp
	g++ -c store.cpp

book.o: book.h book.cpp
	g++ -c book.cpp

clean:
	rm *.o menu