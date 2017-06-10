#ifndef __ESTRUTURA_H__
#define __ESTRUTURA_H__

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#define TAM					50
#define MAX_MONSTROS		5
#define MAX_PEDRAS			25
#define MAX_CHESTS			3
#define SIZE          		10
#define LOOT_TABLE_SIZE 	4
#define INVT_SIZE       	6
#define MAX_DROPPED_ITEMS	LOOT_TABLE_SIZE+INVT_SIZE+2


typedef struct posicao{
	int x;
	int y;
}POSICAO;

typedef struct monster{
	int x;
	int y;
	int monType;
	int hp;
}MSTR;

typedef struct dragon{
	int fireball;
	int wingAttack;
	int fireCone;
	int num_fireballs;
	POSICAO fireballCenters[4];
	POSICAO pos;
	int hp;
}DRAGON;
typedef struct inventory{
	int gold;
	int inv[INVT_SIZE];
	int weapon;
	int armour;
}INVT;

typedef struct chest{
	POSICAO pos;
	int item;
}CHEST;

typedef struct itemUsedata{
	int isBeingUsed;
	int type;
	int lastPickedTarget;
	int isBeingCast;
}ITEM_U_DAT;

typedef struct estado{
	/* {Form=0; Main Menu=1; ScoreBoard=2; Help=3; Character Selection=4; Playing=5; Store=6} */
	int screen;
	/* Classe {Warrior=0, Archer=1, Mage=2} */
	int classe;
	/* Vida do jogador */
	int hp;
	/* Mana do jogador */
	int mp;
	/* Nome do Jogador */
	char name[100];
	/* Nivel */
	int world_lvl;
	/* Score */
	int score;
	/* Turno */
	int turn;
	/* Lado para que o jogador esta a olhar 0:direita e 1:esquerda */
	int direction;
	/* Action */
	int action;
	/*  Items que podem ser adquiridos num certo nivel */
	int lootTable[LOOT_TABLE_SIZE];
	/* Guarda se o jogador esta na loja */
	int isInShop;
	/* Guarda se o jogador esta a apagar items do inventario */
	int isDeletingItems;
	/* Guarda se o jogador esta numa "boss battle" */
	int isInBossBattle;
	/* Guarda se o jogador esta a pedir ajuda ingame */
	int isInIngameHelp;
	/* Codigo de feedback */
	int feedback;
	/* Número de chests */
	int num_chests;
	/* Lista de chests */
	CHEST chests[MAX_CHESTS];
	/* Se o jogador esta a usar um item */
	ITEM_U_DAT complexItem;
	/*  Inventario do jogador */
	INVT bag;
	/*  Posição do jogador */
	POSICAO jog;
	/*  Posição da saida */
	POSICAO saida;
	/*  Numero de Monstros */
	int num_monstros;
	/*  Numero de pedras */
	int num_pedras;
	/*  Posições dos monstros */
	MSTR monstros [MAX_MONSTROS];
	/*  Posições da pedras */
	POSICAO pedras [MAX_PEDRAS];
	/* Lista de items no chão */
	CHEST droppedItems[MAX_DROPPED_ITEMS];
}ESTADO;

static const ESTADO estadoZero;

#endif
