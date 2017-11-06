DEPS = utils.c matrix.c main.c
OBJS = utils.o matrix.o main.o
EXEC = $(EXEC)
%.o: %.c $(DEPS)
	mpicc -c $^
all: $(OBJS)
	mpicc -g -Wall  $^ -o $(EXEC)

clean: 
	rm -rf *.o $(EXEC) 
#test structure

#Homemade Tests
run:
	setenv OMP_NUM_THREADS=1 ;\
		mpirun -np 3 $(EXEC)

#2 cluster nodes
2NodesSingle:
	setenv OMP_NUM_THREADS=1 ;\
		mpirun -hostfile hosts -np 2 $(EXEC)
2Nodes4Threads:
	setenv OMP_NUM_THREADS=4 ;\
		mpirun -hostfile hosts -np 2 $(EXEC)
2Nodes8Threads:
	setenv OMP_NUM_THREADS=8 ;\
		mpirun -hostfile hosts -np 2 $(EXEC)

#4 cluster nodes
4NodesSingle:
	setenv OMP_NUM_THREADS=1 ;\
		mpirun -hostfile hosts -np 4 $(EXEC)
4Nodes4Threads:
	setenv OMP_NUM_THREADS=4 ;\
		mpirun -hostfile hosts -np 4 $(EXEC)
	
4Nodes8Threads:
	setenv OMP_NUM_THREADS=8 ;\
		mpirun -hostfile hosts -np 4 $(EXEC)

#8 cluster nodes
8NodesSingle:
	setenv OMP_NUM_THREADS=1 ;\
		mpirun -hostfile hosts -np 8 $(EXEC)
8Nodes4Threads:
	setenv OMP_NUM_THREADS=4 ;\
		mpirun -hostfile hosts -np 8 $(EXEC)
8Nodes8Threads:
	setenv OMP_NUM_THREADS=8 ;\
		mpirun -hostfile hosts -np 8 $(EXEC)

