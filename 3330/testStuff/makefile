garbage: garbage.o garbageMain.o
	g++ garbage.o garbageMain.o -o garbage
	./garbage

classes: classes.o testProgram.o
	g++ classes.o testProgram.o -o classes
	./classes

fraction: fraction.o main.o
	g++ fraction.o main.o -o fraction
	./fraction

fraction.o: fraction.cpp fraction.h
	g++ -c fraction.cpp

main.o: main.cpp fraction.h
	g++ -c main.cpp

classes.o: classes.cpp classes.h
	g++ -c classes.cpp

testProgram.o: testProgram.cpp classes.h
	g++ -c testProgram.cpp

garbage.o: garbage.cpp garbage.h
	g++ -c garbage.cpp

garbageMain.o: garbageMain.cpp garbage.h
	g++ -c garbageMain.cpp

clean:
	rm -f *.o classes garbage fraction