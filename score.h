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

/** \brief Caminho para o ficheiro de scores */
#define SCORE_PATH	"/var/www/html/score/scoreBoard"

/**
\brief Estrutura que armazena os scores
*/
typedef struct score{
	char name[13];
	int score;
	struct score *prox;
}*SCORE;

/**
\brief Adiciona um elemeto á lista ligada de scoreboards
@param scB Lista de scores
@param name Nome do jogador
@param score Score do jogador
*/
void add2List(SCORE *scB, char name[], int score);
/**
\brief Importa a scoreBoard de um ficheiro para uma lista ligada
@param scB Lista onde vai ser colocada a scoreBoard lida
*/
void importScoreBoard(SCORE *scB);
/**
\brief Insere um score ordenadamente na lista de scores
@param scB Lista onde vai ser inserido
@param name Nome do jogador
@param score Score a inserir
*/
void insertOrd (SCORE *scB, char *name, int score);
/**
\brief Exporta a scoreBoard da lista para o ficheiro
@param scB Lista de scores
*/
void exportScoreBoard(SCORE scB);
/**
\brief Liberta a memória alocado pela lista ligada
@param scB ScoreBoard
*/
void freeScB(SCORE scB);
/**
\brief Função mestra que controla a atualização da scoreBoard
@param name Nome do jogador
@param score Score com que o jogador acabou o jogo
*/
void updateScoreBoard(char *name, int score);

#endif