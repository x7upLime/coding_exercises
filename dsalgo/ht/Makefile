CC = gcc
CFLAGS = -Wall -Wextra -ggdb
LIBS = 

all: main test

main: ht.o htdemo.o
	$(CC) $(CFLAGS) -o a.out ht.o htdemo.o $(LIBS)

test: CFLAGS += -DTESTABLE
test: ht.o ht_test.o
	$(CC) $(CFLAGS) -o test ht.o ht_test.o $(LIBS)

ht_demo.o: ht.c ht_demo.c ht.h
	$(CC) $(CFLAGS) -c ht_demo.c ht.h
ht.o: ht.c ht.h
	$(CC) $(CFLAGS) -c ht.c

clean:
	rm -f ./a.out test *.o
