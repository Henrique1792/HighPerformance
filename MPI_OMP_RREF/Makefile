DEPS = utils.c matrix.c main.c
OBJS = utils.o matrix.o main.o
%.o: %.c $(DEPS)
	gcc -c $^
all: $(OBJS)
	gcc -g -Wall  $^ -o rref

clean:
	rm -rf *.o rref

run:
	./rref

