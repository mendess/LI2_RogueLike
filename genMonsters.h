#ifndef __GEN_MONSTER_H__
#define __GEN_MONSTER_H__

#include <math.h>

#include "colisions.h"
#include "jogo.h"

#define MON_HP_WOLF		10
#define MON_HP_BAT		5
#define MON_HP_OGRE		35
#define MON_HP_ARCHER	10
#define MON_HP_DRAGON	80

#define WOLF_ODDS(i)	((-(90 / (1 + 79*exp(-(0.5*i)))))+91.125)*1000
#define ARCHER_ODDS(i)	(89/(1 + 99999999*exp(-0.5*i)))*1000+1
#define TIER_SHIFT(i)	0.9/(1+170*exp(-0.25*i))

ESTADO genBoss(ESTADO e);
ESTADO genBossBattle(ESTADO e);
char getMonsterNumber(char worldLvl);
char setMonsterType(char worldLvl);
char getMonsterHP(char type);
ESTADO placeMonster(ESTADO e, int index);
ESTADO genMonsters(ESTADO e);
#endif