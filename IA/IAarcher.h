#ifndef __ARCHER_H__
#define __ARCHER_H__
#include "IA.h"

int possivel_casa (ESTADO e,POSICAO p);
int in_range(ESTADO e,POSICAO p);
ESTADO desvia(ESTADO e,int i,POSICAO p);
ESTADO persegue_arch(ESTADO e,int i,POSICAO p);
int livre1(ESTADO e,int x,int y);
POSICAO buscaA1(ESTADO e,int a[SIZE][SIZE]);
POSICAO buscaA2(ESTADO e,int a[SIZE][SIZE]);
POSICAO buscaA3(ESTADO e,int a[SIZE][SIZE]);
POSICAO buscaA4(ESTADO e,int a[SIZE][SIZE]);
POSICAO mapa4 (ESTADO e,POSICAO p,int q);
ESTADO decide(ESTADO e,int i, POSICAO intersect);
ESTADO defA (ESTADO e, int i, POSICAO p,int num);
ESTADO estrat_archer (ESTADO e,int i,POSICAO p);


#endif