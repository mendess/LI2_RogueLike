#ifndef __UI5_BOSS__
#define __UI5_BOSS__

/**
@file UI5PlayingBoss.h
Definição das funções que imprimem os ataques do dragão
*/

#include "UI5Playing.h"

/**
\brief Imprime as zonas que vão ser afetadas pelas "fireballs" do dragão ou as "fireballs" em si
@param e Estado do Jogo
*/
void i_fireballs(ESTADO e);
/**
\brief Imprime as zonas que vão ser afetadas pelo "wingAttack" do dragão ou o "wingAttack" em si
@param e Estado do Jogo
*/
void i_wingAttack(ESTADO e);
/**
\brief Imprime as zonas que vão ser afetadas pelo "fireCone" do dragão ou o "fireCone" em si
@param e Estado do Jogo
*/
void i_fireCone(ESTADO e);
/**
\brief Imprime as zonas que vão ser afetadas pelos ataques do dragão ou os ataques em si
@param e Estado do Jogo
*/
void imprime_boss(ESTADO e);

#endif