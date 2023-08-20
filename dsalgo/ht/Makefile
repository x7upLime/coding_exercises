CC = gcc
CFLAGS = -Wall -Wextra -ggdb
LIBS = 

all: main test

main: ht_demo.o
	$(CC) $(CFLAGS) -o a.out ht.o ht_demo.o $(LIBS)

test: CFLAGS += -DTESTABLE
test: ht.c ht_test.c ht.h
	$(CC) $(CFLAGS) -o test ht.c ht_test.c $(LIBS)

ht_demo.o: ht.c ht_demo.c ht.h
	$(CC) $(CFLAGS) -c ht_demo.c ht.c

ht.o: ht.c ht.h
	$(CC) $(CFLAGS) -c ht.c

clean:
	rm -f ./a.out test *.o
