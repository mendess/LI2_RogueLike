#ifndef __BAT_H__
#define __BAT_H__
#include "IA.h"
/**
@file IAbat.h
Movimentos e ataques do morcego
*/
/**
\brief percorre a matriz a procura do primeiro zero a aparecer 
acima do jogador e á direita.
@param e Estado do jogo
@param a [SIZE][SIZE] matriz das interceções.
*/
POSICAO buscaBat1 (ESTADO e,int a[SIZE][SIZE]);
/**
\brief percorre a matriz a procura do primeiro zero a aparecer 
abaixo do jogador e á esquerda.
@param e Estado do jogo
@param a [SIZE][SIZE] matriz das interceções.
*/
POSICAO buscaBat2 (ESTADO e,int a[SIZE][SIZE]);
/**
\brief percorre a matriz a procura do primeiro zero a aparecer 
acima do jogador e á esquerda.
@param e Estado do jogo
@param a [SIZE][SIZE] matriz das interceções.
*/
POSICAO buscaBat3 (ESTADO e,int a[SIZE][SIZE]);
/**
\brief percorre a matriz a procura do primeiro zero a aparecer 
abaixo do jogador e á direita.
@param e Estado do jogo
@param a [SIZE][SIZE] matriz das interceções.
*/
POSICAO buscaBat4 (ESTADO e,int a[SIZE][SIZE]);
/**
\brief calcula a matriz 10 por 10 com o numero de jogadas necessarias 
para chegar ao jogador a intersecção é representada po zeros.
@param e Estado do jogo
@param p posição atual do morcego
@param num numero que representa se o morcego deve intersectar o jogador
a noroeste,nordeste,sudoeste ou sudeste
*/
POSICAO mapa3 (ESTADO e,POSICAO p,int num);
/**
\brief verifica se o morcego está dentro dos limites do mapa e se para
onde ele se vai mover a posição nao está já ocupada por outro monstro.
@param e Estado do jogo
@param x coordenada x para a qual o morcego se quer mover
@param y coordenada y para a qual o morcego se quer mover
*/
int livre (ESTADO e,int x,int y);
/**
\brief Recebe a posição para intersetar o jogador e move o morcego para lá
chegar com o menos numero de jogadas possivel.
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do morcego em questão
@param intersect posição onde o morcego vai intersetar o jogador
*/
ESTADO estrat_bat1 (ESTADO e, int i, POSICAO intersect);
/**
\brief Esta função decide o local onde o morcego vai impedir a passagem do
jogador caso o morcego esteja entre o jogador e a saida.
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do morcego em questão
@param p posicao atual do morcego
@param num cada um dos 4 numeros simboliza se o monstro está a 
noroeste,nordeste,sudoeste ou sudeste do jogador.
*/
ESTADO defesaBat (ESTADO e, int i,POSICAO p,int num);
/**
\brief Verifica se o morcego pode atacar o jogador ,se tal não ocorrer
verifica se o morcego está entre o jogador e a saida  e se tal também
não acontecer o morcego perseguirá o jogador.
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do morcego em questão
@param p posicao atual do morcego
*/
ESTADO estrat_bat(ESTADO e,int i,POSICAO p);

#endif