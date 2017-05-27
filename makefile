CFLAGS= -Wall -Wextra -pedantic -O2
FICHEIROS=(wildcard *.c) (wildcard *.h) makefile
OBJECTS:=$(patsubst %.c,%.o,$(wildcard *.c))
OBJ_HTML:=$(patsubst %.c,%.o,$(wildcard html/*.c))

LIBS=-lm

install: roguel
	sudo cp roguel /usr/lib/cgi-bin/
	sudo mkdir -p /var/www/html/imagens
	sudo mkdir -p /var/www/html/files
	sudo mkdir -p /var/www/html/score
	sudo chmod a+rw /var/www/html/*
	sudo cp imagens/* /var/www/html/imagens
	touch install

roguel: $(OBJ_HTML) $(OBJECTS)
	cc -o roguel $(OBJECTS) $(OBJ_HTML) $(LIBS)

exemplo.zip: $(FICHEIROS)
	zip -9 exemplo.zip $(FICHEIROS)

doc:
	doxygen -g
	doxygen

clean:
	rm -rf *.o roguel install gamestate
	(cd html;make clean)

cleanvar:
	sudo rm -r /var/www/html/*

