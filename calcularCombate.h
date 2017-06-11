#ifndef __CLCOMB_H__
#define __CLCOMB_H__

/**
@file calcularCombate.h
Definição das funções para calcular o dano que o jogador vai dar aos monstros
*/
#include "estrutura.h"
#include "levelMaker.h"

/** \brief Score que o lobo dá ao morrer */
#define WOLF_SCORE    10
/** \brief Score que o morcego dá ao morrer */
#define BAT_SCORE     10
/** \brief Score que o ogre dá ao morrer */
#define OGRE_SCORE    15
/** \brief Score que o arqueiro dá ao morrer */
#define ARCHER_SCORE  8

/** \brief Array de ganho de scores */
#define SCORE_GAIN_ARRAY	{WOLF_SCORE,BAT_SCORE,OGRE_SCORE,ARCHER_SCORE}

/** \brief Dinheiro que o lobo dá ao morrer */
#define WOLF_GOLD    10
/** \brief Dinheiro que o morcego dá ao morrer */
#define BAT_GOLD     10
/** \brief Dinheiro que o ogre dá ao morrer */
#define OGRE_GOLD    15
/** \brief Dinheiro que o arqueiro dá ao morrer */
#define ARCHER_GOLD  8

/** \brief Array de ganho de dinheiro */
#define GOLD_DROP_ARRAY		{WOLF_GOLD,BAT_GOLD,OGRE_GOLD,ARCHER_GOLD}

/** \brief Array de dano base */
#define BASE_DMG_ARRAY		{0,WARRIOR_BASE_DMG,ARCHER_BASE_DMG,MAGE_BASE_DMG}

/** \brief Array de dano das armas */
#define WEAPON_DMG_ARRAY 	{0,SWORD_BRONZE_DMG,SWORD_IRON_DMG,SWORD_STEEL_DMG,SWORD_PALLADIUM_DMG}

/**
\brief Verifica se um monstro está numa certa posição
@param monPos Posição a verificar
@param monster Monstro a verificar
@returns 1 se sim 0 caso contrario
*/
int samePos(POSICAO monPos, MSTR monster);
/**
\brief Remove um monstro do array de monstros
@param i Indice onde está o monstro que vai ser removido
@param monstros Lista de monstros
@param num_monstros Número de monstros no array
*/
void killMonster(int i, MSTR monstros[], int num_monstros);
/**
\brief Coloca um item no chão
@param droppedItems Lista de espaços no chão para por items
@param item Item a colocar no chão
@param pos Posição onde colocar o item
*/
void dropItem(CHEST droppedItems[], int *item, POSICAO pos);
/**
\brief Coloca um item no chão na posição de um monstro
@param lootTable Tabla de items que podem sair
@param droppedItems Lista dos espaços no chão para por items
@param x Coordenada x do monstro que morreu
@param y Coordenada y do monstro que morreu
*/
void dropItemFromMSTR(int lootTable[], CHEST droppedItems[], int x, int y);
/**
\brief Calcula o dano que o jogador vai causar
@param classe Classe do jogador
@param bag Inventário do jogador
@returns O valor do dano
*/
int calcPlayerDmg(int classe, INVT bag);
/**
\brief Retorna quanto score o jogador ganhou
@param type Tipo do monstro que morreu
@returns Quantidade de score ganho
*/
int updateScore(int type);
/**
\brief Retorna quanto dinheiro o jogador ganhou
@param type Tipo do monstro que morreu
@returns Quantidade de dinheiro ganho
*/
int goldDrop(int type);
/**
\brief Calcula a posição que o jogador atacou quando ataca à distância
@param p Posição do jogador
@param act Ação selecionada
@returns Posição atacada
*/
POSICAO calculaRangedAtackPos(POSICAO p,int act);
/**
\brief Retorna o indice de um monstro numa posição
@param e Estado do jogo
@param p Posição do monstros
@returns Indice ou o MAX_MONSTROS se não existir
*/
int getMonstro(ESTADO e, POSICAO p);
/**
\brief Causa dano a um monstro e mata-o se ficar sem vida
@param e Apontador para o Estado do jogo
@param target Posição alvo do ataque
@param dmg Dano a causar
@returns 1 se atingiu um monstro 0 caso contrario
*/
int hitMonster(ESTADO *e,POSICAO target,int dmg);
/**
\brief Função mestra que calcula o combate com ataques basicos
@param e Estado do jogo
@returns Estado do jogo alterado
*/
ESTADO calcularCombate(ESTADO e);
/**
\brief Função que tira vida/mata monstros envenenados
@param e Apontador para o Estado do jogo
*/
void poison_monstros(ESTADO *e);

#endif