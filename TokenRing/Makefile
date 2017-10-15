all: main.o
	mpicc -fopenmp -Wall -g $< -o  teste

main.o:
	mpicc -c  main.c

run:
	mpirun -np 5 teste

clean:
	rm -rf *.o teste
