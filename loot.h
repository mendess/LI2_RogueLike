#ifndef __LOOT_H_
#define __LOOT_H_

/**
@file loot.h
Definição das funções que geram os items por nivel
*/

#include <math.h>

#include "estrutura.h"

/** \brief Número que representa a poção de vida */
#define HEALTH_POTION       1
/** \brief Número que representa a poção de mana */
#define MANA_POTION         2
/** \brief Número que representa o pergaminho de fogo */
#define SCROLL_FIRE         3
/** \brief Número que representa a pergaminho de relampago */
#define SCROLL_LIGHTNING    4
/** \brief Número que representa a pergaminho de veneno */
#define SCROLL_POISON		5
/** \brief Número que representa a pergaminho de teleport */
#define SCROLL_TELEPORT     6
/** \brief Número que representa a arma de nível 1 */
#define SWORD_BRONZE        10
/** \brief Número que representa a arma de nível 2 */
#define SWORD_IRON          11
/** \brief Número que representa a arma de nível 3 */
#define SWORD_STEEL         12
/** \brief Número que representa a arma de nível 4 */
#define SWORD_PALLADIUM     13
/** \brief Número que representa a armadura de nível 1 */
#define ARMOUR_BRONZE       14
/** \brief Número que representa a armadura de nível 2 */
#define ARMOUR_IRON         15
/** \brief Número que representa a armadura de nível 3 */
#define ARMOUR_STEEL        16
/** \brief Número que representa a armadura de nivel 4 */
#define ARMOUR_PALLADIUM    17

/** \brief Formula para calcular a probabilidade de gerar um item de tier 1 */
#define TIER1_ODDS(i)	((-(90 / (1 + 79*exp(-(0.5*i)))))+91.125)*1000
/** \brief Formula para calcular a probabilidade de gerar um item de tier 4 */
#define TIER4_ODDS(i)	(89/(1 + 99999999*exp(-0.5*i)))*1000+1
/** \brief Formula para calcular a probabilidade de gerar um item de tier 2 ou 3 */
#define TIER_SHIFT(i)	0.9/(1+170*exp(-0.25*i))

#define SCROLL_ARRAY {SCROLL_FIRE,SCROLL_LIGHTNING,SCROLL_TELEPORT,SCROLL_POISON}
/**
\brief Devolve uma potion gerada aleatoriamente
@returns O número da poção gerada
*/
int generatePotion();
/**
\brief Devolve um scroll gerada aleatoriamente
@returns O número do pergaminho gerada
*/
int generateScroll();
/**
\brief Devolve uma arma gerada aleatoriamente conforme o nível em que o jogador está
@param world_lvl Nível
@returns O número da arma gerada
*/
int generateSword(int world_lvl);
/**
\brief Devolve uma armadura gerada aleatoriamente conforme o nível em que o jogador está
@param world_lvl Nível
@returns O número da armadura gerada
*/
int generateArmour(int world_lvl);
/**
\brief Função mestra que gera os quatro items de cada nível
@param lootTable Tabela de items de um nível
@param world_lvl Nível para o qual os items vão ser gerados
*/
void generateLoot(int lootTable[], int world_lvl);

#endif