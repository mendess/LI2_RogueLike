#ifndef __IA_OGRE__
#define __IA_OGRE__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "IA.h"

/**
@file actionMap.h
Movimentos e ataques do ogre
*/
/**
\brief verifica se para onde o ogre se vai mover existem pedras
@param e Estado do jogo
@param p posição atual do ogre
@returns 1 se a posição estiver ocupada por uma pedra 
*/
int blocked1 (ESTADO e,POSICAO p);
/**
\brief Verifica se para onde o ogre se vai mover existem monstros
@param e Estado do jogo
@param p posição atual do ogre
@returns 1 se a posição estiver ocupada por um monstro 
*/
int blocked2 (ESTADO e,POSICAO p);
/**
\brief verifica se é possivel o ogre mover-se para a posição 
que pretende
@param e Estado do jogo
@param p posição atual do ogre
@returns  se a posição estiver ocupada por uma pedra, um monstro ou 
fora do mapa
*/
int possivel (ESTADO e,POSICAO p);
/**
\brief Coloca o ogre entre o cofre e o jogador para impedir que este 
chegue ao cofre sem passar pelo ogre
@param e Estado do jogo
@param i posição das coordenadas do ogre no array dos monstros
@param chest posição do cofre que está a beira do ogre
@param monstro posição atual do ogre
@returns o estado do jogo depois do ogre se ter movido para defender 
o cofre 
*/
ESTADO blocked_chest(ESTADO e,int i,POSICAO chest,POSICAO monstro);
/**
\brief Identifaca junto a que cofre o ogre está e a posição do cofre 
face ao ogre
@param e Estado do jogo
@param i posição das coordenadas do ogre no array dos monstros
@param p posição atual do ogre
@returns o estado do jogo depois do ogre se ter movido para defender 
o cofre 
*/
ESTADO protect_it(ESTADO e,int i,POSICAO p);
/**
\brief Verifica se o ogre está a beira de um cofre
@param e Estado do jogo
@param p posição atual do ogre
@vreturns 1 se o ogre está a beira do cofre
*/
int next2chest(ESTADO e,POSICAO p);
/**
\brief Verifica se o jogador pode ser atacado , se não 
coloca o ogre entre o cofre e o jogador
@param e Estado do jogo
@param i posição das coordenadas do ogre no array dos monstros
@param p posição atual do ogre
@returns o estado do jogo depois do ogre se ter movido ou atacado
o jogador
*/
ESTADO estrat_ogre (ESTADO e,int i,POSICAO p);


#endif