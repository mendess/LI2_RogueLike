#ifndef ___JOGO_H___
#define ___JOGO_H___

#define TAM           50
#define MAX_MONSTROS  10
#define MAX_PEDRAS    20
#define SIZE          10

typedef struct posicao{
	char x;
	char y;
}POSICAO;

typedef struct estado {
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