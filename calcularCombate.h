#ifndef __CLCOMB_H__
#define __CLCOMB_H__

#include "estrutura.h"
#include "levelMaker.h"

#define WOLF_SCORE    10
#define BAT_SCORE     10
#define ARCHER_SCORE  8
#define OGRE_SCORE    15

#define SCORE_GAIN_ARRAY	{WOLF_SCORE,BAT_SCORE,OGRE_SCORE,ARCHER_SCORE}

#define WOLF_GOLD    10
#define BAT_GOLD     10
#define ARCHER_GOLD  8
#define OGRE_GOLD    15

#define GOLD_DROP_ARRAY		{WOLF_GOLD,BAT_GOLD,OGRE_GOLD,ARCHER_GOLD}

#define WARRIOR_BASE_DMG	20
#define ARCHER_BASE_DMG		15
#define MAGE_BASE_DMG		13

#define BASE_DMG_ARRAY		{0,WARRIOR_BASE_DMG,ARCHER_BASE_DMG,MAGE_BASE_DMG}

#define SWORD_BRONZE_DMG	5
#define SWORD_IRON_DMG		10
#define SWORD_STEEL_DMG		15
#define SWORD_PALLADIUM_DMG	20

#define WEAPON_DMG_ARRAY 	{0,SWORD_BRONZE_DMG,SWORD_IRON_DMG,SWORD_STEEL_DMG,SWORD_PALLADIUM_DMG}

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
void killMonster(int i, MSTR monstros[], int num_monstros);
void dropItem(CHEST droppedItems[], int *item, POSICAO pos);
void dropItemFromMSTR(int lootTable[], CHEST droppedItems[], int x, int y);
int updateScore(int type);
int goldDrop(int type);
POSICAO calculaRangedAtackPos(POSICAO p,int act);
int getMonstro(ESTADO e, POSICAO p);
int hitMonster(ESTADO *e,POSICAO target,int dmg);
int calcPlayerDmg(int classe, INVT bag);
ESTADO calcularCombate(ESTADO e);

#endif