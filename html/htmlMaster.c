#include "htmlMaster.h"

/**
\brief Imprime o inicio do html
*/
void print_header (){
	printf ("Content-Type: text/html; charset=utf-8\n\n");
	printf ("<!DOCTYPE html>\n");
	printf ("<html>\n");
	printf ("<head><title> Rogue Like </title></head>\n");
	printf ("<body>\n");
	printf ("<svg width=%d height=%d>\n",SVG_WIDTH,SVG_HEIGHT);
}
/**
\brief Imprime o fim do html
*/
void print_footer () {
	printf ("</svg>\n");
	printf("</body>\n");
	printf ("</html>\n");
}
/**
\brief Função principal que chama todas as outras
*/
void imprime(ESTADO e){
	print_header();
	switch(e.screen){
		case 0: imprimeMainMenu();
				break;
		case 1: imprimeCharSelect();
				break;
		case 2: imprimeHelp();
				break;
		case 3: imprimeScoreBoard();
				break;
		case 4: imprimePlaying(e);
				break;
		case 5: imprimeShop(e);
				break;
	}
	print_footer();
}