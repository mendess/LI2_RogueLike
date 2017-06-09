#ifndef ___JOGO_H___
#define ___JOGO_H___

/**
@file jogo.h
Define as funções principais do jogo. As que controlam e todo o estado.
*/

//#define BOSS

#include "estrutura.h"
#include "actionMap.h"
#include "antiCheat.h"
#include "levelMaker.h"
#include "calcularCombate.h"
#include "move_monst.h"
#include "shop.h"
#include "score.h"
#include "items.h"
#include "html/htmlMaster.h"

/** \brief Caminho para os ficheiros de jogador */
#define FILEPATH	"/var/www/html/files/"

/**
\brief Calcula um novo estado conforme a ação que esteja no estado que recebe
@param e Estado do jogo
@returns Estado do jogo alterado
*/
ESTADO calcularNovaEstado(ESTADO e);
/**
\brief Lê o estado de um ficheiro e ação da QUERY_STRING
@param args QUERY_STRING
@returns Estado do jogo lido
*/
ESTADO ler_estado (char *args);
/**
\brief Escreve o estado no ficheiro
@param e Estado do jogo
*/
void escrever_estado(ESTADO e);
/**
\brief Corre o jogo.

lê do ficheiro
Calcula o novo estado
Escreve no ficheiro
@returns Estado do jogo
*/
ESTADO runGame();

#endif