
CFLAGS= -Wall -Wextra -pedantic -g
FICHEIROS=(wildcard *.c) (wildcard *.h) makefile
OBJECTS:=$(patsubst %.c,%.o,$(wildcard *.c))
OBJ_UI:=$(patsubst %.c,%.o,$(wildcard UI/*.c))

LIBS=-lm

install: roguel
	sudo cp roguel /usr/lib/cgi-bin/
	sudo mkdir -p /var/www/html/imagens
	sudo mkdir -p /var/www/html/files
	sudo mkdir -p /var/www/html/score
	sudo chmod a+rw /var/www/html/*
	sudo cp imagens/* /var/www/html/imagens
	touch install

roguel: $(OBJ_UI) $(OBJECTS)
	cc -o roguel $(OBJECTS) $(OBJ_UI) $(LIBS)

exemplo.zip: $(FICHEIROS)
	zip -9 exemplo.zip $(FICHEIROS)

doc:
	doxygen -g
	doxygen Doxyfile

clean:
	rm -rf *.o roguel install latex html Doxyfile*
	(cd UI;make clean)

hardclean:
	sudo rm -r /var/www/html/*
	rm -rf *.o roguel install latex html Doxyfile*
	(cd UI;make clean)

givegdbpermits:
	sudo chmod a+rw /var/www/html/files/*
	sudo chmod a+rw /var/www/html/score/*

