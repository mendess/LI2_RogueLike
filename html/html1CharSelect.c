#include "html1CharSelect.h"

void imprimeCharSelect(){
	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,"ScreenCharSelect.png");
	ABRIR_LINK("62");//Archer
	printf("<rect x=30 y=21 width=230 height=368 style=opacity:0;></rect>\n");
	FECHAR_LINK;
	ABRIR_LINK("61");//Warrior
	printf("<rect x=285 y=21 width=230 height=368 style=opacity:0;></rect>\n");
	FECHAR_LINK;
	ABRIR_LINK("63");//Mage
	printf("<rect x=540 y=21 width=230 height=368 style=opacity:0;></rect>\n");
	FECHAR_LINK;
	ABRIR_LINK("0");//back
	printf("<rect x=0 y=540 width=140 height=60 style=opacity:0;></rect>\n");
	FECHAR_LINK;
}