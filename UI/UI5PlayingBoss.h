#ifndef __UI5_BOSS__
#define __UI5_BOSS__

/**
@file UI5PlayingBoss.h
Definição das funções que imprimem os ataques do dragão
*/

#include <stdio.h>

#include "../estrutura.h"
#include "UIMacros.h"

/**
\brief Decide qual a imagem do dragao conforme o turno
@param turn Turno do jogo
@returns Indice da imagem
*/
int getDragonImg(int turn);
/**
\brief Imprime as zonas que vão ser afetadas pelas "fireballs" do dragão ou as "fireballs" em si
@param e Estado do Jogo
*/
void i_fireballs(ESTADO e);
/**
\brief Imprime a sombra do dragão quando ele muda de lado
@param side Lado para onde vai
*/
void i_shadow(int side);

// SIDE 0
/**
\brief Imprime as zonas que vão ser afetadas pelo "wingAttack" do dragão ou o "wingAttack" em si se o dragão estiver na parte de cima do mapa
@param e Estado do Jogo
*/
void i_wingAttack0(ESTADO e);
/**
\brief Imprime as zonas que vão ser afetadas pelo "fireCone" do dragão ou o "fireCone" em si se o dragão estiver na parte de cima do mapa
@param e Estado do Jogo
*/
void i_fireCone0(ESTADO e);
/**
\brief Imprime as zonas que vão ser afetadas pelos ataques do dragão ou os ataques em si se o dragão estiver na parte de cima do mapa
@param e Estado do Jogo
*/
void imprime_boss0(ESTADO e);

// SIDE 1
/**
\brief Imprime as zonas que vão ser afetadas pelo "wingAttack" do dragão ou o "wingAttack" em si se o dragão estiver na parte de baixo do mapa
@param e Estado do Jogo
*/
void i_wingAttack1(ESTADO e);
/**
\brief Imprime as zonas que vão ser afetadas pelo "fireCone" do dragão ou o "fireCone" em si se o dragão estiver na parte de baixo do mapa
@param e Estado do Jogo
*/
void i_fireCone1(ESTADO e);
/**
\brief Imprime as zonas que vão ser afetadas pelos ataques do dragão ou os ataques em si se o dragão estiver na parte de baixo do mapa
@param e Estado do Jogo
*/
void imprime_boss1(ESTADO e);
#endif