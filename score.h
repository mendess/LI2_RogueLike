#ifndef ___SCORE_H___
#define ___SCORE_H___

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SB_SIZE 	10

/**
\brief Importa a scoreBoard de um ficheiro para um array 
	e devolve o numero de scores lidos
@param scoreBoard Array onde vai ser colocada a scoreBoard lida
@return numero de items lidos
*/
int importScoreBoard(int scoreBoard[]);
/**
\brief Insere o score no array de scores
	e devolve o numero de scores no array
@param score Score a inserir
@param scoreBoard Array onde vai ser inserido
@param num_scores Na scoreBoard
*/
int insertScore(int score, int scoreBoard[], int num_scores);
/**
\brief Exporta a scoreBoard do array para o ficheiro
@param scoreBoard Array de scores
@param num_scores Número de scores
*/
void exportScoreBoard(int scoreBoard[], int num_scores);
/**
\brief Função mestra que controla a atualização da scoreBoard
@param score Score com que o jogador acabou o jogo
*/
void updateScoreBoard(int score);

#endif