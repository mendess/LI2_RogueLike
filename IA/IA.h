#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "../move_monst.h"
#include "../jogo.h"
/*
ESTADO mapa1 (Estado e,int i,POSICAO p);
int livre (ESTADO e,int x,int y);
POSICAO buscaB1 (ESTADO mov);
POSICAO buscaB2 (ESTADO mov);
POSICAO buscaB3 (ESTADO mov);
POSICAO buscaB4 (ESTADO mov);
ESTADO estrat_bat1 (ESTADO e, int i, POSICAO intersect);
ESTADO defB1 (ESTADO e, int i,POSICAO p);
ESTADO defB2 (ESTADO e, int i,POSICAO p);
ESTADO defB3 (ESTADO e, int i,POSICAO p);
ESTADO defB4 (ESTADO e, int i,POSICAO p);
ESTADO estrat_bat(ESTADO e,int i,POSICAO p);

ESTADO estrat_ogre (ESTADO e,int i,POSICAO p);

ESTADO persegue_arch(ESTADO e,int i,POSICAO p);
POSICAO buscaA1(int a[][]);
POSICAO buscaA2(int a[][]);
POSICAO buscaA3(int a[][]);
POSICAO buscaA4(int a[][]);
POSICAO mapa1 (Estado e,int i,POSICAO p,int q);
ESTADO decide(ESTADO e,int i, POSICAO intersect);
ESTADO defA1 (ESTADO e, int i, POSICAO p);
ESTADO defA2 (ESTADO e, int i, POSICAO p);
ESTADO defA3 (ESTADO e, int i, POSICAO p);
ESTADO defA4 (ESTADO e, int i, POSICAO p);
ESTADO estrat_archer (ESTADO e,int i,POSICAO p);


int blocked1 (ESTADO e,POSICAO p);
int blocked2 (ESTADO e,POSICAO p);
int possivel (ESTADO e,POSICAO p);
int primeira_livre (ESTADO e,POSICAO p);
POSICAO altera1(ESTADO e, POSICAO seguinte);
POSICAO altera2(ESTADO e, POSICAO seguinte);
POSICAO altera3(ESTADO e, POSICAO seguinte);
POSICAO altera4(ESTADO e, POSICAO seguinte);
void corrige (ESTADO e,POSICAO caminho[],POSICAO q,POSICAO intersect);
int contacaminho(int caminho[],POSICAO intersect);
void vertical(ESTADO e,int caminho[],int i);
POSICAO tracker(ESTADO e,POSICAO p, POSICAO intersect);
ESTADO mapa1 (Estado e,int i,POSICAO p);
int livre1(ESTADO e,int x,int y);
POSICAO buscaW1 (int a[][]);
POSICAO buscaW2 (int a[][]);
POSICAO buscaW3 (int a[][]);
POSICAO buscaW4 (int a[][]);
ESTADO estrat_wolf (ESTADO e,int i,POSICAO p);
ESTADO defW1(ESTADO e,int i,POSICAO p);
ESTADO defW2(ESTADO e,int i,POSICAO p);
ESTADO defW3(ESTADO e,int i,POSICAO p);
ESTADO defW4(ESTADO e,int i,POSICAO p);
ESTADO persegue_wolf(ESTADO e,int i,POSICAO p);
*/