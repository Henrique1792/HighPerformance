DEPS = utils.c matrix.c GJ.c main.c
OBJS = utils.o matrix.o GJ.o main.o
EXEC = rref

%.o: %.c $(DEPS)
	mpicc -c $^

all: $(OBJS)
	mpicc -g -Wall  $^ -o $(EXEC)

clean: 
	rm -rf *.o $(EXEC) 

#test structure

#Homemade Tests
run:
	export OMP_NUM_THREADS=1 ;\
		mpirun -np 3 $(EXEC) 5

#2 cluster nodes
2NodesSingle1:
	export OMP_NUM_THREADS=1 ;\
		mpirun -hostfile hosts -np 2 $(EXEC) 1000

2NodesSingle2:
	export OMP_NUM_THREADS=1 ;\
		mpirun -hostfile hosts -np 2 $(EXEC) 5000

2NodesSingle3:
	export OMP_NUM_THREADS=1 ;\
		mpirun -hostfile hosts -np 2 $(EXEC) 10000

2Nodes4Threads1:
	export OMP_NUM_THREADS=4 ;\
		mpirun -hostfile hosts -np 2 $(EXEC) 1000

2Nodes4Threads2:
	export OMP_NUM_THREADS=4 ;\
		mpirun -hostfile hosts -np 2 $(EXEC) 5000

2Nodes4Threads3:
	export OMP_NUM_THREADS=4 ;\
		mpirun -hostfile hosts -np 2 $(EXEC) 10000

2Nodes8Threads1:
	export OMP_NUM_THREADS=8 ;\
		mpirun -hostfile hosts -np 2 $(EXEC) 1000

2Nodes8Threads2:
	export OMP_NUM_THREADS=8 ;\
		mpirun -hostfile hosts -np 2 $(EXEC) 5000

2Nodes8Threads3:
	export OMP_NUM_THREADS=8 ;\
		mpirun -hostfile hosts -np 2 $(EXEC) 10000

#4 cluster nodes
4NodesSingle1:
	export OMP_NUM_THREADS=1 ;\
		mpirun -hostfile hosts -np 4 $(EXEC) 1000

4NodesSingle2:
	export OMP_NUM_THREADS=1 ;\
		mpirun -hostfile hosts -np 4 $(EXEC) 5000

4NodesSingle3:
	export OMP_NUM_THREADS=1 ;\
		mpirun -hostfile hosts -np 4 $(EXEC) 10000

4Nodes4Threads1:
	export OMP_NUM_THREADS=4 ;\
		mpirun -hostfile hosts -np 4 $(EXEC) 1000

4Nodes4Threads2:
	export OMP_NUM_THREADS=4 ;\
		mpirun -hostfile hosts -np 4 $(EXEC) 5000

4Nodes4Threads3:
	export OMP_NUM_THREADS=4 ;\
		mpirun -hostfile hosts -np 4 $(EXEC) 10000

4Nodes8Threads1:
	export OMP_NUM_THREADS=8 ;\
		mpirun -hostfile hosts -np 4 $(EXEC) 1000

4Nodes8Threads2:
	export OMP_NUM_THREADS=8 ;\
		mpirun -hostfile hosts -np 4 $(EXEC) 5000

4Nodes8Threads3:
	export OMP_NUM_THREADS=8 ;\
		mpirun -hostfile hosts -np 4 $(EXEC) 10000

#8 cluster nodes
8NodesSingle1:
	export OMP_NUM_THREADS=1 ;\
		mpirun -hostfile hosts -np 8 $(EXEC) 1000

8NodesSingle2:
	export OMP_NUM_THREADS=1 ;\
		mpirun -hostfile hosts -np 8 $(EXEC) 5000

8NodesSingle3:
	export OMP_NUM_THREADS=1 ;\
		mpirun -hostfile hosts -np 8 $(EXEC) 10000

8Nodes4Threads1:
	export OMP_NUM_THREADS=4 ;\
		mpirun -hostfile hosts -np 8 $(EXEC) 1000

8Nodes4Threads2:
	export OMP_NUM_THREADS=4 ;\
		mpirun -hostfile hosts -np 8 $(EXEC) 5000

8Nodes4Threads3:
	export OMP_NUM_THREADS=4 ;\
		mpirun -hostfile hosts -np 8 $(EXEC) 10000

8Nodes8Threads1:
	export OMP_NUM_THREADS=8 ;\
		mpirun -hostfile hosts -np 8 $(EXEC) 1000

8Nodes8Threads2:
	export OMP_NUM_THREADS=8 ;\
		mpirun -hostfile hosts -np 8 $(EXEC) 5000

8Nodes8Threads3:
	export OMP_NUM_THREADS=8 ;\
		mpirun -hostfile hosts -np 8 $(EXEC) 10000
