all: main.o
	mpicc -fopenmp -Wall -g $< -o  teste

main.o:
	mpicc -c  -fopenmp main.c

run:
	mpirun -np 3 teste

clean:
	rm -rf *.o teste
