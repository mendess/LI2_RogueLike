#ifndef ___JOGO_H___
#define ___JOGO_H___

#define TAM           50
#define MAX_MONSTROS  5
#define MAX_PEDRAS    25
#define SIZE          10

#define HP_WARRIOR    100
#define HP_ARCHER     90
#define HP_MAGE       70

#define MP_WARRIOR    50
#define MP_ARCHER     70
#define MP_MAGE     100


#define WOLF_DMG      10
#define WOLF_HP       10
#define WOLF_SCORE    10
#define BAT_DMG       7
#define BAT_HP        10
#define BAT_SCORE     10
#define ARCHER_DMG    8
#define ARCHER_HP     8
#define ARCHER_SCORE  8
#define OGRE_DMG      15
#define OGRE_HP       15
#define OGRE_SCORE    15


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
    POSICAO monstros [MAX_MONSTROS];
    // Posições da pedras
    POSICAO pedras [MAX_PEDRAS];
}ESTADO;

int isOnPath(ESTADO e, POSICAO p, int pathSize, POSICAO path[]);
int pos_ocupada (ESTADO e, POSICAO p);
ESTADO colocar_pedra (ESTADO e, int pathSize, POSICAO path[]);
ESTADO colocar_monstro (ESTADO e);
ESTADO colocar_pedras (ESTADO e, int pathSize, POSICAO path[]);
ESTADO colocar_monstros (ESTADO e);
ESTADO inicializar();
int com_jogador (ESTADO e,POSICAO p);
int com_pedras (ESTADO e, POSICAO p);
int com_monstros (ESTADO e, POSICAO p);
ESTADO ler_estado (char *args);

#endif