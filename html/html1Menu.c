#include "html1Menu.h"

void imprimeMainMenu(char *name){
	ABRIR_SVG;

	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,"ScreenMainMenu.png");
	ABRIR_LINK(name,"52");/* Play */
	printf("<rect x=245 y=294 width=310 height=99 style=opacity:0;></rect>\n");
	FECHAR_LINK;
	ABRIR_LINK(name,"53");/* Help */
	printf("<rect x=269 y=402 width=269 height=75 style=opacity:0;></rect>\n");
	FECHAR_LINK;
	ABRIR_LINK(name,"54");/* ScoreBoard */
	printf("<rect x=269 y=484 width=269 height=75 style=opacity:0;></rect>\n");
	FECHAR_LINK;

	ABRIR_RESET_LINK;/* back */
	printf("<rect x=660 y=540 width=140 height=60 style=opacity:0;></rect>\n");
	FECHAR_LINK;

	FECHAR_SVG;
}
