#ifndef __ANTI_CHEAT_H__
#define __ANTI_CHEAT_H__

#include "estrutura.h"
#include "colisions.h"
#include "actionMap.h"
#include "levelMaker.h"

/**
\brief Verifica se voltar ao menu é uma "jogada" válida
@param e Estado do jogo
*/
int validMenu(ESTADO e);
/**
\brief Verifica se o jogador pode passar de nível
O jogador pode passar de nível se estiver ao lado da saída
ou se estiver na loja
@param e Estado do jogo
*/
int validNewLevel(ESTADO e);
/**
\brief Verifica se o movimento do jogador é valido
@param e Estado do jogo
*/
int validMove(ESTADO e);
/**
\brief Verifica se o ataque do jogador é valido
@param e Estado do jogo
*/
int validAtack(ESTADO e);
/**
\brief Verifica se o item que o jogador escolheu pode ser usado
Verifica se o item existe
@param e Estado do jogo
*/
int validItemUse(ESTADO e);
/**
\brief Verifica se o jogador está ao alcance do boss para o atacar
@param e Estado do jogo
*/
int validBossAtack(ESTADO e);
/**
\brief Verifica se o jogador esta no Main Menu
@param e Estado do jogo
*/
int isInMenu(ESTADO e);
/**
\brief Verifica se o jogador esta no Menu de Seleção da Classe
@param e Estado do jogo
*/
int isInCharSelect(ESTADO e);
/**
\brief Verifica se o jogador está na loja
@param e Estado do jogo
*/
int isInShop(ESTADO e);
/**
\brief Função mestra que verifica se a jogada é valida
@param e Estado do jogo
*/
int validAction(ESTADO e);
#endif
