
CFLAGS= -Wall -Wextra -pedantic -O2
FICHEIROS=(wildcard *.c) (wildcard *.h) makefile
OBJECTS:=$(patsubst %.c,%.o,$(wildcard *.c))
OBJ_IA:=$(patsubst %.c,%.o,$(wildcard IA/*.c))
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

roguel: $(OBJ_IA) $(OBJ_UI) $(OBJECTS)
	cc -o roguel $(OBJECTS) $(OBJ_IA) $(OBJ_UI) $(LIBS)

exemplo.zip: $(FICHEIROS)
	zip -9 exemplo.zip $(FICHEIROS)

doc:
	doxygen Doxyfile

clean:
	rm -rf *.o roguel install latex html Doxyfile.bak
	(cd UI;make clean)
	(cd IA;make clean)

hardclean: clean
	sudo rm -r /var/www/html/*

givegdbpermits:
	sudo chmod a+rw /var/www/html/files/*
	sudo chmod a+rw /var/www/html/score/*
