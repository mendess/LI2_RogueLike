#ifndef __ARCHER_H__
#define __ARCHER_H__
#include "IA.h"
/*
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
*/
int sem_monstros(ESTADO e,int n,int x,int y);
int sem_pedras(ESTADO e,int n,int x,int y);
ESTADO persegue_NO(ESTADO e,int a[10][10],int i,POSICAO p);
ESTADO persegue_SO(ESTADO e,int a[10][10],int i,POSICAO p);
ESTADO persegue_NE(ESTADO e,int a[10][10],int i,POSICAO p);
ESTADO persegue_SE(ESTADO e,int a[10][10],int i,POSICAO p);
ESTADO persegue_arch(ESTADO e,int a[10][10],int i,POSICAO p);
ESTADO desvia_right(int a[10][10],ESTADO e,int i,POSICAO p);
ESTADO desvia_left(int a[10][10],ESTADO e,int i,POSICAO p);
ESTADO desvia_down(int a[10][10],ESTADO e,int i,POSICAO p);
ESTADO desvia_up(int a[10][10],ESTADO e,int i,POSICAO p);
ESTADO desvia(ESTADO e,int a[10][10],int i,POSICAO p);
int in_range(ESTADO e,POSICAO p);
ESTADO defArcher_NO (ESTADO e,int a[10][10], int i, POSICAO p,int intersect);
ESTADO defArcher_NE (ESTADO e,int a[10][10],int i, POSICAO p,int intersect);
ESTADO defArcher_SO (ESTADO e,int a[10][10],int i, POSICAO p,int intersect);
ESTADO defArcher_SE (ESTADO e,int a[10][10],int i, POSICAO p,int intersect);
void distancia_ARCHER (ESTADO e,int a[10][10],int x,int y,int i);
void preenche_matriz(int a[10][10]);
ESTADO estrat_archer (ESTADO e,int i,POSICAO p);

#endif