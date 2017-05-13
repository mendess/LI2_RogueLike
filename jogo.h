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

#define HEALTH_POTION       1
#define MANA_POTION         2
#define SCROLL_FIRE         3
#define SCROLL_LIGHTNING    4
#define SCROLL_TELEPORT     5
#define SWORD_BRONZE        10
#define SWORD_IRON          11
#define SWORD_STEEL         12
#define SWORD_PALLADIUM     13
#define ARMOUR_BRONZE       14
#define ARMOUR_IRON         15
#define ARMOUR_STEEL        16
#define ARMOUR_PALLADIUM    17

#define LOOT_TABLE_SIZE     4

#define INVT_SIZE           6

/*
--gold
GoldCoins
--potion
HealthPotion    1
ManaPotion      2
--scroll
ScrollFire      3  - Vermelho
ScrollLightning 4  - Amarelo
ScrollTeleport  5  - Azul
ScrollHealing   6  - Pink
--weapon
SwordBronze     10 - Castanho
SwordIron       11 - Cinzento Escuro
SwordSteel      12 - Cinzento Claro
SwordPalladium  13 - Inventa para ai
--armour
ArmourBronze    14 - Castanho
ArmourIron      15 - Cinzento Escuro
ArmourSteel     16 - Cinzento Claro
ArmourPalladium 17 - Inventa para ai
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
    int gold;
    char inv[INVT_SIZE];
    char weapon;
    char armour;
}INVT;

typedef struct estado{
    //{Main Menu=0; ScoreBoard=1; Help=2; Character Selection=3; Playing=4; Store=5}
    char screen;
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
    int action;
    // Items que podem ser adquiridos num certo nivel
    char lootTable[LOOT_TABLE_SIZE];
    //Guarda se o jogador esta na loja
    char isInShop;
    //Codigo de feedback da loja
    char shopFeedback;
    // Inventario do jogador
    INVT bag;
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

ESTADO inicializar(char classe);
ESTADO newLevel();
POSICAO calculaNovaPosicao(POSICAO jog, int act);
ESTADO calcularNovaEstado(ESTADO e);
ESTADO ler_estado (char *args,FILE *gamestateFile);
ESTADO runGame();

#endif