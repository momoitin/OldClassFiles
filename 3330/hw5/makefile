test: driver
	./driver < testfile.txt > outputMyString.txt

driver: driver.o mystring.o
	g++ driver.o mystring.o -o driver

driver.o: driver.cpp mystring.h
	g++ -c driver.cpp

mystring: main.o mystring.o
	g++ main.o mystring.o -o mystring

main.o: main.cpp mystring.h
	g++ -c main.cpp

mystring.o: mystring.cpp mystring.h
	g++ -c mystring.cpp

clean:
	rm *.o mystring driver