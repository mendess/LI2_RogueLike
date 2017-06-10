#include "UI3Help.h"

void imprimeHelp(char *name){
	ABRIR_SVG;

	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,"ScreenHelp.png");
	ABRIR_LINK(name,"0");/* back */
	printf("<rect x=0 y=540 width=60 height=60 style=opacity:0;></rect>\n");
	FECHAR_LINK;

	FECHAR_SVG;
}
