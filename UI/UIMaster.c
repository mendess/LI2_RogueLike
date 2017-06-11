#include "UIMaster.h"

void print_header (){
	printf ("Content-Type: text/html; charset=utf-8\n\n");
	printf ("<!DOCTYPE html>\n");
	printf ("<html>\n");
	printf ("<head><title> Rogue Like </title></head>\n");
	printf ("<body>\n");
}
void print_footer () {

	printf("</body>\n");
	printf("</html>\n");
}
void imprime(ESTADO e){
	print_header();
	switch(e.screen){
		case 0: imprimeForm();
				break;
		case 1: imprimeMainMenu(e.name);
				break;
		case 2: imprimeCharSelect(e.name);
				break;
		case 4: imprimeScoreBoard(e.name,e.turn);
				break;
		case 5: imprimePlaying(e);
				break;
		case 6: imprimeShop(e);
				break;
	}
	print_footer();
}