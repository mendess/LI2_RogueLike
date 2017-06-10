#ifndef __ITEMS_H_
#define __ITEMS_H_

/**
@file items.h
Definição das funções que definem o comportamento dos items
*/

#include "levelMaker.h"
#include "estrutura.h"
#include "calcularCombate.h"
#include "colisions.h"
#include "loot.h"

/** \brief Quantidade de vida restaurada pela poção de vida */
#define HP_POT_POWER			30
/** \brief Quantidade de mana restaurada pela poção de mana */
#define MP_POT_POWER			10

/** \brief Dano causado pelo pergaminho de fogo */
#define SCROLL_FIRE_DMG			35
/** \brief Dano causado pelo pergaminho de relampago */
#define SCROLL_LIGHTNING_DMG	40

/** \brief Custo de mana do pergaminho de fogo */
#define SCROLL_COST_FIRE		40
/** \brief Custo de mana do pergaminho de relampago */
#define SCROLL_COST_LIGHTNING	25
/** \brief Custo de mana do pergaminho de veneno */
#define SCROLL_COST_POISON		20
/** \brief Custo de mana do pergaminho de teleport */
#define SCROLL_COST_TELEPORT	30

/** \brief Array de custos */
#define COST_ARRAY	{SCROLL_COST_FIRE,\
					 SCROLL_COST_LIGHTNING,\
					 SCROLL_COST_POISON,\
					 SCROLL_COST_TELEPORT}

/**
\brief Usa uma potion
@param e Apontador para o Estado do Jogo
@param item Apontador para a poção
@returns 0 se consumiu com sucesso 2 se tem o atributo ao maximo
*/
int usePotion(ESTADO *e,int *item);
/**
\brief Desequipa o item equipado e equipa um novo
@param e Apontador para o Estado do Jogo
@param item Item a equipar
*/
void equipItem(ESTADO *e,int *item);
/**
\brief Devolve o custo de um pergaminho
@param item Pergaminho
@returns Custo
*/
int getSpellCost(int item);
/**
\brief Devolve se o feitiço relampago (amarelo) teria alvos se fosse usado
@param e Estado do Jogo
@returns 1 se sim 0 caso contrario
*/
int lightningHasTargets(ESTADO e);
/**
\brief Usa um item e coloca o campo de feedback no valor certo
@param e Estado do Jogo
@returns Estado do Jogo alterado
*/
ESTADO useItem(ESTADO e);
/**
\brief Devolve o indice de uma posição vazia do inventário
@param inv Inventário
@returns Indice ou INVT_SIZE caso não haja espaço
*/
int getItemSpace(int inv[]);
/**
\brief Devolve o indice do item que o jogador quer apanhar
@param droppedItem Lista dos items dropados
@param pos Posição do item
@returns Indice do item ou MAX_DROPPED_ITEMS se não existir
*/
int getDroppedItem(CHEST droppedItem[], POSICAO pos);
/**
\brief Move um item do chão para o inventátrio do jogador
@param jog Posição do jogador
@param inv Inventário do jogador
@param droppedItems Lista dos items no chão
@param action Ação selecionada
@returns 0 se teve sucesso 3 se o jogador não tem espaço para o item
*/
int pickUpItem(POSICAO jog, int inv[], CHEST droppedItems[], int action);
/**
\brief Comverte uma ação no formato 1XXYY num par de coordenadas X e Y
@param action Ação a converter
@returns Posição convertida
*/
POSICAO itAct2Pos(int action);
/**
\brief Devolve o indice da chest que o jogador quer abrir
@param chests Lista das chests
@param num_chests Número de chests
@param p Posição da chest
@returns Indice da chest ou MAX_CHESTS se não existir
*/
int getChest(CHEST chests[], int num_chests, POSICAO p);
/**
\brief Remove uma chest na lista
@param i Indice da chest
@param chests Lista das chests
@param num_chests Número de chests
*/
void removeChest(int i, CHEST chests[], int num_chests);
/**
\brief Abre uma chest
@param e Apontador para o Estado do Jogo
*/
void openChest(ESTADO *e);
/**
\brief Executa o efeito do pergaminho de fogo
@param e Apontador do Estado do Jogo
*/
void castScroll_Fire(ESTADO *e);
/**
\brief Executa o efeito do pergaminho de teleport
@param e Apontador do Estado do Jogo
*/
void castScroll_Teleport(ESTADO *e);
/**
\brief Verifica se um certa posição ocorre num array de posições
@param targets Lista de posição
@param num_targets Número de posições
@param newTarget Posição a verificar
@returns 1 se for 0 caso contrario
*/
int isRepeat(POSICAO targets[], int num_targets, POSICAO newTarget);
/**
\brief Executa o efeito do pergaminho de relampago
@param e Apontador do Estado do Jogo
*/
void castScroll_Lightning(ESTADO *e);
/**
\brief Executa o efeito de um pergaminho
@param e Estado do Jogo
@returns Estado do Jogo alterado
*/
ESTADO castScroll(ESTADO e);
/**
\brief Controla um item complexo
@param e Estado do Jogo
@returns Estado do Jogo alterado
*/
ESTADO handleComplexItem(ESTADO e);
#endif