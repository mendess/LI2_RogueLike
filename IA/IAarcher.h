#ifndef __ARCHER_H__
#define __ARCHER_H__
#include "IA.h"

int blocked1 (ESTADO e,POSICAO p);
int blocked2 (ESTADO e,POSICAO p);
int possivel (ESTADO e,POSICAO p);
ESTADO persegue_arch(ESTADO e,int i,POSICAO p);
POSICAO buscaA1(ESTADO e,int a[][]);
POSICAO buscaA2(ESTADO e,int a[][]);
POSICAO buscaA3(ESTADO e,int a[][]);
POSICAO buscaA4(ESTADO e,int a[][]);
POSICAO mapa2 (ESTADO e,int i,POSICAO p,int q);
ESTADO decide(ESTADO e,int i, POSICAO intersect);
ESTADO defA (ESTADO e, int i, POSICAO p,int num);
ESTADO estrat_archer (ESTADO e,int i,POSICAO p);


#endif