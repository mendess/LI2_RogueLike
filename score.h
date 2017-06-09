#ifndef ___SCORE_H___
#define ___SCORE_H___

/**
@file score.h
Definição das funções que tratam do registo da scoreboard
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/** \brief Tamanho maximo da scoreboard */
#define SB_SIZE 	10

/**
\brief Estrutura que armazena os scores
*/
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
@param name Nome do jogador
@param score Score a inserir
@param scoreBoard Array onde vai ser inserido
@param num_scores Número de scores na score board
@returns O número de scores na score board
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
@param name Nome do jogador
@param score Score com que o jogador acabou o jogo
*/
void updateScoreBoard(char *name, int score);

#endif