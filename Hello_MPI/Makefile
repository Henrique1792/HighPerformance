all: hello.o
	mpicc -Wall -g $< -o hello

hello.o:
	mpicc -c hello.c

teste:
	mpirun -np 10 hello

clean:
	rm -rf *.o
