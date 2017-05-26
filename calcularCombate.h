#ifndef __CLCOMB_H__
#define __CLCOMB_H__

#include "estrutura.h"
#include "levelMaker.h"

#define WOLF_SCORE    10
#define BAT_SCORE     10
#define ARCHER_SCORE  8
#define OGRE_SCORE    15

#define WOLF_GOLD    10
#define BAT_GOLD     10
#define ARCHER_GOLD  8
#define OGRE_GOLD    15

#define WARRIOR_BASE_DMG	20
#define ARCHER_BASE_DMG		15
#define MAGE_BASE_DMG		13

#define SWORD_BRONZE_DMG	5
#define SWORD_IRON_DMG		10
#define SWORD_STEEL_DMG		15
#define SWORD_PALLADIUM_DMG	20

/**
\brief Verifica se um monstro está numa certa posição
@param monPos Posição a verificar
@param monster Monstro a verificar
*/
int samePos(POSICAO monPos, MSTR monster);
/**
\brief Remove um monstro do array de monstros
@param i Indice onde está o monstro que vai ser removido
@param monPos Posição a verificar
@param monster Monstro a verificar
*/
void killMonster(int i, MSTR monstros[], char num_monstros);
int updateScore(char type);
int goldDrop(char type);
char calcPlayerDmg(char classe, INVT bag);
ESTADO calcularCombate(ESTADO e);

#endif
