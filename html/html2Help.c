#include "html2Help.h"

void imprimeHelp(){
	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,"ScreenHelp.png");
	ABRIR_LINK("0");//back
	printf("<rect x=0 y=540 width=140 height=60 style=opacity:0;>\n");
	FECHAR_LINK;
}