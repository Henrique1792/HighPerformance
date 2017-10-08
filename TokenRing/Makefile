all: *.o 
	mpicc -Wall -g $< -o ring

*.o: 
	mpicc -c *.c

run:
	mpirun -np 5 ring

clean:
	rm -rf *.o ring
