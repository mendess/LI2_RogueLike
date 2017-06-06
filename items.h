#ifndef __ITEMS_H_
#define __ITEMS_H_

#include "levelMaker.h"
#include "estrutura.h"
#include "calcularCombate.h"
#include "colisions.h"

#define HP_POT_POWER			30
#define MP_POT_POWER			10

#define SCROLL_FIRE_DMG			35
#define SCROLL_LIGHTNING_DMG	40

#define SCROLL_COST_FIRE		40
#define SCROLL_COST_LIGHTNING	25
#define SCROLL_COST_POISON		20
#define SCROLL_COST_TELEPORT	30

#define COST_ARRAY	{SCROLL_COST_FIRE,\
					 SCROLL_COST_LIGHTNING,\
					 SCROLL_COST_POISON,\
					 SCROLL_COST_TELEPORT}

void usePotion(ESTADO *e,int *item);
void equipItem(ESTADO *e,int *item);
int getSpellCost(int item);
ESTADO useItem(ESTADO e);
POSICAO itAct2Pos(int action);
int hitMonster(ESTADO *e,POSICAO target,int dmg);
void castScroll_Fire(ESTADO *e);
void castScroll_Teleport(ESTADO *e);
void castScroll_Lightning(ESTADO *e);
ESTADO castScroll(ESTADO e);
ESTADO handleComplexItem(ESTADO e);
#endif