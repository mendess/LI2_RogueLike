#ifndef ___LEVELMAKER_H___
#define ___LEVELMAKER_H___

#include <stdlib.h>

#include "jogo.h"

#define HP_WARRIOR    100
#define HP_ARCHER     90
#define HP_MAGE       70

#define MP_WARRIOR    50
#define MP_ARCHER     70
#define MP_MAGE       100

int isOnPath(ESTADO e, POSICAO p, int pathSize, POSICAO path[]);
int pos_ocupada (ESTADO e, POSICAO p);
int com_jogador (ESTADO e,POSICAO p);
int com_pedras (ESTADO e, POSICAO p);
int com_monstros (ESTADO e, POSICAO p);
ESTADO colocar_pedra (ESTADO e, int pathSize, POSICAO path[]);
ESTADO colocar_monstro (ESTADO e);
ESTADO colocar_pedras (ESTADO e, int pathSize, POSICAO path[]);
ESTADO colocar_monstros (ESTADO e);
char getClassHp(char type);
char getClassMp(char type);

#endif