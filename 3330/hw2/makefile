date: date.o main.o
	g++ date.o main.o -o date
	./date

driver: date.o driver.o
	g++ date.o driver.o -o driver
	./driver

driver.o: driver.cpp date.h
	g++ -c driver.cpp

main.o: main.cpp date.h
	g++ -c main.cpp

date.o: date.cpp date.h
	g++ -c date.cpp

clean:
	rm -f *.o date driver