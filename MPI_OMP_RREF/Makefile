DEPS = matrix.c main.c
OBJS = matrix.o main.o
%.o: %.c $(DEPS)
	mpicc -c -fopenmp $^
all: $(OBJS)
	mpicc -g -Wall -fopenmp $^ -o teste

clean:
	rm -rf *.o teste

run:
	mpirun -np 3 teste

