#ifndef __IA_OGRE__
#define __IA_OGRE__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "IA.h"

int impossivel(ESTADO e,POSICAO pos);
POSICAO move_vertical(POSICAO atual,POSICAO alternativa);
POSICAO distancia(ESTADO e,POSICAO pos);
POSICAO instrucoes(POSICAO pos,POSICAO intersect);
POSICAO tracker_chest (ESTADO e,POSICAO p, POSICAO intersect);
POSICAO nearest_chest(ESTADO e,POSICAO p);
ESTADO  track_chest(ESTADO e,int i,POSICAO p);
ESTADO defO(ESTADO e,POSICAO c,POSICAO m,int i);
ESTADO protect_it(ESTADO e,int i,POSICAO pos_monst);
int next2chest(ESTADO e,int i,POSICAO p);
ESTADO estrat_ogre (ESTADO e,int i,POSICAO p);


#endif