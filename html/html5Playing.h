#ifndef __HTML5_H__
#define __HTML5_H__

#include "../colisions.h"
#include "htmlMaster.h"

#include "html5PlayingSpells.h"

#define ARCHER_ACTION_MATRIX	{{-1,-1,28,-1,-1},\
								 {-1,27,-1,29,-1},\
								 {24,-1,-1,-1,26},\
								 {-1,21,-1,23,-1},\
								 {-1,-1,22,-1,-1},}

#define PLAY_FRAMES		{"Moldura_Movimento.png","Moldura_Ataque.png","Moldura_Lesser_Teleport.png","Moldura_PickUp_Item.png"}

#define FEEDBACK_MSGS	{"","Hum... I can't cast that!","I can't carry more items!","There are no targets in range!"}

#define CAN_USE_LESSER_TELEPORT	e.classe==3 && e.turn % 5 == 0 && e.turn != 0 && e.mp>=LESSER_TP_COST

#define LESSER_TP_COST	10

/**
\brief Retorna a direção em que o jogador vai andar

Valores que a função retorna
1- SW	x==-1 ; y==1
2- S	x==0  ; y==1
3- SE	x==1  ; y==1
4- W	x==-1 ; y==0
6- E	x==1  ; y==0
7- NW	x==-1 ; y==-1
8- N	x==0  ; y==-1
9- NE	x==1  ; y==-1
@param e Estado do jogo
@param p Quanto no eixo dos x e dos y o jogador vai andar
*/
int getDirection(ESTADO e,POSICAO p);
/**
\brief Imprime a moldura da jogada
@param p Posição do movimento
*/
void imprime_move_frame (POSICAO p, int moldura);
/**
\brief Imprime o link de uma jogada
@param name Nome do jogador
@param target Posição da jogada
@param new_action Nova ação que representa a jogada
@param moldura Número da imagem que associada à jogada
*/
void imprime_link(char *name, POSICAO target, int new_action, int moldura);
/**
\brief Imprime um movimento para as coordenadas dadas
@param e Estado do jogo
@param p Posição onde criar o movimento
*/
void imprime_move (ESTADO e, POSICAO p);
/**
\brief Imprime um ataque ...
@param e Estado do jogo
@param
*/
void imprime_ranged_attack(ESTADO e,POSICAO p);
/**
\brief Imprime os ataques especiais do arqueiro
@param e Estado do jogo
*/
void imprime_all_ranged_atacks(ESTADO e);
/**
\brief Imprime todas as jogadas possiveis
@param e Estado do jogo
*/
void imprime_all_moves (ESTADO e);
/**
\brief Imprime o jogador
@param e Estado do jogo
*/
void imprime_jogador (ESTADO e);
/**
\brief Imprime as chests
@param e Estado do jogo
*/
void imprime_chests(CHEST chests[], int num_chests);
/**
\brief Imprime os monstros
@param mostros Lista dos mostros
*/
void imprime_monstros (MSTR monstros[], int num_monstros);
/**
\brief Imprime as pedras
@param pedras Lista dos obstaculos
*/
void imprime_pedras (POSICAO pedras[]);
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
\brief Imprime o chao do mapa
*/
void imprime_chao();
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
void imprime_inventory(int mode, char *name, INVT bag);
/**
\brief Função mestra que chama todas as funções
de impressão
@param e Estado do jogo
*/
void imprimePlaying(ESTADO e);

#endif
