CC=gcc
CFLAGS=-g -Wall -std=c99
TARGETS=check-date odd-sum

all: $(TARGETS)

#Static Pattern Rules
$(TARGETS): % : %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf *.o *~ $(TARGETS)