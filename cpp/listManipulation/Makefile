all : main

main: main.o
	g++ -std=c++11 -g -o main main.o

main.o: main.cpp
	g++ -std=c++11 -c -g main.cpp

clean:
	rm -f *.o main
	echo Clean done
