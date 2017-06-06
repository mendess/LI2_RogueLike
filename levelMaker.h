#ifndef ___LEVELMAKER_H___
#define ___LEVELMAKER_H___

#include "estrutura.h"
#include "colisions.h"
#include "path.h"
#include "loot.h"

#define HP_WARRIOR    100
#define HP_ARCHER     90
#define HP_MAGE       70

#define MP_WARRIOR    50
#define MP_ARCHER     70
#define MP_MAGE       100

#define NEW_LEVEL_HP_BONUS  30
#define NEW_LEVEL_MP_BONUS  10
#define NEW_LEVEL_SC_BONUS  60

/**
\brief Coloca uma pedra numa posição aleatoria válida
@param e Estado do jogo
@param pathSize Tamanho do caminho
@param path Caminho a evitar
*/
ESTADO colocar_pedra (ESTADO e, int pathSize, POSICAO path[]);
/**
\brief Coloca um monstro numa posição aleatoria válida
@param e Estado do jogo
*/
ESTADO colocar_monstro (ESTADO e);
/**
\brief Coloca todas as pedras para inicializar o estado
@param e Estado do jogo
@param pathSize Tamanho do caminho a evitar
@param path Array de coordenadas do caminho a evitar
*/
ESTADO colocar_pedras (ESTADO e, int pathSize, POSICAO path[]);
/**
\brief Coloca todas os monstros para inicializar o estado
@param e Estado do jogo
*/
ESTADO colocar_monstros (ESTADO e);
/*
\brief Retorna o hp inicial da classe dada como argumento
@param type O numero da classe
*/
int getClassHp(int type);
/*
\brief Retorna o mp inicial da classe dada como argumento
@param type O numero da classe
*/
int getClassMp(int type);
/**
\brief Inicializa o inventario a vazio
@param bag Inventario
*/
INVT initINVT();
/**
\brief Calcula uma nova posição a partir das coordenadas do jogador e da acao
@param jog A posição antiga do jogador
@param act Ação selecionada
*/
POSICAO calculaNovaPosicao(POSICAO jog, int act);
/**
\brief Calcula o nova posição do jogador depois de usar a abilidade "lesser teleport" do "Mage"
@param jog Posição do jogador
@param act Ação selecionada
@returns Nova posição do jogador
*/
POSICAO calcularLesserTeleport(POSICAO jog, int act);
/**
\brief Inicializa o estado do jogo
*/
ESTADO inicializar(ESTADO e);
/**
\brief Gera um novo nivel quando o jogador chega a saida
@param e Estado do Jogo
*/
ESTADO newLevel();

#endif
