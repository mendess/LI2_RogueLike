#ifndef __ESTRUTURA_H__
#define __ESTRUTURA_H__

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#define TAM				50
#define MAX_MONSTROS	5
#define MAX_PEDRAS		25
#define SIZE          	10
#define LOOT_TABLE_SIZE 4
#define INVT_SIZE       6

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

typedef struct inventory{
	int gold;
	int inv[INVT_SIZE];
	int weapon;
	int armour;
}INVT;

typedef struct itemUsedata{
	int usingItem;
	int itemBeingUsed;
	int lastPickedTarget;
}ITEM_U_DAT;

typedef struct estado{
	/* {Main Menu=0; ScoreBoard=1; Help=2; Character Selection=3; Playing=4; Store=5} */
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
	/* Codigo de feedback da loja */
	int shopFeedback;
	/* Se o jogador esta a usar um item */
	ITEM_U_DAT itemUseData;
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
}ESTADO;

static const ESTADO estadoZero;

#endif