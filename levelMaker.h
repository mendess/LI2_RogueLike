#ifndef ___LEVELMAKER_H___
#define ___LEVELMAKER_H___

/**
@file levelMaker.h
Definição das funções para criação de niveis e de calculo de novas posições
*/

#include "estrutura.h"
#include "colisions.h"
#include "genMonsters.h"
#include "path.h"
#include "loot.h"

/** \brief Vida base do Warrior */
#define HP_WARRIOR    100
/** \brief Vida base do Archer */
#define HP_ARCHER     90
/** \brief Vida base do Mage */
#define HP_MAGE       70

/** \brief Mana base do Warrior */
#define MP_WARRIOR    50
/** \brief Mana base do Archer */
#define MP_ARCHER     70
/** \brief Mana base do Mage */
#define MP_MAGE       100

/** \brief Bonus de vida ganho ao passar de nível */
#define NEW_LEVEL_HP_BONUS  30
/** \brief Bonus de mana ganho ao passar de nível */
#define NEW_LEVEL_MP_BONUS  10
/** \brief Bonus de score ganho ao passar de nível */
#define NEW_LEVEL_SC_BONUS  60

/**
\brief Coloca uma pedra numa posição aleatoria válida
@param e Estado do jogo
@param pathSize Tamanho do caminho
@param path Caminho a evitar
@returns Estado do jogo alterado
*/
ESTADO colocar_pedra (ESTADO e, int pathSize, POSICAO path[]);
/**
\brief Coloca um monstro numa posição aleatoria válida
@param e Estado do jogo
@returns Estado do jogo alterado
*/
ESTADO colocar_monstro (ESTADO e);
/**
\brief Coloca todas as pedras para inicializar o estado
@param e Estado do jogo
@param pathSize Tamanho do caminho a evitar
@param path Array de coordenadas do caminho a evitar
@returns Estado do jogo alterado
*/
ESTADO colocar_pedras (ESTADO e, int pathSize, POSICAO path[]);
/**
\brief Coloca todas os monstros para inicializar o estado
@param e Estado do jogo
@returns Estado do jogo alterado
*/
ESTADO colocar_monstros (ESTADO e);
/*
\brief Retorna o hp inicial da classe dada como argumento
@param type O numero da classe
@returns A vida base do jogador
*/
int getClassHp(int type);
/*
\brief Retorna o mp inicial da classe dada como argumento
@param type O numero da classe
@returns A mana base do jogador
*/
int getClassMp(int type);
/**
\brief Inicializa o inventario a vazio
@returns Inventario inicializado
*/
INVT initINVT();
/**
\brief Inicializa o item complexo a 0
@returns Item complexo inicializado
*/
ITEM_U_DAT initComplexItem();
/**
\brief Inicializa o array de items no chão a 0
@param droppedItems Lista de items no chão a inicializar
*/
void initDroppedItems(CHEST droppedItems[]);
/**
\brief Calcula uma nova posição a partir das coordenadas do jogador e da ação
@param jog A posição do jogador
@param act Ação selecionada
@returns Nova posição relativa ao jogador
*/
POSICAO calcularNovaPosicao(POSICAO jog, int act);
/**
\brief Calcula o nova posição do jogador depois de usar a abilidade "lesser teleport" do "Mage"
@param jog Posição do jogador
@param act Ação selecionada
@returns Nova posição do jogador
*/
POSICAO calcularLesserTeleport(POSICAO jog, int act);
/**
\brief Inicializa o estado do jogo
@returns Estado do jogo inicializado
*/
ESTADO inicializar(ESTADO e);
/**
\brief Gera um novo nivel quando o jogador chega a saida
@param e Estado do Jogo
@returns Estado do jogo alterado
*/
ESTADO newLevel(ESTADO e);

#endif
