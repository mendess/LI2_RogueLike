#ifndef __HTML5_H__
#define __HTML5_H__

#include "htmlMaster.h"
#include "../colisions.h"

#include "html5PlayingSpells.h"

/**
\brief Retorna a direção em que o jogador vai andar
1- SW	x==-1 ; y==1
2- S	x==0  ; y==1
3- SE	x==1  ; y==1
4- W	x==-1 ; y==0
5- --	(saida, esta função nunca deve retornar este valor)
6- E	x==1  ; y==0
7- NW	x==-1 ; y==-1
8- N	x==0  ; y==-1
9- NE	x==1  ; y==-1
@param x Quanto no eixo dos x o jogador vai andar
@param y Quanto no eixo dos x o jogador vai andar
*/
int getDirection(ESTADO e,POSICAO p);
/**
\brief Imprime um movimento (link)
@param p Posição a verficar
*/
void imprime_jogador (ESTADO e);
/**
\brief Cria um movimento para as coordenadas dadas
@param e Estado do jogo
@param p Posição onde criar o movimento
*/
void imprime_jogadaS (ESTADO e);
/**
\brief Imprime as jogadas possiveis
@param e Estado do jogo
*/
void criar_jogada (ESTADO e, POSICAO p);
/**
\brief Imprime o jogador
@param e Estado do jogo
*/
void imprime_jogada (ESTADO e,POSICAO p);
/**
\brief Imprime os monstros
@param e Estado do jogo
*/
void imprime_monstros (ESTADO e);
/**
\brief Imprime as pedras
@param e Estado do jogo
*/
void imprime_pedras (ESTADO e);
/**
\brief Imprime a saida
@param p Posição da saida
*/
void imprime_saida (POSICAO p);
/**
\brief Imprime uma casa
@param p Posição a imprimir
*/
void imprime_casa (POSICAO p);
/**
\brief Imprime a imagem de fundo
@param classe Classe do jogador
*/
void imprime_background (int classe);
/**
\brief Imprime a barra que indica a vida do jogador
@param hp Vida
*/
void imprime_hpBar(int hp);
/**
\brief Imprime a barra que indica a mana do jogador
@param mp Mana
*/
void imprime_mpBar(int mp, int classe);
/**
\brief Imprime o Ecra de fim jogo
*/
void imprime_gameOverScreen(char *name);
/**
\brief Imprime um item do inventario
@param item Item a ser impresso
@param i Indice de posição do item
*/
void imprime_inv_slot(char *name, int item,int i);
/**
\brief Imprime o equipamento do jogador
@param bag Inventario do jogador
*/
void imprime_equipment(INVT bag);
/**
\brief Imprime o inventario do jogador
@param bag Inventario do jogador
*/
void imprime_inventory(char *name, INVT bag);
/**
\brief Função mestra que chama todas as funções
de impressão
@param e Estado do jogo
*/
void imprimePlaying(ESTADO e);

#endif
