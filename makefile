test: test.o
	./test.o
	#debug50 test.o
	rm test.o

test.o: test.cpp Phone.cpp
	g++ -std=c++11 test.cpp Phone.cpp -o test.o #-ggdb

