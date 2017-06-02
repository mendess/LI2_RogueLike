#ifndef __LOOT_H_
#define __LOOT_H_

#include <math.h>

#include "estrutura.h"

#define HEALTH_POTION       1
#define MANA_POTION         2
#define SCROLL_FIRE         3
#define SCROLL_LIGHTNING    4
#define SCROLL_POISON		5
#define SCROLL_TELEPORT     6
#define SWORD_BRONZE        10
#define SWORD_IRON          11
#define SWORD_STEEL         12
#define SWORD_PALLADIUM     13
#define ARMOUR_BRONZE       14
#define ARMOUR_IRON         15
#define ARMOUR_STEEL        16
#define ARMOUR_PALLADIUM    17

#define TIER1_ODDS(i)	((-(90 / (1 + 79*exp(-(0.5*i)))))+91.125)*1000
#define TIER4_ODDS(i)	(89/(1 + 99999999*exp(-0.5*i)))*1000+1
#define TIER_SHIFT(i)	0.9/(1+170*exp(-0.25*i))

/**
\brief Devolve uma potion gerada aleatoriamente
*/
int generatePotion();
/**
\brief Devolve um scroll gerada aleatoriamente
*/
int generateScroll();
/**
\brief Devolve uma arma gerada aleatoriamente 
	conforme o nivel em que o jogador está
@param world_lvl Nível
*/
int generateSword(int world_lvl);
/**
\brief Devolve uma armadura gerada aleatoriamente 
	conforme o nivel em que o jogador está
@param world_lvl Nível
*/
int generateArmour(int world_lvl);
/**
\brief Função mestra que gera os quatro items de cada nível
@param lootTable Tabela de items de um nível
@param world_lvl Nível para o qual os items vão ser gerados
*/
void generateLoot(int lootTable[], int world_lvl);

#endif