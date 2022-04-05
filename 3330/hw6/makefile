test:
	./studentlist < testcase1.txt

main: main.o studentlist.o
	g++ main.o studentlist.o -o studentlist

main.o: main.cpp studentlist.h
	g++ -c main.cpp

studentlist.o: studentlist.cpp studentlist.h
	g++ -c studentlist.cpp

clean:
	rm *.o studentlist