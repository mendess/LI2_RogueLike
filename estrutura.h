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
	char x;
	char y;
}POSICAO;

typedef struct monster{
	char x;
	char y;
	char monType;
	char hp;
}MSTR;

typedef struct inventory{
	int gold;
	char inv[INVT_SIZE];
	char weapon;
	char armour;
}INVT;

typedef struct estado{
	/* {Main Menu=0; ScoreBoard=1; Help=2; Character Selection=3; Playing=4; Store=5} */
	char screen;
	/* Classe {Warrior=0, Archer=1, Mage=2} */
	char classe;
	/* Vida do jogador */
	int hp;
	/* Mana do jogador */
	int mp;
	/* Nivel */
	char world_lvl;
	/* Score */
	int score;
	/* Turno */
	char turn;
	/* Lado para que o jogador esta a olhar 0:direita e 1:esquerda */
	char direction;
	/* Action */
	int action;
	/*  Items que podem ser adquiridos num certo nivel */
	char lootTable[LOOT_TABLE_SIZE];
	/* Guarda se o jogador esta na loja */
	char isInShop;
	/* Codigo de feedback da loja */
	char shopFeedback;
	/*  Inventario do jogador */
	INVT bag;
	/*  Posição do jogador */
	POSICAO jog;
	/*  Posição da saida */
	POSICAO saida;
	/*  Numero de Monstros */
	char num_monstros;
	/*  Numero de pedras */
	char num_pedras;
	/*  Posições dos monstros */
	MSTR monstros [MAX_MONSTROS];
	/*  Posições da pedras */
	POSICAO pedras [MAX_PEDRAS];
}ESTADO;

static const ESTADO estadoZero;

#endif