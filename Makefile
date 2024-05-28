.PHONY: clean run

run: clasament
	./clasament Input/test10.in r1.out r2.out

build: main.c
	gcc thePrestige.c createTheGraph.c Queue.c readFromFile.c main.c -Wall -o clasament -lm

clean:
	rm -f clasament
	rm -f r1.out
	rm -f r2.out