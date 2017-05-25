#ifndef __IA_WOLF__
#define __IA_WOLF__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "IA.h"
/*
ESTADO persegue_wolf(ESTADO e,int i,POSICAO p);
int impossivel(ESTADO e,POSICAO pos);
POSICAO anda_vertical(POSICAO atual,POSICAO alternativa);
POSICAO vertical1(ESTADO e,POSICAO pos);
POSICAO direcao(POSICAO pos,POSICAO intersect);
POSICAO tracker1 (ESTADO e,POSICAO p, POSICAO intersect);
int blocked1 (ESTADO e,POSICAO p);
int blocked2 (ESTADO e,POSICAO p);
int possivel (ESTADO e,POSICAO p);
int primeira_livre (ESTADO e,POSICAO p);
POSICAO altera1(ESTADO e, POSICAO seguinte);
POSICAO altera2(ESTADO e, POSICAO seguinte);
POSICAO altera3(ESTADO e, POSICAO seguinte);
POSICAO altera4(ESTADO e, POSICAO seguinte);
POSICAO *corrige (ESTADO e,POSICAO caminho[],POSICAO q,POSICAO intersect);
void vertical(ESTADO e,POSICAO caminho[],int i);
int contacaminho(POSICAO caminho[],POSICAO q);
POSICAO tracker(ESTADO e,POSICAO p, POSICAO intersect);
POSICAO buscaW1 (ESTADO e,int a[SIZE][SIZE]);
POSICAO buscaW2 (ESTADO e,int a[SIZE][SIZE]);
POSICAO buscaW3 (ESTADO e,int a[SIZE][SIZE]);
POSICAO buscaW4 (ESTADO e,int a[SIZE][SIZE]);
POSICAO mapa1 (ESTADO e,POSICAO p,int q);
ESTADO defW1(ESTADO e,int i,POSICAO p);
ESTADO defW2(ESTADO e,int i,POSICAO p);
ESTADO defW3(ESTADO e,int i,POSICAO p);
ESTADO defW4(ESTADO e,int i,POSICAO p);
ESTADO estrat_wolf (ESTADO e,int i,POSICAO p);
*/
ESTADO persegue_wolf_SE (ESTADO e,int i,POSICAO p,int a[10][10]);
ESTADO persegue_wolf_NE (ESTADO e,int i,POSICAO p,int a[10][10]);
ESTADO persegue_wolf_SO (ESTADO e,int i,POSICAO p,int a[10][10]);
ESTADO persegue_wolf_NO (ESTADO e,int i,POSICAO p,int a[10][10]);
ESTADO persegue_wolf (ESTADO e,int i,POSICAO p,int a[10][10]);
ESTADO defW1 (ESTADO e, int i,POSICAO p,int a[10][10]);
ESTADO defW2 (ESTADO e, int i,POSICAO p,int a[10][10]);
ESTADO defW3 (ESTADO e, int i,POSICAO p,int a[10][10]);
ESTADO defW4 (ESTADO e, int i,POSICAO p,int a[10][10]);
int sem_pedras(ESTADO e,int n,int x,int y);
void dist (ESTADO e,int a[10][10],int x,int y,int i);
void preenche(int a[10][10]);
ESTADO estrat_wolf (ESTADO e,int i,POSICAO p);
#endif