#ifndef __IA_WOLF__
#define __IA_WOLF__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "IA.h"

/**
@file IAwolf.h
Movimentos e ataques do dragão
*/
/**
Verifica seo arqueiro está entre o jogador e a saida e se a saida está nordeste do jogador
*/
#define BLOQUEAVEL_NE	e.jog.y>p.y && e.jog.x<p.x && p.x<e.saida.x && e.saida.y<p.y && e.saida.x>e.jog.x && e.saida.y<e.jog.y
/**
Verifica seo arqueiro está entre o jogador e a saida e se a saida está noroeste do jogador
*/
#define BLOQUEAVEL_NO   e.jog.y>p.y && e.jog.x>p.x && e.saida.x<p.x && e.saida.y<p.y && e.saida.x<e.jog.x && e.saida.y<e.jog.y
/**
Verifica seo arqueiro está entre o jogador e a saida e se a saida está sudeste do jogador
*/
#define BLOQUEAVEL_SE   e.jog.y<p.y && e.jog.x<p.x && e.saida.x<p.x && e.saida.y>p.y && e.saida.x<e.jog.x && e.saida.y>e.jog.y
/**
Verifica seo arqueiro está entre o jogador e a saida e se a saida está sudoeste do jogador
*/
#define BLOQUEAVEL_SO   e.jog.y<p.y && e.jog.x>p.x && e.saida.x>p.x && e.saida.y>p.y && e.saida.x>e.jog.x && e.saida.y>e.jog.y
/**
\brief Se o jogador estiver a sudeste do lobo este persegue-o nessa direção
@param e Estado do jogo
@param i posição no array dos monstros onde estão as coordendas do lobo
@param p posição atual do lobo
@param a[SIZE][SIZE] matriz do numero de jogadas necessarias para intersetar
o jogador
*/
ESTADO persegue_wolf_SE (ESTADO e,int i,POSICAO p,int a[SIZE][SIZE]);
/**
\brief Se o jogador estiver a nordeste do lobo este persegue-o nessa direção
@param e Estado do jogo
@param i posição no array dos monstros onde estão as coordendas do lobo
@param p posição atual do lobo
@param a[SIZE][SIZE] matriz do numero de jogadas necessarias para intersetar
o jogador
@returns o estado do jogo depois do lobo se ter movido
*/
ESTADO persegue_wolf_NE (ESTADO e,int i,POSICAO p,int a[SIZE][SIZE]);
/**
\brief Se o jogador estiver a sudooeste do lobo este persegue-o nessa direção
@param e Estado do jogo
@param i posição no array dos monstros onde estão as coordendas do lobo
@param p posição atual do lobo
@param a[SIZE][SIZE] matriz do numero de jogadas necessarias para intersetar
o jogador
@returns o estado do jogo depois do lobo se ter movido
*/
ESTADO persegue_wolf_SO (ESTADO e,int i,POSICAO p,int a[SIZE][SIZE]);
/**
\brief Se o jogador estiver a noroeste do lobo este persegue-o nessa direção
@param e Estado do jogo
@param i posição no array dos monstros onde estão as coordendas do lobo
@param p posição atual do lobo
@param a[SIZE][SIZE] matriz do numero de jogadas necessarias para intersetar
o jogador
@returns o estado do jogo depois do lobo se ter movido
*/
ESTADO persegue_wolf_NO (ESTADO e,int i,POSICAO p,int a[SIZE][SIZE]);
/**
\brief Se o lobo não estiver entre o jogador e a saida vai perseguir o jogador
@param e Estado do jogo
@param i posição no array dos monstros onde estão as coordendas do lobo
@param p posição atual do lobo
@param a[SIZE][SIZE] matriz do numero de jogadas necessarias para intersetar
o jogador
@returns o estado do jogo depois do lobo se ter movido
*/
ESTADO persegue_wolf (ESTADO e,int i,POSICAO p,int a[SIZE][SIZE]);
/**
\brief Se o monstro estiver a nordeste do jogador e entre este e a saida
este vai bloquear a passagem ao jogador.
@param e Estado do jogo
@param i posição no array dos monstros onde estão as coordendas do lobo
@param p posição atual do lobo
@param a[SIZE][SIZE] matriz do numero de jogadas necessarias para intersetar
o jogador
*/
ESTADO defesa_WOLF_NE (ESTADO e, int i,POSICAO p,int a[SIZE][SIZE]);
/**
\brief Se o monstro estiver a noroeste do jogador e entre este e a saida
este vai bloquear a passagem ao jogador.
@param e Estado do jogo
@param i posição no array dos monstros onde estão as coordendas do lobo
@param p posição atual do lobo
@param a[SIZE][SIZE] matriz do numero de jogadas necessarias para intersetar
o jogador
@returns o estado do jogo depois do lobo se ter movido
*/
ESTADO defesa_WOLF_NO (ESTADO e, int i,POSICAO p,int a[SIZE][SIZE]);
/**
\brief Se o monstro estiver a sudeste do jogador e entre este e a saida
este vai bloquear a passagem ao jogador.
@param e Estado do jogo
@param i posição no array dos monstros onde estão as coordendas do lobo
@param p posição atual do lobo
@param a[SIZE][SIZE] matriz do numero de jogadas necessarias para intersetar
o jogador
@returns o estado do jogo depois do lobo se ter movido
*/
ESTADO defesa_WOLF_SE (ESTADO e, int i,POSICAO p,int a[SIZE][SIZE]);
/**
\brief Se o monstro estiver a sudoeste do jogador e entre este e a saida
este vai bloquear a passagem ao jogador.
@param e Estado do jogo
@param i posição no array dos monstros onde estão as coordendas do lobo
@param p posição atual do lobo
@param a[SIZE][SIZE] matriz do numero de jogadas necessarias para intersetar
o jogador 
@returns o estado do jogo depois do lobo se ter movido
*/
ESTADO defesa_WOLF_SO (ESTADO e, int i,POSICAO p,int a[SIZE][SIZE]);
/**
\brief coloca na matriz 10 por 10 o numero de jogadas necessarias para
intersetar o jogador a partir de qualquer ponto no mapa
@param e Estado do jogo
@param a[SIZE][SIZE] matriz do numero de jogadas necessarias para intersetar
o jogador 
@param x coordenada x para andar na matriz a  
@param y coordenada y para andar na matriz a
@param i contador do numero de jogadas a fazer para chegar ao jogador
*/
void distancia_WOLF (ESTADO e,int a[SIZE][SIZE],int x,int y,int i);
/**
\brief preenche uma matriz 1'0 por 10 com onumero 50 que será udado para
identificar pedras e monstros.
@param a [10][10] matriz do numero de jogadas necessarias para intersetar
o jogador 
*/
void preenche(int a[SIZE][SIZE]);
/**
\brief Verifica se o jogador está ao alcance do ataque do lobo se
não estiver mas o lobo estiver entre ele e a saida o lobo vai bloquear
a saida ao jogador senão perseguilo-a.
@param e Estado do jogo
@param i posição no array dos monstros onde estão as coordendas do lobo
@param p posição atual do lobo  
@returns o estado do jogo depois do lobo se ter movido ou atacado
o jogador
*/
ESTADO estrat_wolf (ESTADO e,int i,POSICAO p);

#endif