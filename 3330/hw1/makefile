diamond: diamond.o main.o
	g++ diamond.o main.o -o diamond
	./diamond

driver: diamond.o driver.o
	g++ diamond.o driver.o -o driver
	./driver

diamond.o: diamond.cpp diamond.h
	g++ -c diamond.cpp

main.o: main.cpp diamond.h
	g++ -c main.cpp

driver.o: driver.cpp diamond.h
	g++ -c driver.cpp

clean:
	rm -f *.o diamond driver
