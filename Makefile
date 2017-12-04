all: main

main: main.cpp Matrix.cpp
	rm -f -- lab7_matrix
	g++ -g -Wall -pedantic -o lab7_matrix main.cpp Matrix.cpp

.PHONY: clean

clean:
	rm lab7_matrix
