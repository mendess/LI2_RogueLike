#ifndef __ITEMS_H_
#define __ITEMS_H_

#include "levelMaker.h"
#include "jogo.h"

#define HP_POT_POWER	30
#define MP_POT_POWER	10


void usePotion(ESTADO *e,char *item);
void equipItem(ESTADO *e,char *item);
ESTADO useItem(ESTADO e);
#endif