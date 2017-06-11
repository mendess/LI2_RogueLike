#ifndef __IA_H__
#define __IA_H__

/**
@file IA.h
Movimentos e ataques dos monstros
*/

#include "../colisions.h"
#include "../levelMaker.h"
#include "../estrutura.h"
#include "IAwolf.h"
#include "IAarcher.h"
#include "IAbat.h"
#include "IAogre.h"
#include "IAdragon.h"


#define WOLF_DMG      10
#define WOLF_HP       10
#define BAT_DMG       7
#define BAT_HP        10
#define ARCHER_DMG    8
#define ARCHER_HP     8
#define OGRE_DMG      15
#define OGRE_HP       15

/**
\brief Verifica se a jogada que será feita pelo monstro 
está dentro dos limites do mapa.
@param p posição para a qual o monstro se moverá
@returns 1 se está dentro do mapa
 */
int inBounds(POSICAO p);
/**
\brief Verifica se não existem outros monstros já a ocupar a posição
para a qual o monstro em questão se pretende mover.
@param e Estado do jogo
@param p posição para a qual o monstro se moverá
@returns 1 se não existir um monstro para onde o monstro em questão
se quer mover
*/
int poslivre(ESTADO e, POSICAO p);
/**
\brief Retira á vida do jogador o dano causado por um ataque de um monstro
tendo em conta a armadura que este tem equipada
@param e Estado do jogo
@param i dano que o monstro causa
@returns estado do jogo depois de o monstro ter tirado vida ao jogador
*/
ESTADO ataca_jogador(ESTADO e,int i);
/**
\brief Verifica se o jogador pode ser atacado.
Serve para morcegos e para lobos.
@param e Estado do jogo
@param p posição atual do monstro 
@returns 1 se o jogador está ao alcance dos monstros
*/
int existe_jogador(ESTADO e,POSICAO p);
/**
\brief Verifica se o jogador pode ser atacado.
Serve exclusivamente para arqueiros.
@param e Estado do jogo
@param p posição do arqueiro.
@returns 1 se o jogador está ao alcance do arqueiro 
*/
int ve_jogador (ESTADO e,POSICAO p);
/**
\brief Quando um morcego não é escolhido para atacar o jogador
está função fa-lo mover-se pseudo-aleatóriamente pelo mapa.
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do morcego em questão
@param p posição do morcego em questão
@returns estado do jogo depois do morcego se ter movido aleatóriamente
*/
ESTADO mov_bat(ESTADO e,int i,POSICAO p);
/**
\brief  Quando não é selecionado para atacar faz com que o arqueiro 
se mova pelo mapa
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do arqueiro em questão
@param p posição do arqueiro em questão
@returns estado do jogo alterado depois do arqueiro se ter movido 
aleatóriamente
*/
ESTADO mov_archer(ESTADO e,int i,POSICAO p);
/**
\brief Quando não é selecionado para atacar faz com que o lobo 
se mova pelo mapa
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do lobo em questão
@param p posição do lobo em questão
@returns estado do jogo alterado depois do lobo se ter movido 
aleatóriamente
*/
ESTADO mov_wolf (ESTADO e,int i,POSICAO p);
/**
\brief Decide se o morcego ataca ou se se mexe pelo mapa
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do morcego em questão
@param p posição do morcego em questão
@returns estado do jogo alterado depois do morcego se ter movido 
aleatóriamente ou atacado o jogador
*/
ESTADO acao_bat(ESTADO e, int i, POSICAO p);
/**
\brief Decide se o lobo ataca ou se se mexe pelo mapa
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do lobo em questão
@param p posição do lobo em questão
@returns estado do jogo alterado depois do lobo se ter movido 
aleatóriamente ou atacado o jogador
*/
ESTADO acao_wolf (ESTADO e,int i, POSICAO p);
/**
\brief Decide se o arqueiro ataca ou se se mexe pelo mapa
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do arqueiro em questão
@param p posição do arqueiro em questão
@returns estado do jogo alterado depois do arqueiro se ter movido 
aleatóriamente ou atacado o jogador
*/
ESTADO acao_archer(ESTADO e, int i, POSICAO p);
/**
\brief Caso o lobo seja escolhido para atacar esta função decide:
 se o lobo ataca o jogador 
 se colabora com outro monstro para bloquear a passagem do jogador
 se persegue o jogador
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do lobo em questão
@param p posição do lobo em questão 
@returns estado do jogo alterado depois do lobo se ter movido 
ou atacado o jogador
*/
ESTADO estrat_wolf(ESTADO e, int i, POSICAO p);
/**
\brief Caso o morcego seja escolhido para atacar esta função decide:
 se o morcego ataca o jogador 
 se colabora com outro monstro para bloquear a passagem do jogador
 se persegue o jogador
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do morcego em questão
@param p posição do morcego em questão 
@returns estado do jogo alterado depois do morcego se ter movido 
ou atacado o jogador
*/
ESTADO estrat_bat(ESTADO e, int i, POSICAO p);
/**
\brief Oogre tem como unica função guardar o cofre que está ao seu lado.
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do ogre em questão
@param p posição do ogre em questão 
@returns estado do jogo alterado depois do ogre se ter movido 
ou atacado o jogador
*/
ESTADO estrat_ogre(ESTADO e, int i, POSICAO p);
/**
\brief Caso o arqueiro seja escolhido para atacar esta função decide:
 se o arqueiro ataca o jogador 
 se colabora com outro monstro para bloquear a passagem do jogador
 se persegue o jogador
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do arqueiro em questão
@param p posição do arqueiro em questão 
@returns estado do jogo alterado depois do arqueiro se ter movido 
ou atacado o jogador
*/
ESTADO estrat_archer(ESTADO e, int i, POSICAO p);
/**
\brief Vê quais os dois monstros que estão mais perto e fa-los cooperar 
para maximizarem o dano feito ao jogador
@param e Estado do jogo
@returns numa posição os indices do dois monstros que vão 
perseguir/atacar o jogador
*/
POSICAO quemAtaca(ESTADO e);
/**
\brief das duas posições devolvidas pela funão quemAtaca esta função verifica
o tipo de monstro e chama a função que coordena a estratégia dos dois monstros.
@param e Estado do jogo
@param i  posição do array onde estão guardadas as coordenadas
do monstro em questão
@returns o estado do jogo depois de terem sido escolhidos os dois monstros
que iriam tentar atacar o jogador e depois de estes terem feito os seus
movimentos
*/
ESTADO iaMoves (ESTADO e,int i);
/**
\brief Coordena as funções de movimento aleatório e as de movimentos estratégicos
dos monstros.
@param e Estado do jogo.
@returns o resultado do movimento aleatório dos monstros e dos dois
que tentam atacar o jogador
*/
ESTADO move_monstros(ESTADO e);

#endif
