CC=gcc
CFLAGS=-g -Wall -std=c99
TARGETS=check-date odd-sum

all: $(TARGETS)

check-date: check-date.c
	cc $(CFLAGS) -o check-date check-date.c

odd-sum: odd-sum.c
	cc $(CFLAGS) -o odd-sum odd-sum.c

clean:
	rm -rf *.o *~ $(TARGETS) a.out \
	rm -rf check-date.dSYM odd-sum.dSYM