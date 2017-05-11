#ifndef __LOOT_H_
#define __LOOT_H_

#include <math.h>

#include "jogo.h"

#define TIER1_ODDS(i)	((-(90 / (1 + 79*exp(-(0.5*i)))))+91.125)*1000
#define TIER4_ODDS(i)	(89/(1 + 99999999*exp(-0.5*i)))*1000+1
#define TIER_SHIFT(i)	0.9/(1+170*exp(-0.25*i))

char generatePotion();
char generateScroll();
char generateSword(char world_lvl);
char generateArmour(char world_lvl);
void generateLoot(char lootTable[], int world_lvl);

#endif