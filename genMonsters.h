#ifndef __GEN_MONSTER_H__
#define __GEN_MONSTER_H__


/**
@file genMonster.h
Definição das funções que geram os monstros para cada nível
*/
#include <math.h>

#include "colisions.h"
#include "loot.h"
#include "jogo.h"

/** \brief Vida base do lobo */
#define MON_HP_WOLF		10
/** \brief Vida base do morcego */
#define MON_HP_BAT		5
/** \brief Vida base do ogre */
#define MON_HP_OGRE		35
/** \brief Vida base do arqueiro */
#define MON_HP_ARCHER	10
/** \brief Vida base do dragão */
#define MON_HP_DRAGON	80

/**
\brief Gera o boss
@param e Estado do jogo
@returns Estado do jogo alterado
*/
ESTADO genBoss(ESTADO e);
/**
\brief Gera uma boss battle
@param e Estado do jogo
@returns Estado do jogo alterado
*/
ESTADO genBossBattle(ESTADO e);
/**
\brief Devolve o número de monstros de um nível
@param worldLvl Nível do jogo
@returns Número de monstros
*/
int getNumMonst(int worldLvl);
/**
\brief Devolve a vida base do uma monstro
@param type Tipo de monstro
@returns A vida base desse monstro
*/
int getMonsterHP(int type);
/**
\brief Coloca um monstro no mapa
@param e Estado do jogo
@param type Tipo do monstro
@returns Estado do jogo alterado
*/
ESTADO placeMonster(ESTADO e,int type);
/**
\brief Coloca um ogre no mapa e a sua chest
@param e Estado do jogo
@returns Estado do jogo alterado
*/
ESTADO placeOgre(ESTADO e);
/**
\brief Coloca uma chest perto do ogre
@param e Estado do jogo
@param chest Chest com a posicao do ogre
@returns Estado do jogo alterado
*/
CHEST genChest(ESTADO e, CHEST chest);
/**
\brief Função mestra que gera os monstros todos
@param e Estado do jogo
@returns Estado do jogo alterado
*/
ESTADO genMonsters(ESTADO e);
#endif