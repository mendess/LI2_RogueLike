CFLAGS=-Wall -g
FICHEIROS=(wildcard *.c) (wildcard *.h) makefile
OBJECTS:=$(patsubst %.c,%.o,$(wildcard *.c))
OBJ_HTML:=$(patsubst %.c,%.o,$(wildcard html/*.c))

LIBS=-lm

install: roguel
	sudo cp roguel /usr/lib/cgi-bin/
	sudo cp imagens/* /var/www/html/imagens
	rm *.o
	touch install

roguel: $(OBJECTS) html
	cc -o roguel $(OBJECTS) $(OBJ_HTML) $(LIBS)

html:   (cd html;make)

exemplo.zip: $(FICHEIROS)
	zip -9 exemplo.zip $(FICHEIROS)

doc:
	doxygen -g
	doxygen

clean:
	rm -rf *.o roguel install gamestate
	(cd html;make clean)
