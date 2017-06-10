#ifndef __COLISIONS_H__
#define __COLISIONS_H__


/**
@file colisions.h
Definição das funções que verificam se alguma entidade existe num certo sitio
*/
#include "estrutura.h"

/**
\brief Verifica se um par de coordenadas esta fora dos limites do mapa
@param p Posição a verficar
@returns 1 se a posição estiver fora dos limite do mapa 0 caso contrario
*/
int outOfBounds(POSICAO p);
/**
\brief Verifica se esta posição está em cima do caminho entre o jogador e a saida
@param p Posição a verificar
@param pathSize Tamanho do caminho
@param path Array de posições do caminho
@returns 1 se a posição estiver no caminho 0 caso contrario
*/
int isOnPath(POSICAO p, int pathSize, POSICAO path[]);
/**
\brief Verifica se esta algum monstro, pedra ou jogador na posição dada
@param e Estado do jogo
@param p Posição a verificar
@returns 1 se sim 0 caso contrario
*/
int pos_ocupada (ESTADO e, POSICAO p);
/**
\brief Verifica se uma posição está completamente vazia
@param e Estado do jogo
@param x Coordenada x da posição
@param y Coordenada y da posição
@returns 1 se estiver vazia ou 0 caso contrario
*/
int pos_completamente_livre(ESTADO e, int x, int y);
/**
\brief Verifica se a saida esta num certo par de coordenadas
@param e Estado do jogo
@param p Posição a verificar
@returns 1 se sim 0 caso contrario
*/
int com_saida (ESTADO e, POSICAO p);
/**
\brief Verifica se o jogador esta num certo par de coordenadas
@param e Estado do jogo
@param p Posição a verificar
@returns 1 se sim 0 caso contrario
*/
int com_jogador (ESTADO e,POSICAO p);
/**
\brief Verifica se existem pedras nas coordenadas dadas
@param e Estado do jogo
@param p Posição a verificar
@returns 1 se sim 0 caso contrario
*/
int com_pedras (ESTADO e, POSICAO p);
/**
\brief Verifica se existem monstros nas coordenadas dadas
@param e Estado do jogo
@param p Posição a verificar
@returns 1 se sim 0 caso contrario
*/
int com_monstros (ESTADO e, POSICAO p);
/**
\brief Verifica se existem chests nas coordenadas dadas
@param e Estado do jogo
@param p Posição a verificar
@returns 1 se sim 0 caso contrario
*/
int com_chest(ESTADO e, POSICAO p);
/**
\brief Verifica se num certo par de coordenadas existe um item no chão
@param droppedItems Lista dos items no chão
@param p Posição a verificar
@returns 1 se existir o item 0 caso contrario
*/
int com_droppedItem(CHEST droppedItems[], POSICAO p);
/**
\brief Verifica o boss está nas coordenadas
@param e Estado do jogo
@param p Posição a verificar
@returns 1 se sim 0 caso contrario
*/
int isBoss(ESTADO e, POSICAO p);

#endif