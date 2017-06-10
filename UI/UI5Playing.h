#ifndef __UI5_H__
#define __UI5_H__

/**
@file UI5Playing.h
Definição das funções que imprimem a interface do jogo
*/
#include "../colisions.h"
#include "UIMaster.h"

#include "UI5PlayingSpells.h"
#include "UI5PlayingTips.h"
#include "UI5PlayingBoss.h"

/** \brief Matriz de ações das ações dos ataques à distancia */
#define RANGED_ACTION_MATRIX	{{-1,-1,28,-1,-1},\
								 {-1,27,-1,29,-1},\
								 {24,-1,-1,-1,26},\
								 {-1,21,-1,23,-1},\
								 {-1,-1,22,-1,-1},}
/** \brief Lista dos nomes do ficheiro das molduras de jogada */
#define PLAY_FRAMES		{"Moldura_Movimento.png","Moldura_Ataque.png","Moldura_Lesser_Teleport.png","Moldura_PickUp_Item.png","Moldura_OpenChest.png"}
/** \brief Lista das mensagens de erro para quando o jogador tenta fazer algo que não pode */
#define FEEDBACK_MSGS	{"","Hum... I can't cast that!","Bad idea...\nDrinking that\nwould make me sick","I can't carry\nmore items!","There are no\ntargets in range!"}
/** \brief Condições para usar o teleport menor */
#define CAN_USE_LESSER_TELEPORT	e.classe==3 && e.turn % 5 == 0 && e.turn != 0 && e.mp>=LESSER_TP_COST
/** \brief Ações para pedir ajuda sobre um item do inventário */
#define ACT_HELP_ITEM	e.action>39 && e.action<46
/** \brief Ação para pedir ajuda sobre a arma equipada */
#define ACT_HELP_SWORD	e.action==46
/** \brief Ação para pedir ajuda sobre a armadura equipada */
#define ACT_HELP_ARMOUR	e.action==47
/** \brief Ações para pedir ajuda sobre um inimigo */
#define ACT_HELP_MSTR	e.action>9999

/**
\brief Retorna a direção em que o jogador vai andar

Valores que a função retorna
1- SW	x==-1 ; y==1
2- S	x==0  ; y==1
3- SE	x==1  ; y==1
4- W	x==-1 ; y==0
5- C	x==0  ; y==0
6- E	x==1  ; y==0
7- NW	x==-1 ; y==-1
8- N	x==0  ; y==-1
9- NE	x==1  ; y==-1
@param e Estado do jogo
@param p Quanto no eixo dos x e dos y o jogador vai andar
*/
int getDirection(ESTADO e,POSICAO p);
/**
\brief Imprime texto no ecra
@param x Coordenada x onde deve começar o texto
@param y Coordenada y onde deve começar o texto
@param text String de texto a imprimir
@param fontSize Tamanho em pixels da letra
*/
void imprime_texto(int x, int y, char *text, int fontSize);
/**
\brief Imprime a moldura da jogada
@param p Posição da moldura
@param moldura Número da moldura
*/
void imprime_move_frame (POSICAO p, int moldura);
/**
\brief Imprime o link de uma jogada
@param name Nome do jogador
@param target Posição da jogada
@param new_action Nova ação que representa a jogada
@param moldura Número da imagem que associada à moldura
*/
void imprime_link(char *name, POSICAO target, int new_action, int moldura);
/**
\brief Imprime um movimento para as coordenadas dadas
@param e Estado do jogo
@param p Diferencial posição onde criar o movimento relativo ao jogador
*/
void imprime_move (ESTADO e, POSICAO dif);
/**
\brief Imprime um ataque à distância
@param e Estado do jogo
@param dif Diferencial posição do ataque à distancia relativo ao jogador
*/
void imprime_ranged_attack(ESTADO e,POSICAO dif);
/**
\brief Imprime os ataques à distância
@param e Estado do jogo
*/
void imprime_all_ranged_attacks(ESTADO e);
/**
\brief Imprime todas as jogadas possiveis
@param e Estado do jogo
*/
void imprime_all_moves (ESTADO e);
/**
\brief Imprime o jogador e as suas jogadas possiveis
@param e Estado do jogo
*/
void imprime_jogador (ESTADO e);
/**
\brief Imprime os items no chão
@param droppedItems Lista dos items no chão
*/
void imprime_droppedItems(CHEST droppedItems[]);
/**
\brief Imprime as chests
@param chests Lista de chests
@param num_chests Número de chests
*/
void imprime_chests(CHEST chests[], int num_chests);
/**
\brief Imprime os monstros
@param jog Posição do jogador
@param mostros Lista dos mostros
@param num_monstros Número de monstros
*/
void imprime_monstros (POSICAO jog, MSTR monstros[], int num_monstros);
/**
\brief Imprime as pedras
@param pedras Lista dos obstaculos
*/
void imprime_pedras (POSICAO pedras[], int num_pedras);
/**
\brief Imprime a saida
@param p Posição da saida
*/
void imprime_saida (POSICAO p);
/**
\brief Imprime um quadrado do chão
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
@param classe Classe do jogador
*/
void imprime_hpBar(int hp);
/**
\brief Imprime a barra que indica a mana do jogador
@param mp Mana
@param classe Classe do jogador
*/
void imprime_mpBar(int mp, int classe);
/**
\brief Imprime o Ecra de fim jogo
@param name Nome do jogador
*/
void imprime_gameOverScreen(char *name);
/**
\brief Imprime um item do inventario
@param name Nome do jogador
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
@param mode Se está no modo de apagar items (1) ou não (0)
@param name Nome do jogador
@param bag Inventario do jogador
*/
void imprime_inventory(int mode, char *name, INVT bag);
/**
\brief Imprime as mensagens de erro para o jogador ver porque é que o que ele quer fazer não é possivel
@param feedback Número da mensagem a apresentar
*/
void imprime_feedback(int feedback);
/**
\brief Imprime os botões para apresentar as ajudas ao jogador
@param e Estado do jogo
*/
void imprime_ingameHelp(ESTADO e);
/**
\brief Função mestra que chama todas as funções que imprimem a interface do jogo
@param e Estado do jogo
*/
void imprimePlaying(ESTADO e);

#endif
