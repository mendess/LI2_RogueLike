CFLAGS=-Wall -g
FICHEIROS=cgi.h estado.c estado.h exemplo.c Makefile

install: roguel
	sudo cp roguel /usr/lib/cgi-bin/
	sudo cp imagens/* /var/www/html/imagens
	touch install

roguel: jogo.o parser.o path.o estado.o score.o levelMaker.o
	cc -o roguel jogo.o estado.o path.o parser.o score.o levelMaker.o

exemplo.zip: $(FICHEIROS)
	zip -9 exemplo.zip $(FICHEIROS)

doc:
	doxygen -g
	doxygen

clean:
	rm -rf *.o roguel Doxyfile latex html install
	rm -rf gamestate
