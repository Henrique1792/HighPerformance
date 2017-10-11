all: main.o
	mpicc -Wall -g $< -fopenmp -o  teste

main.o:
	mpicc -c  main.c

run:
	mpirun -np 5 teste

clean:
	rm -rf *.o
