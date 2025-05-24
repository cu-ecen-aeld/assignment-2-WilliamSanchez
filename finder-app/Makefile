CC = $(CROSS_COMPILE)gcc
OBJ = writer.o

%.o: %.c
	$(CC) -c -o $@ $<

all: writer

writer: $(OBJ)
	$(CC) -o $@ $^

.PHONY: clean

clean:
	rm -f *.o writer *~



