#ifndef __ANTI_CHEAT_H__
#define __ANTI_CHEAT_H__

/**
@file antiCheat.h
Definição das funções que impedem o jogador de fazer batota mudando a Query String "manualmente"
*/
#include "estrutura.h"
#include "colisions.h"
#include "actionMap.h"
#include "levelMaker.h"
#include "calcularCombate.h"
#include "items.h"
#include "shop.h"
#include "html/html5Playing.h"

/**
\brief Verifica se voltar ao menu é uma "jogada" válida
@param e Estado do jogo
@returns 1 se a jogada for válida 0 se não for
*/
int validMenu(ESTADO e);
/**
\brief Verifica se o jogador pode passar de nível

O jogador pode passar de nível se estiver ao lado da saída
ou se estiver na loja
@param e Estado do jogo
@returns 1 se a jogada for válida 0 se não for
*/
int validNewLevel(ESTADO e);
/**
\brief Verifica se o movimento do jogador é valido

Se não tem uma parede, ou monstro no caminho
@param e Estado do jogo
@returns 1 se a jogada for válida 0 se não for
*/
int validMove(ESTADO e);
/**
\brief Verifica se o ataque do jogador é valido

Se tem um monstro para atacar
@param e Estado do jogo
@returns 1 se a jogada for válida 0 se não for
*/
int validAtack(ESTADO e);
/**
/brief Verifica se o jogador pode apanhar um item do chão

Se tem um item a sua beira para apanhar
@param e Estado do jogo
@returns 1 se a jogada for válida 0 se não for
*/
int validItemPickup(ESTADO e);
/**
\brief Verifica se o item que o jogador escolheu pode ser usado

Verifica se o item existe
@param e Estado do jogo
@returns 1 se a jogada for válida 0 se não for
*/
int validItemUse(ESTADO e);
/**
\brief Verifica se o jogador está ao alcance do boss para o atacar
@param e Estado do jogo
@returns 1 se a jogada for válida 0 se não for
*/
int validBossAtack(ESTADO e);
/**
\brief Verifica se o jogador esta no Main Menu
@param e Estado do jogo
@returns 1 se a jogada for válida 0 se não for
*/
int isInMenu(ESTADO e);
/**
\brief Verifica se o jogador esta no Menu de Seleção da Classe
@param e Estado do jogo
@returns 1 se a jogada for válida 0 se não for
*/
int isInCharSelect(ESTADO e);
/**
\brief Verifica se o jogador está na loja
@param e Estado do jogo
@returns 1 se a jogada for válida 0 se não for
*/
int isInShop(ESTADO e);
/**
\brief Função mestra que verifica se a jogada é valida
@param e Estado do jogo
@returns 1 se a jogada for válida 0 se não for
*/
int validAction(ESTADO e);
#endif