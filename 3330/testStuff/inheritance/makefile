friends: main.o friends.o
	g++ main.o friends.o -o friends

main.o: friends.h main.cpp	
	g++ -c main.cpp

friends.o: friends.h friends.cpp
	g++ -c friends.cpp

clean:
	rm *.o friends