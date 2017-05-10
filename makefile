CFLAGS=-Wall -Wextra -pedantic -g
FICHEIROS=(wildcard *.c) (wildcard *.h) makefile
OBJECTS:=$(patsubst %.c,%.o,$(wildcard *.c))
OBJ_HTML:=$(patsubst %.c,%.o,$(wildcard html/*.c))
OBJ_IA:=$(patsubst %.c,%.o,$(wildcard IA/*.c))

LIBS=-lm

install: roguel
	sudo cp roguel /usr/lib/cgi-bin/
	sudo cp imagens/* /var/www/html/imagens
	touch install

roguel: $(OBG_IA) $(OBJ_HTML) $(OBJECTS)
	cc -o roguel $(OBJECTS) $(OBJ_HTML) $(LIBS)

exemplo.zip: $(FICHEIROS)
	zip -9 exemplo.zip $(FICHEIROS)

doc:
	doxygen -g
	doxygen

clean:
	rm -rf *.o roguel install gamestate
	(cd html;make clean)
	(cd IA;make clean)
