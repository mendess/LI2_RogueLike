#ifndef ___LEVELMAKER_H___
#define ___LEVELMAKER_H___

#include <stdlib.h>

#include "jogo.h"
#include "colisions.h"

#define HP_WARRIOR    101
#define HP_ARCHER     91
#define HP_MAGE       71

#define MP_WARRIOR    51
#define MP_ARCHER     71
#define MP_MAGE       101


ESTADO colocar_pedra (ESTADO e, int pathSize, POSICAO path[]);
ESTADO colocar_monstro (ESTADO e);
ESTADO colocar_pedras (ESTADO e, int pathSize, POSICAO path[]);
ESTADO colocar_monstros (ESTADO e);
char getClassHp(char type);
char getClassMp(char type);

#endif