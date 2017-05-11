#ifndef __ARCHER_H__
#define __ARCHER_H__
#include "IA.h"

int block_pedra (ESTADO e,POSICAO p);
int block_monst (ESTADO e,POSICAO p);
int possivel_casa (ESTADO e,POSICAO p);
ESTADO persegue_arch(ESTADO e,int i,POSICAO p);
POSICAO buscaA1(ESTADO e,int a[SIZE][SIZE]);
POSICAO buscaA2(ESTADO e,int a[SIZE][SIZE]);
POSICAO buscaA3(ESTADO e,int a[SIZE][SIZE]);
POSICAO buscaA4(ESTADO e,int a[SIZE][SIZE]);
POSICAO mapa4 (ESTADO e,int i,POSICAO p,int q);
ESTADO decide(ESTADO e,int i, POSICAO intersect);
ESTADO defA (ESTADO e, int i, POSICAO p,int num);
ESTADO estrat_archer (ESTADO e,int i,POSICAO p);


#endif