#ifndef __ESTRUTURA_H__
#define __ESTRUTURA_H__

/**
@file estrutura.h
Definição de algumas constantes e das estruturas do jogo
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

/** \brief Tamanho em pixeis de cada quadrado no mapa */
#define TAM					50
/** \brief Número maximo de monstros que um nível pode ter */
#define MAX_MONSTROS		20
/** \brief Número maximo de obstaculos de um nível */
#define MAX_PEDRAS			25
/** \brief Número maximo de chests que um nível pode ter */
#define MAX_CHESTS			3
/** \brief Tamanho do mapa */
#define SIZE          		10
/** \brief Tamanho da tabela de items que se pode obter por nível */
#define LOOT_TABLE_SIZE 	4
/** \brief Tamanho do inventário */
#define INVT_SIZE       	6
/** \brief Número maximo de items que um nível pode ter no chão */
#define MAX_DROPPED_ITEMS	LOOT_TABLE_SIZE+MAX_CHESTS
/** \brief Condições para usar o teleport menor */
#define CAN_USE_LESSER_TELEPORT	e.classe==3 && e.turn % 5 == 0 && e.turn != 0 && e.mp>=LESSER_TP_COST
/** \brief Custo do teleport menor */
#define LESSER_TP_COST	10

/** \brief Estrutura que armazena uma posição */
typedef struct posicao{
	/** Coordenada X */
	int x;
	/** Coordenada Y */
	int y;
}POSICAO;
/** \brief Estrutura que armazena um monstro */
typedef struct monster{
	/** Coordenada X */
	int x;
	/** Coordenada Y */
	int y;
	/** Tipo do monstro */
	int monType;
	/** Vida do monstro */
	int hp;
	/** Poison counter */
	int poison;
}MSTR;

/** \brief Estrutura que armazena o inventário do jogador */
typedef struct inventory{
	/** Dinheiro do jogador */
	int gold;
	/** Lista de items do jogador */
	int inv[INVT_SIZE];
	/** Arma que o jogador tem equipada */
	int weapon;
	/** Armadura que o jogador tem equipada */
	int armour;
}INVT;

/** \brief Estrutura que guarda uma chest */
typedef struct chest{
	/** Posição da chest */
	POSICAO pos;
	/** Item dentro da chest */
	int item;
}CHEST;

/** \brief Estrutura que armazena os dados do uso de items complexos */
typedef struct itemUsedata{
	/** Guarda se o item esta a ser usado */
	int isBeingUsed;
	/** Guarda o tipo do item */
	int type;
	/** Guarda a ultima posição escolhida */
	int lastPickedTarget;
	/** Guarda se o jogador esta a "disparar" o item */
	int isBeingCast;
}ITEM_U_DAT;

/** \brief Estrutura que armazena os dados do dragão */
typedef struct dragao{
	/** Lado do mapa */
	int side;
	/** Guarda qual o proximo ataque {1="fireball";2="wingAttack";3="fireCone"} */
	int attack;
	/** Guarda, se o proximo ataque for "fireball", o número de fireballs */
	int num_fireballs;
	/** Guarda, se o proximo ataque for "fireball", as posições das mesmas */
	POSICAO fireballCenters[16];
	/** Guarda a posição do dragao */
	POSICAO pos;
	/** Guarda a vida do dragão */
	int hp;
	/** Poison counter */
	int poison;
}BOSS;

/** \brief Estrutura que guarda o estado do jogo */
typedef struct estado{
	/** Ecra em que o jogo está {Form=0; Main Menu=1; ScoreBoard=2; Help=3; Character Selection=4; Playing=5; Store=6} */
	int screen;
	/** Classe {Warrior=0, Archer=1, Mage=2} */
	int classe;
	/** Vida do jogador */
	int hp;
	/** Mana do jogador */
	int mp;
	/** Nome do Jogador */
	char name[14];
	/** Nivel */
	int world_lvl;
	/** Score */
	int score;
	/** Turno */
	int turn;
	/** Lado para que o jogador esta a olhar 0:direita e 1:esquerda */
	int direction;
	/** Action */
	int action;
	/**  Items que podem ser adquiridos num certo nivel */
	int lootTable[LOOT_TABLE_SIZE];
	/** Guarda se o jogador esta na loja */
	int isInShop;
	/** Guarda se o jogador esta a apagar items do inventario */
	int isDeletingItems;
	/** Guarda se o jogador esta numa "boss battle" */
	int isInBossBattle;
	/** Guarda se o jogador esta a pedir ajuda ingame */
	int isInIngameHelp;
	/** Codigo de feedback */
	int feedback;
	/** Número de chests */
	int num_chests;
	/** Lista de chests */
	CHEST chests[MAX_CHESTS];
	/** Se o jogador esta a usar um item */
	ITEM_U_DAT complexItem;
	/**  Inventario do jogador */
	INVT bag;
	/**  Posição do jogador */
	POSICAO jog;
	/**  Posição da saida */
	POSICAO saida;
	/**  Numero de Monstros */
	int num_monstros;
	/**  Numero de pedras */
	int num_pedras;
	/**  Posições dos monstros */
	MSTR monstros [MAX_MONSTROS];
	/** Estrutura do boss */
	BOSS dragon;
	/**  Posições da pedras */
	POSICAO pedras [MAX_PEDRAS];
	/** Lista de items no chão */
	CHEST droppedItems[MAX_DROPPED_ITEMS];
}ESTADO;

/** \brief Estado inicializado completamente a 0 */
static const ESTADO estadoZero;

#endif
