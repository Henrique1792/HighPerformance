all: matrix.o mult.o
	gcc -g -Wall matrix.o mult.o -fopenmp -o teste

matrix.o:
	gcc -c matrix.c


mult.o:
	gcc -c mult.c

run:
	./teste

control: run
	time ./teste


debug:
	valgrind ./teste

clean:
	rm -rf *.o
