CFLAGS=-Wall -g
FICHEIROS=cgi.h estado.c estado.h exemplo.c Makefile

install: roguel
	sudo cp roguel /usr/lib/cgi-bin/
	sudo cp imagens/* /var/www/html/imagens
	rm *.o
	touch install

roguel: jogo.o estado.o path.o htmlMaster.o html0Menu.o html1ScoreBoard.o html2Help.o html3CharSelect.o html4Playing.o html5Shop.o score.o levelMaker.o move_monst.o colisions.o
	cc -o roguel jogo.o estado.o path.o htmlMaster.o html0Menu.o html1ScoreBoard.o html2Help.o html3CharSelect.o html4Playing.o html5Shop.o score.o levelMaker.o move_monst.o colisions.o

exemplo.zip: $(FICHEIROS)
	zip -9 exemplo.zip $(FICHEIROS)

doc:
	doxygen -g
	doxygen

clean:
	rm -rf *.o roguel Doxyfile latex html install
	rm -rf gamestate
