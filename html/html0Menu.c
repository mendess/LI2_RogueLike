#include "html0Menu.h"

void imprimeMainMenu(){
	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,"ScreenMainMenu.png");
	ABRIR_LINK("51");//Play
	printf("<rect x=255 y=205 width=286 height=94 style=opacity:0;></rect>\n");
	FECHAR_LINK;
	ABRIR_LINK("52");//Help
	printf("<rect x=255 y=311 width=286 height=94 style=opacity:0;></rect>\n");
	FECHAR_LINK;
	ABRIR_LINK("53");//ScoreBoard
	printf("<rect x=255 y=415 width=286 height=94 style=opacity:0;></rect>\n");
	FECHAR_LINK;

}