TARGETS=linkedlist
CC=gcc
CFLAGS=-g -Wall -std=c99

all: $(TARGETS)

$(TARGETS): % : %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o *~ $(TARGETS) a.out
