CFLAGS=-Wall -g
OBJECTS:=$(patsubst %.c,%.o,$(wildcard *.c))

instal: $(OBJECTS)
	cc -c $(OBJECTS)

clean: 
	rm -rf *.o
