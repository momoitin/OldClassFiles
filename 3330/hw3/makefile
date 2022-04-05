main:
	g++ -c time.cpp main.cpp
	g++ time.o main.o -o time
	./time

time: time.o main.o
	g++ time.o main.o -o time
	./time

time.o: time.cpp time.h
	g++ -c time.cpp

main.o: main.cpp time.h
	g++ -c main.cpp

clean:
	rm -f *.o time