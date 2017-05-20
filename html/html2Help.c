#include "html2Help.h"

void imprimeHelp(){
	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,"ScreenHelp.png");
	ABRIR_LINK("0");/* back */
	printf("<rect x=5 y=526 width=103 height=70 style=opacity:0;></rect>\n");
	FECHAR_LINK;
}