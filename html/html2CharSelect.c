#include "html2CharSelect.h"

void imprimeCharSelect(char *name){
	ABRIR_SVG;

	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,"ScreenCharSelect.png");

	// Mage
	ABRIR_LINK(name,"63");
	printf("<rect x=30 y=21 width=230 height=368 style=opacity:0;></rect>\n");
	FECHAR_LINK;

	// Warrior
	ABRIR_LINK(name,"61");
	printf("<rect x=285 y=21 width=230 height=368 style=opacity:0;></rect>\n");
	FECHAR_LINK;

	// Archer
	ABRIR_LINK(name,"62");
	printf("<rect x=540 y=21 width=230 height=368 style=opacity:0;></rect>\n");
	FECHAR_LINK;

	// Back
	ABRIR_LINK(name,"0");
	printf("<rect x=0 y=540 width=60 height=60 style=opacity:0;></rect>\n");
	FECHAR_LINK;

	FECHAR_SVG;
}
