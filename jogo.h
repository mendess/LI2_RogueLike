#ifndef ___JOGO_H___
#define ___JOGO_H___

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#define TAM           50
#define MAX_MONSTROS  5
#define MAX_PEDRAS    25
#define SIZE          10

#define NEW_LEVEL_HP_BONUS  30
#define NEW_LEVEL_MP_BONUS  10
#define NEW_LEVEL_SC_BONUS  60

/*
HelhPotion      0
ManaPotion      1
ScrollFire      2  - Vermelho
ScrollLightning 3  - Amarelo
ScrollTeleport  4  - Azul
SwordBronze     5  - Castanho
SwordIron       6  - Cinzento Escuro
SwordSteel      7  - Cinzento Claro
SwordPalladium  8  - Inventa para ai
ArmourBronze    9  - Castanho
ArmourIron      10 - Cinzento Escuro
ArmourSteel     11 - Cinzento Claro
ArmourPalladium 12 - Inventa para ai
*/

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
    char gold;
    char inv[4];
}INVT;

typedef struct estado{
    //Classe {Warrior=0, Archer=1, Mage=2}
    char classe;
    //Vida do jogador
    char hp;
    //Mana do jogador
    char mp;
    //Nivel
    char world_lvl;
    //Score
    int score;
    //Turno
    char turn;
    //Lado para que o jogador esta a olhar 0:direita e 1:esquerda
    char direction;
    //Action
    char action;
	// Posição do jogador
    POSICAO jog;
    // Posição da saida
    POSICAO saida;
    // Numero de Monstros
    char num_monstros;
    // Numero de pedras
    char num_pedras;
    // Posições dos monstros
    MSTR monstros [MAX_MONSTROS];
    // Posições da pedras
    POSICAO pedras [MAX_PEDRAS];
}ESTADO;

ESTADO inicializar();
ESTADO ler_estado (char *args,FILE *gamestateFile);

#endif
