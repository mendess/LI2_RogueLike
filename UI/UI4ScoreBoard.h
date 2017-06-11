#ifndef __UI4_H__
#define __UI4_H__

/**
@file UI4ScoreBoard.h
Definição das funções que imprimem a scoreboard
*/

#include <stdio.h>

#include "../score.h"
#include "UIMacros.h"

/**
\brief Imprime um score num certo indice
@param score Score a imprimir
@param index Indice onde imprimir
*/
void imprime_score(int score, int index);
/**
\brief Imprime o nome do jogador num certo indice
@param name Nome do jogador
@param index Indice onde imprimir
*/
void imprime_name(char name[], int index);
/**
\brief Imprime o lugar em que o score está
@param place Lugar em que está
@param index Indice de onde no ecra está
*/
void imprime_place(int place, int index);
/**
\brief Imprime a scoreboard normal. Top 10 de sempre
*/
void i_scoreBoardNormal();
/**
\brief Imprime a scoreboard filtrada para ter só os scores do jogador que está agora a jogar.
@param name Nome do jogador
*/
void i_scoreBoardFiltered(char *name);
/**
\brief Imprime a scoreBoard
@param name Nome do jogador
@param filtered Se é para imprimir a scoreboard filtrada
*/
void imprimeScoreBoard(char *name, int filtered);

#endif
