#ifndef __COLISIONS_H__
#define __COLISIONS_H__

#include "jogo.h"

int outOfBounds(POSICAO p);
int isOnPath(POSICAO p, int pathSize, POSICAO path[]);
int pos_ocupada (ESTADO e, POSICAO p);
int com_jogador (ESTADO e,POSICAO p);
int com_pedras (ESTADO e, POSICAO p);
int com_monstros (ESTADO e, POSICAO p);
int isBoss(ESTADO e, POSICAO p);
#endif