#ifndef __ARCHER_H__
#define __ARCHER_H__
#include "IA.h"
/**
@file IAarcher.h
Movimentos e ataques do arquero
*/
/**
Verifica seo arqueiro está entre o jogador e a saida e se a saida está nordeste do jogador
*/
#define BLOQUEAVEL_NE	e.jog.y>p.y && e.jog.x<p.x && p.x<e.saida.x && e.saida.y<p.y && e.saida.x>e.jog.x && e.saida.y<e.jog.y
/**
Verifica seo arqueiro está entre o jogador e a saida e se a saida está noroeste do jogador
*/
#define BLOQUEAVEL_NO   e.jog.y>p.y && e.jog.x>p.x && e.saida.x<p.x && e.saida.y<p.y && e.saida.x<e.jog.x && e.saida.y<e.jog.y
/**
Verifica seo arqueiro está entre o jogador e a saida e se a saida está sudeste do jogador
*/
#define BLOQUEAVEL_SE   e.jog.y<p.y && e.jog.x<p.x && e.saida.x<p.x && e.saida.y>p.y && e.saida.x<e.jog.x && e.saida.y>e.jog.y
/**
Verifica seo arqueiro está entre o jogador e a saida e se a saida está sudoeste do jogador
*/
#define BLOQUEAVEL_SO   e.jog.y<p.y && e.jog.x>p.x && e.saida.x>p.x && e.saida.y>p.y && e.saida.x>e.jog.x && e.saida.y>e.jog.y

/**
\brief se o jogador estiver a noroeste do arqueiro e o arqueiro não estiver
mais proximo da saida do que o jogador esta função é chamada.
@param e Estado do jogo
@param a[SIZE][SIZE] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
@returns estado do jogo depois do arqueiro se ter movido
*/
ESTADO persegue_NO(ESTADO e,int a[SIZE][SIZE],int i,POSICAO p);
/**
\brief se o jogador estiver a sudoeste do arqueiro e o arqueiro não estiver
mais proximo da saida do que o jogador esta função é chamada.
@param e Estado do jogo
@param a[SIZE][SIZE] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
@returns estado do jogo depois do arqueiro se ter movido
*/
ESTADO persegue_SO(ESTADO e,int a[SIZE][SIZE],int i,POSICAO p);
/**
\brief se o jogador estiver a nordeste do arqueiro e o arqueiro não estiver
mais proximo da saida do que o jogador esta função é chamada.
@param e Estado do jogo
@param a[SIZE][SIZE] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
@returns estado do jogo depois do arqueiro se ter movido
*/
ESTADO persegue_NE(ESTADO e,int a[SIZE][SIZE],int i,POSICAO p);
/**
\brief se o jogador estiver a sudeste do arqueiro e o arqueiro não estiver
mais proximo da saida do que o jogador esta função é chamada.
@param e Estado do jogo
@param a[SIZE][SIZE] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
@returns estado do jogo depois do arqueiro se ter movido
*/
ESTADO persegue_SE(ESTADO e,int a[SIZE][SIZE],int i,POSICAO p);
/**
\brief Se o arqueiro não se encontrar entre o jogador e a saida vai 
perseguir o jogador.
Esta função coordena as 4 diferentes ocorrencias de perseguição.
@param e Estado do jogo
@param a[SIZE][SIZE] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
@returns estado do jogo depois do arqueiro se ter movido
*/
ESTADO persegue_arch(ESTADO e,int a[SIZE][SIZE],int i,POSICAO p);
/**
\brief se o jogador estiver a esquerda do arqueiro,este começa por tentar 
fugir para a direita e depois para cima e para baixo.
@param a[SIZE][SIZE] matriz do numero de jogadas para chegar ao jogador
@param e Estado do jogo
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
*/
ESTADO desvia_right(int a[SIZE][SIZE],ESTADO e,int i,POSICAO p);
/**
\brief se o jogador estiver a direita do arqueiro,este começa por tentar 
fugir para a esquerda e depois para cima e para baixo.
@param a[SIZE][SIZE] matriz do numero de jogadas para chegar ao jogador
@param e Estado do jogo
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
@returns estado do jogo depois do arqueiro se ter desviado do jogador
*/
ESTADO desvia_left(int a[SIZE][SIZE],ESTADO e,int i,POSICAO p);
/**
\brief se o jogador estiver por cima do arqueiro,este começa por tentar 
fugir para baixo e depois para os lados.
@param a[SIZE][SIZE] matriz do numero de jogadas para chegar ao jogador
@param e Estado do jogo
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
@returns estado do jogo depois do arqueiro se ter desviado do jogador
*/
ESTADO desvia_down(int a[SIZE][SIZE],ESTADO e,int i,POSICAO p);
/**
\brief se o jogador estiver por baixo do arqueiro,este começa por tentar 
fugir para cima e depois para os lados.
@param a[SIZE][SIZE] matriz do numero de jogadas para chegar ao jogador
@param e Estado do jogo
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
@returns estado do jogo depois do arqueiro se ter desviado do jogador
*/
ESTADO desvia_up(int a[SIZE][SIZE],ESTADO e,int i,POSICAO p);
/**
\brief se o jogador estiver ao lado do arqueiro e poder atacar o arqueiro 
no proximo turno o arqueiro foge dele.
@param e Estado do jogo
@param a[SIZE][SIZE] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
@returns estado do jogo depois do arqueiro se ter desviado do jogador
*/
ESTADO desvia(ESTADO e,int a[SIZE][SIZE],int i,POSICAO p);
/**
\brief verifica se o jogador está ao alcance do ataque do arqueiro.
@param e Estado do jogo
@param p posição do monstro
@returns 1 se o jogador estiver ao alcance do arqueiro
*/
int in_range(ESTADO e,POSICAO p);
/**
\brief esta função coloca o arqueiro a bloquear a passagem do jogador 
caso a saida se encontre a nordeste do jogador e o monstro esteja
entre ambos.
@param e Estado do jogo
@param a[SIZE][SIZE] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
@returns estado do jogo depois do arqueiro se ter movido
*/
ESTADO defArcher_NO (ESTADO e,int a[SIZE][SIZE], int i, POSICAO p);
/**
\brief esta função coloca o arqueiro a bloquear a passagem do jogador 
caso a saida se encontre a noroeste do jogador e o monstro esteja
entre ambos.
@param e Estado do jogo
@param a[SIZE][SIZE] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
@returns estado do jogo depois do arqueiro se ter movido
*/
ESTADO defArcher_NE (ESTADO e,int a[SIZE][SIZE], int i, POSICAO p);
/**
\brief esta função coloca o arqueiro a bloquear a passagem do jogador 
caso a saida se encontre a sudoeste do jogador e o monstro esteja
entre ambos.
@param e Estado do jogo
@param a[SIZE][SIZE] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
@returns estado do jogo depois do arqueiro se ter movido
*/
ESTADO defArcher_SO (ESTADO e,int a[SIZE][SIZE], int i, POSICAO p);
/**
\brief esta função coloca o arqueiro a bloquear a passagem do jogador 
caso a saida se encontre a sudeste do jogador e o monstro esteja
entre ambos.
@param e Estado do jogo
@param a[SIZE][SIZE] matriz do numero de jogadas para chegar ao jogador
@param i posição do arqueiro no array dos monstros
@param p posição atual do arqueiro
@returns estado do jogo depois do arqueiro se ter movido
*/
ESTADO defArcher_SE (ESTADO e,int a[SIZE][SIZE], int i, POSICAO p);
/**
\brief começando no jogador esta função cria um mapa 10 por 10 com cada posição
a representar o numero de jogadas necessarias para chegar ao jogador
a partir dessa posição.
@param e Estado do jogo
@param a[SIZE][SIZE] matriz do numero de jogadas para chegar ao jogador
@param x coordenada x na matriz a
@param y coordenada y na matriz a
@param i contador de jogadas a imprimir em a[x][y]
*/
void distancia_ARCHER (ESTADO e,int a[SIZE][SIZE],int x,int y,int i);
/**
\brief preenche uma matriz a[SIZE][SIZE] com o valor 50
que postriormente será usado para identificar pedras e monstros
*/
void preenche_matriz(int a[SIZE][SIZE]);
/**
\brief decide se o arqueiro tem o jogador ao alcance dos seus ataques e
o jogador não o possa atacar se tal acontecer este foge.
se não estiver ao alcance verifica se o arqueiro está entre o jogador
e a saida e se sim bloqueia-a, ou então persegue o jogador.
@param e Estado do jogo
@param i i  posição do array onde estão guardadas as coordenadas
do arqueiro em questão
@param p posicao atual do arqueiro
@returns estado do jogo depois do arqueiro se ter movido, 
desviado do jogador ou atacado o jogador.
*/
ESTADO estrat_archer (ESTADO e,int i,POSICAO p);

#endif