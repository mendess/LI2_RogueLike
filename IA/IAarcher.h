#ifndef __ARCHER_H__
#define __ARCHER_H__
#include "IA.h"


#define BLOQUEAVEL_NE	e.jog.y>p.y && e.jog.x<p.x && p.x<e.saida.x && e.saida.y<p.y && e.saida.x>e.jog.x && e.saida.y<e.jog.y
#define BLOQUEAVEL_NO   e.jog.y>p.y && e.jog.x>p.x && e.saida.x<p.x && e.saida.y<p.y && e.saida.x<e.jog.x && e.saida.y<e.jog.y
#define BLOQUEAVEL_SE   e.jog.y<p.y && e.jog.x<p.x && e.saida.x<p.x && e.saida.y>p.y && e.saida.x<e.jog.x && e.saida.y>e.jog.y
#define BLOQUEAVEL_SO   e.jog.y<p.y && e.jog.x>p.x && e.saida.x>p.x && e.saida.y>p.y && e.saida.x>e.jog.x && e.saida.y>e.jog.y

/**
\brief se o jogador estiver a noroeste do arqueiro e o arqueiro não estiver
mais proximo da saida do que o jogador esta função é chamada.
@param e Estado do jogo
@param a[10][10] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
*/
ESTADO persegue_NO(ESTADO e,int a[10][10],int i,POSICAO p);
/**
\brief se o jogador estiver a sudoeste do arqueiro e o arqueiro não estiver
mais proximo da saida do que o jogador esta função é chamada.
@param e Estado do jogo
@param a[10][10] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
*/
ESTADO persegue_SO(ESTADO e,int a[10][10],int i,POSICAO p);
/**
\brief se o jogador estiver a nordeste do arqueiro e o arqueiro não estiver
mais proximo da saida do que o jogador esta função é chamada.
@param e Estado do jogo
@param a[10][10] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
*/
ESTADO persegue_NE(ESTADO e,int a[10][10],int i,POSICAO p);
/**
\brief se o jogador estiver a sudeste do arqueiro e o arqueiro não estiver
mais proximo da saida do que o jogador esta função é chamada.
@param e Estado do jogo
@param a[10][10] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
*/
ESTADO persegue_SE(ESTADO e,int a[10][10],int i,POSICAO p);
/**
\brief Se o arqueiro não se encontrar entre o jogador e a saida vai 
perseguir o jogador.
Esta função coordena as 4 diferentes ocorrencias de perseguição.
@param e Estado do jogo
@param a[10][10] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
*/
ESTADO persegue_arch(ESTADO e,int a[10][10],int i,POSICAO p);
/**
\brief se o jogador estiver a esquerda do arqueiro,este começa por tentar 
fugir para a direita e depois para cima e para baixo.
@param a[10][10] matriz do numero de jogadas para chegar ao jogador
@param e Estado do jogo
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
*/
ESTADO desvia_right(int a[10][10],ESTADO e,int i,POSICAO p);
/**
\brief se o jogador estiver a direita do arqueiro,este começa por tentar 
fugir para a esquerda e depois para cima e para baixo.
@param a[10][10] matriz do numero de jogadas para chegar ao jogador
@param e Estado do jogo
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
*/
ESTADO desvia_left(int a[10][10],ESTADO e,int i,POSICAO p);
/**
\brief se o jogador estiver por cima do arqueiro,este começa por tentar 
fugir para baixo e depois para os lados.
@param a[10][10] matriz do numero de jogadas para chegar ao jogador
@param e Estado do jogo
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
*/
ESTADO desvia_down(int a[10][10],ESTADO e,int i,POSICAO p);
/**
\brief se o jogador estiver por baixo do arqueiro,este começa por tentar 
fugir para cima e depois para os lados.
@param a[10][10] matriz do numero de jogadas para chegar ao jogador
@param e Estado do jogo
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
*/
ESTADO desvia_up(int a[10][10],ESTADO e,int i,POSICAO p);
/**
\brief se o jogador estiver ao lado do arqueiro e poder atacar o arqueiro 
no proximo turno o arqueiro foge dele.
@param e Estado do jogo
@param a[10][10] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
*/
ESTADO desvia(ESTADO e,int a[10][10],int i,POSICAO p);
/**
\brief verifica se o jogador está ao alcance do ataque do arqueiro.
@param e Estado do jogo
@param p posição do monstro
*/
int in_range(ESTADO e,POSICAO p);
/**
\brief esta função coloca o arqueiro a bloquear a passagem do jogador 
caso a saida se encontre a nordeste do jogador e o monstro esteja
entre ambos.
@param e Estado do jogo
@param a[10][10] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
*/
ESTADO defArcher_NO (ESTADO e,int a[10][10], int i, POSICAO p);
/**
\brief esta função coloca o arqueiro a bloquear a passagem do jogador 
caso a saida se encontre a noroeste do jogador e o monstro esteja
entre ambos.
@param e Estado do jogo
@param a[10][10] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
*/
ESTADO defArcher_NE (ESTADO e,int a[10][10], int i, POSICAO p);
/**
\brief esta função coloca o arqueiro a bloquear a passagem do jogador 
caso a saida se encontre a sudoeste do jogador e o monstro esteja
entre ambos.
@param e Estado do jogo
@param a[10][10] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
*/
ESTADO defArcher_SO (ESTADO e,int a[10][10], int i, POSICAO p);
/**
\brief esta função coloca o arqueiro a bloquear a passagem do jogador 
caso a saida se encontre a sudeste do jogador e o monstro esteja
entre ambos.
@param e Estado do jogo
@param a[10][10] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
*/
ESTADO defArcher_SE (ESTADO e,int a[10][10], int i, POSICAO p);
/**
\brief começando no jogador esta função cria um mapa 10 por 10 com cada posição
a representar o numero de jogadas necessarias para chegar ao jogador
a partir dessa posição.
@param e Estado do jogo
@param a[10][10] matriz do numero de jogadas para chegar ao jogador
@param x coordenada x na matriz a
@param y coordenada y na matriz a
@param i contador de jogadas a imprimir em a[x][y]
*/
void distancia_ARCHER (ESTADO e,int a[10][10],int x,int y,int i);
/**
\brief preenche uma matriz a[10][10] com o valor 50
que postriormente será usado para identificar pedras e monstros
*/
void preenche_matriz(int a[10][10]);
/**
\brief decide se o arqueiro tem o jogador ao alcance dos seus ataques e
o jogador não o possa atacar se tal acontecer este foge.
se não estiver ao alcance verifica se o arqueiro está entre o jogador
e a saida e se sim bloqueia-a, ou então persegue o jogador.
@param e Estado do jogo
@param i i  posição do array onde estão guardadas as coordenadas
do arqueiro em questão
@param p posicao atual do arqueiro
*/
ESTADO estrat_archer (ESTADO e,int i,POSICAO p);

#endif