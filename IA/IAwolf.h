#ifndef __IA_WOLF__
#define __IA_WOLF__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "IA.h"

#define BLOQUEAVEL_NE	e.jog.y>p.y && p.x<e.saida.x && e.saida.y<p.y && e.saida.x>e.jog.x && e.saida.y<e.jog.y
#define BLOQUEAVEL_NO   e.jog.y>p.y && e.saida.x<p.x && e.saida.y<p.y && e.saida.x<e.jog.x && e.saida.y<e.jog.y
#define BLOQUEAVEL_SE   e.jog.y<p.y && e.saida.x<p.x && e.saida.y>p.y && e.saida.x<e.jog.x && e.saida.y>e.jog.y
#define BLOQUEAVEL_SO   e.jog.y<p.y && e.saida.x>p.x && e.saida.y>p.y && e.saida.x>e.jog.x && e.saida.y>e.jog.y

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
void distancia_WOLF (ESTADO e,int a[10][10],int x,int y,int i);
void preenche(int a[10][10]);
ESTADO estrat_wolf (ESTADO e,int i,POSICAO p);
#endif