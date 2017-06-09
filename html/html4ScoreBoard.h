#ifndef __HTML4_H__
#define __HTML4_H__

/**
@file html4ScoreBoard.h
Definição das funções que imprimem a scoreboard
*/

#include "../score.h"

#include "htmlMaster.h"

/**
\brief Imprime um score num certo indice
@param score Score a imprimir
@param index Indice onde imprimir
*/
void imprime_score(int score, int index);
/**
\brief Imprime a scoreBoard
@param name Nome do jogador
*/
void imprimeScoreBoard(char *name);

#endif
