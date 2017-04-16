#ifndef __LOOT_H_
#define __LOOT_H_

#include <stdlib.h>
#include <time.h>

#include "jogo.h"

#define LOOT_TABLE_SIZE	4

#define TIER1_ODDS(i)	((-(90 / (1 + 79*exp(-(0.5*i)))))+91.125)*1000
#define TIER4_ODDS(i)	(89/(1 + 99999999*exp(-0.5*i)))*1000+1
#define TIER_SHIFT(i)	0.9/(1+170*exp(-0.25*i))

#define HEALTH_POTION 		0
#define MANA_POTION 		1
#define SCROLL_FIRE 		2
#define SCROLL_LIGHTNING 	3
#define SCROLL_TELEPORT		4
#define SWORD_BRONZE 		10
#define SWORD_IRON	 		11
#define SWORD_STEEL 		12
#define SWORD_PALLADIUM		13
#define ARMOUR_BRONZE 		14
#define ARMOUR_IRON 		15
#define ARMOUR_STEEL		16
#define ARMOUR_PALLADIUM	17

char generatePotion();
char generateScroll();
char generateSword(char world_lvl);
char generateArmour(char world_lvl);
char *generateLoot(int world_lvl);

#endif