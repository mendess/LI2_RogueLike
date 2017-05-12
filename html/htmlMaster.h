#ifndef ___HTML_MASTER_H___
#define ___HTML_MASTER_H___

#include "../jogo.h"

#include "html0Menu.h"
#include "html1CharSelect.h"
#include "html2Help.h"
#include "html3ScoreBoard.h"
#include "html4Playing.h"
#include "html5Shop.h"

#define ITEM_LIST				{"Empty",\
								 "Item_PotionHealth.png",\
								 "Item_PotionMana.png",\
								 "Item_ScrollRed.png",\
								 "Item_ScrollGreen.png",\
								 "Item_ScrollBlue.png",\
								 "Empty",\
								 "Empty",\
								 "Empty",\
								 "Empty",\
								 "Item_SwordBronze.png",\
								 "Item_SwordIron.png",\
								 "Item_SwordSteel.png",\
								 "Item_SwordPalladium.png",\
								 "Item_ArmourBronze.png",\
								 "Item_ArmourIron.png",\
								 "Item_ArmourSteel.png",\
								 "Item_ArmourPalladium.png"}

#define SVG_WIDTH				800

#define SVG_HEIGHT				600

#define IMAGE_PATH				"http://127.0.0.1/imagens/"

#define IMAGEM(X,Y,WIDTH,HEIGHT,FICHEIRO)	printf("<image x=%d y=%d width=%d height=%d preserveAspectRatio=none xlink:href=%s%s />\n", \
												X, Y, WIDTH, HEIGHT, IMAGE_PATH, FICHEIRO)


#define ABRIR_LINK(link)		printf("<a xlink:href=http://localhost/cgi-bin/roguel?%s>\n", link)

#define FECHAR_LINK				printf("</a>\n")


void print_header();
void print_footer();
void imprime(ESTADO e);

#endif
