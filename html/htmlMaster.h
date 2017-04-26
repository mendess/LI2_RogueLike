#ifndef ___HTML_MASTER_H___
#define ___HTML_MASTER_H___

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "../jogo.h"
#include "../estado.h"
#include "../levelMaker.h"
#include "../colisions.h"

#include "html0Menu.h"
#include "html1ScoreBoard.h"
#include "html2Help.h"
#include "html3CharSelect.h"
#include "html4Playing.h"
#include "html5Shop.h"

/*
#define COMECAR_HTML						printf("Content-Type: text/html\n\n")
#define ABRIR_SVG(tamx, tamy)				printf("<svg width=%d height=%d>\n", tamx, tamy)
#define FECHAR_SVG							printf("</svg>\n")
*/

#define IMAGE_PATH							"http://127.0.0.1/imagens/"

#define ABRIR_LINK(link)					printf("<a xlink:href=%s>\n", link)

#define FECHAR_LINK							printf("</a>\n")


void print_header();
void print_footer();
void imprime(ESTADO e);

#endif
