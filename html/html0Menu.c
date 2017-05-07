#include "html0Menu.h"

void imprimeMainMenu(){
	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,"ScreenMainMenu.png");
	ABRIR_LINK("51");//Play
	printf("<rect x=300 y=230 width=200 height=50 style=opacity:0;>\n");
	FECHAR_LINK;
	ABRIR_LINK("52");//Help
	printf("<rect x=300 y=330 width=200 height=50 style=opacity:0;>\n");
	FECHAR_LINK;
	ABRIR_LINK("53");//ScoreBoard
	printf("<rect x=250 y=430 width=300 height=50 style=opacity:0;>\n");
	FECHAR_LINK;

}