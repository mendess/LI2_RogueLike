#ifndef ___HTML_MASTER_H___
#define ___HTML_MASTER_H___

#include "../estrutura.h"

#include "html0Form.h"
#include "html1Menu.h"
#include "html2CharSelect.h"
#include "html3Help.h"
#include "html4ScoreBoard.h"
#include "html5Playing.h"
#include "html6Shop.h"

#define ITEM_LIST				{"Empty",\
								 "Item_PotionHealth.png",\
								 "Item_PotionMana.png",\
								 "Item_ScrollRed.png",\
								 "Item_ScrollYellow.png",\
								 "Item_ScrollGreen.png",\
								 "Item_ScrollBlue.png",\
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

#define ABRIR_SVG				printf("<svg width=%d height=%d>\n",SVG_WIDTH,SVG_HEIGHT)

#define FECHAR_SVG				printf("</svg>\n")

#define IMAGE_PATH				"http://127.0.0.1/imagens/"

#define IMAGEM(X,Y,WIDTH,HEIGHT,FICHEIRO)	printf("<image x=%d y=%d width=%d height=%d preserveAspectRatio=none xlink:href=%s%s />\n", \
												X, Y, WIDTH, HEIGHT, IMAGE_PATH, FICHEIRO)
#define IMAGEM_FORMATED(X,Y,WIDTH,HEIGHT,FICHEIRO)	printf("<image x=%d y=%d width=%d height=%d preserveAspectRatio=none xlink:href=%s%s />\n", \
																(X+1)*TAM, (Y+1)*TAM, WIDTH, HEIGHT, IMAGE_PATH, FICHEIRO)

/**
\brief Macro para criar um quadrado
@param X A coordenada X do canto superior esquerdo
@param Y A coordenada Y do canto superior esquerdo
@param SCALE A escala do quadrado
@param COR A cor de preenchimento do quadrado
*/
/*#define QUADRADO(X, Y, SCALE, COR)			printf("<rect x=%d y=%d width=%d height=%d fill=%s />\n", \
												SCALE * X, SCALE* Y, SCALE, SCALE, COR) */              //old one 
#define SQUARE(X,Y,FILL,F_OPACITY,STROKE,S_OPACITY,SCALE)	printf("<rect x=%d y=%d width=%d height=%d style=fill:%s;fill-opacity:%f;stroke:%s;stroke-opacity:%f;stroke-width:2/></rect>", \
																		     X,   Y,   SCALE,    SCALE,         FILL,        F_OPACITY,   STROKE,          S_OPACITY)
#define SQUARE_FORMATED(X,Y,FILL,F_OPACITY,STROKE,S_OPACITY,SCALE)	printf("<rect x=%d y=%d width=%d height=%d style=fill:%s;fill-opacity:%f;stroke:%s;stroke-opacity:%f;stroke-width:2/></rect>", \
																		    	 (X+1)*TAM,   (Y+1)*TAM,   SCALE,    SCALE,         FILL,        F_OPACITY,   STROKE,          S_OPACITY)
#define CIRCLE(X,Y,RADIUS,FILL,F_OPACITY,STROKE,S_OPACITY,SCALE)	printf("<circle cx=%d cy=%d r=%d style=fill:%s;fill-opacity:%f;stroke:%s;stroke-opacity:%f;stroke-width:2/></circle>", \
																                X+SCALE/2,Y+SCALE/2,RADIUS,   FILL,      F_OPACITY,   STROKE,        S_OPACITY)

#define ABRIR_LINK(name,action)	printf("<a xlink:href=http://localhost/cgi-bin/roguel?%s,%s>\n",name,action)

#define ABRIR_RESET_LINK		printf("<a xlink:href=http://localhost/cgi-bin/roguel>\n")

#define FECHAR_LINK				printf("</a>\n")


void print_header();
void print_footer();
void imprime(ESTADO e);

#endif
