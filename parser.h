#ifndef ___PARSER_H___
#define ___PARSER_H___

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "jogo.h"
#include "estado.h"

/*
#define COMECAR_HTML						printf("Content-Type: text/html\n\n")


#define ABRIR_SVG(tamx, tamy)				printf("<svg width=%d height=%d>\n", tamx, tamy)


#define FECHAR_SVG							printf("</svg>\n")
*/

#define ABRIR_LINK(link)					printf("<a xlink:href=%s>\n", link)


#define FECHAR_LINK							printf("</a>\n")


void print_header();
void print_footer();
int outOfBounds(POSICAO p);
int isMonster(ESTADO e, POSICAO p);
int getDirection(ESTADO e,POSICAO p);
void imprime_background ();
void imprime_casa (int r,POSICAO p);
void imprime_jogador (ESTADO e);
 void imprime_jogadas (ESTADO e);
  void criar_movimento (ESTADO e, POSICAO p);
   void imprime_movimento (ESTADO e,POSICAO p);
void imprime_monstros (ESTADO e);
void imprime_pedras (ESTADO e);
void imprime_saida (POSICAO p);

#endif