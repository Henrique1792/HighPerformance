all: 
	mpicc -Wall -g $< -o ring

*.o: 
	mpicc -c *.c

teste:
	mpirun -np 10 ring

clean:
	rm -rf *.o ring
