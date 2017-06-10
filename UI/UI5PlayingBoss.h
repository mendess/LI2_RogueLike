#ifndef __UI5_BOSS__
#define __UI5_BOSS__

/**
@file UI5PlayingBoss.h
Definição das funções que imprimem os ataques do dragão
*/

#include "UI5Playing.h"
int getDragonImg(int turn);
/**
\brief Imprime as zonas que vão ser afetadas pelas "fireballs" do dragão ou as "fireballs" em si
@param e Estado do Jogo
*/
void i_fireballs(ESTADO e);
void i_shadow(int side);
/**
\brief Imprime as zonas que vão ser afetadas pelo "wingAttack" do dragão ou o "wingAttack" em si
@param e Estado do Jogo
*/
void i_wingAttack0(ESTADO e);
/**
\brief Imprime as zonas que vão ser afetadas pelo "fireCone" do dragão ou o "fireCone" em si
@param e Estado do Jogo
*/
void i_fireCone0(ESTADO e);
/**
\brief Imprime as zonas que vão ser afetadas pelos ataques do dragão ou os ataques em si
@param e Estado do Jogo
*/
void imprime_boss0(ESTADO e);
void i_wingAttack1(ESTADO e);
void i_fireCone1(ESTADO e);
void imprime_boss1(ESTADO e);
#endif