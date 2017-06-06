#ifndef __COLISIONS_H__
#define __COLISIONS_H__

#include "estrutura.h"

/**
\brief Verifica se um par de coordenadas esta fora dos limites do mapa
@param p Posição a verficar
*/
int outOfBounds(POSICAO p);
/**
\brief Verifica se esta posição está em cima do caminho entre o heroi e a saida
@param e Estado do jogo
@param p Posição a verificar
@param pathSize Tamanho do caminho
@param path Array de posições do caminho
@return
*/
int isOnPath(POSICAO p, int pathSize, POSICAO path[]);
/**
\brief Verifica se esta algum monstro, pedra ou jogador na posição dada
@param e Estado do jogo
@param p Posição a verificar
*/
int pos_ocupada (ESTADO e, POSICAO p);
/**
\brief Verifica se a saida esta num certo par de coordenadas
@param e Estado do jogo
@param p Posição a verificar
*/
int com_saida (ESTADO e, POSICAO p);
/**
\brief Verifica se o jogador esta num certo par de coordenadas
@param e Estado do jogo
@param p Posição a verificar
*/
int com_jogador (ESTADO e,POSICAO p);
/**
\brief Verifica se existem pedras nas coordenadas dadas
@param e Estado do jogo
@param p Posição a verificar
*/
int com_pedras (ESTADO e, POSICAO p);
/**
\brief Verifica se existem monstros nas coordenadas dadas
@param e Estado do jogo
@param p Posição a verificar
*/
int com_monstros (ESTADO e, POSICAO p);

#endif