#ifndef ___SCORE_H___
#define ___SCORE_H___

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SB_SIZE 	10

typedef struct score{
	char name[50];
	int score;
}SCORE;

/**
\brief Importa a scoreBoard de um ficheiro para um array 
	e devolve o numero de scores lidos
@param scoreBoard Array onde vai ser colocada a scoreBoard lida
@return numero de items lidos
*/
int importScoreBoard(SCORE scoreBoard[]);
/**
\brief Insere o score no array de scores
	e devolve o numero de scores no array
@param score Score a inserir
@param scoreBoard Array onde vai ser inserido
@param num_scores Na scoreBoard
*/
int insertScore(char *name, int score, SCORE scoreBoard[], int num_scores);
/**
\brief Exporta a scoreBoard do array para o ficheiro
@param scoreBoard Array de scores
@param num_scores Número de scores
*/
void exportScoreBoard(SCORE scoreBoard[], int num_scores);
/**
\brief Função mestra que controla a atualização da scoreBoard
@param score Score com que o jogador acabou o jogo
*/
void updateScoreBoard(char *name, int score);

#endif