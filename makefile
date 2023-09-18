OPTS=-fno-pie -no-pie -fno-builtin -g

all: lab03_1 lab03_2 lab03_3

lab03_1: lab03_1.o
	gcc $(OPTS) -o lab03_1 lab03_1.o

lab03_2: lab03_2.o
	gcc $(OPTS) -o lab03_2 lab03_2.o

lab03_3: lab03_3.o
	gcc $(OPTS) -o lab03_3 lab03_3.o

lab03_1.o: lab03_1.c
	gcc -c $(OPTS) lab03_1.c

lab03_2.o: lab03_2.c
	gcc -c $(OPTS) lab03_2.c

lab03_3.o: lab03_3.c
	gcc -c $(OPTS) lab03_3.c

clean:
	rm -f *.o lab03_1 lab03_2 lab03_3
