unix3:
	g++ hw7unix.cpp -o points.exe
	./points.exe > myOutput.txt
	date
	wc -w myOutput.txt
	diff -w sample.out myOutput.txt
	mkdir hw7OutputFolder

mirrors:
	g++ ed20cr_mirrors.cpp -o mirrors
	./mirrors
	rm mirrors

mirrorsTest:
	g++ ed20cr_mirrors.cpp -o mirrors
	./mirrors < mirrorTest2.txt
	rm mirrors

restaurant:
	g++ ed20cr_restaurant.cpp -o restaurant
	./restaurant
	rm restaurant
