#ifndef ___PATH_H___
#define ___PATH_H___

/**
@file path.h
Definição das funções que geram o caminho garantido para a saida
*/
#include "estrutura.h"
/** \brief Tamanha maximo do caminho */
#define MAX_CAMINHO   30

/**
\brief Cria um caminho a ser evitado quando o mapa está a ser gerado 
	   para garantir que há pelo menos um caminho possivel para chegar a saida.
	   Esta função também define a posição inicial do jogador e de saida
@param path Array de posições do caminho a ser evitado
@returns Tamanho final do caminho
*/
int pathMaker(POSICAO path[]);

#endif