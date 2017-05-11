#ifndef __ANTI_CHEAT_H__
#define __ANTI_CHEAT_H__

#include "jogo.h"
#include "colisions.h"

int validMenu(ESTADO e);
int validNewLevel(ESTADO e);
int validMove(ESTADO e);
int validAtack(ESTADO e);
int validItemUse(ESTADO e);
int validBossAtack(ESTADO e);
int isInMenu(ESTADO e);
int isInCharSelect(ESTADO e);
int isInShop(ESTADO e);

int validAction(ESTADO e);
#endif