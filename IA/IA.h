#ifndef __IA_H__
#define __IA_H__

#include "../colisions.h"
#include "../levelMaker.h"
#include "../estrutura.h"
#include "IAwolf.h"
#include "IAarcher.h"
#include "IAbat.h"
#include "IAogre.h"


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
 */
int inBounds(POSICAO p);
/**
\brief Verifica se não existem outros monstros já a ocupar a posição
para a qual o monstro em questão se pretende mover.
@param e Estado do jogo
@param p posição para a qual o monstro se moverá
*/
int poslivre(ESTADO e, POSICAO p);
/**
\brief Retira á vida do jogador o dano causado por um ataque de um monstro
@param e Estado do jogo
@param i dano que o monstro causa
*/
void ataca_jogador(ESTADO e,int i);
/**
\brief Verifica se o jogador pode ser atacado.
Serve para morcegos e para lobos.
@param e Estado do jogo
@param p posição atual do monstro 
*/
int existe_jogador(ESTADO e,POSICAO p);
/**
\brief Verifica se o jogador pode ser atacado.
Serve exclusivamente para arqueiros.
@param e Estado do jogo
@param p posição do arqueiro.
*/
int ve_jogador (ESTADO e,POSICAO p);
/**
\brief Quando um morcego não é escolhido para atacar o jogador
está função fa-lo mover-se pseudo-aleatóriamente pelo mapa.
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do morcego em questão
@param p posição do morcego em questão
*/
ESTADO mov_bat(ESTADO e,int i,POSICAO p);
/**
\brief  Quando não é selecionado para atacar faz com que o arqueiro 
se mova pelo mapa
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do arqueiro em questão
@param p posição do arqueiro em questão
*/
ESTADO mov_archer(ESTADO e,int i,POSICAO p);
/**
\brief Quando não é selecionado para atacar faz com que o lobo 
se mova pelo mapa
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do lobo em questão
@param p posição do lobo em questão
*/
ESTADO mov_wolf (ESTADO e,int i,POSICAO p);
/**
\brief Decide se o morcego ataca ou se se mexe pelo mapa
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do morcego em questão
@param p posição do morcego em questão
*/
ESTADO acao_bat(ESTADO e, int i, POSICAO p);
/**
\brief Decide se o lobo ataca ou se se mexe pelo mapa
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do lobo em questão
@param p posição do lobo em questão
*/
ESTADO acao_wolf (ESTADO e,int i, POSICAO p);
/**
\brief Decide se o arqueiro ataca ou se se mexe pelo mapa
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do arqueiro em questão
@param p posição do arqueiro em questão
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
*/
ESTADO estrat_bat(ESTADO e, int i, POSICAO p);
/**
\brief Oogre tem como unica função guardar o cofre que está ao seu lado.
@param e Estado do jogo
@param i posição do array onde estão guardadas as coordenadas
do ogre em questão
@param p posição do ogre em questão 
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
*/
ESTADO estrat_archer(ESTADO e, int i, POSICAO p);
/**
\brief Vê quais os dois monstros que estão mais perto e fa-los cooperar 
para maximizarem o dano feito ao jogador
@param e Estado do jogo
*/
POSICAO quemAtaca(ESTADO e);
/**
\brief das duas posições devolvidas pela funão quemAtaca esta função verifica
o tipo de monstro e chama a função que coordena a estratégia dos dois monstros.
@param e Estado do jogo
@param i  posição do array onde estão guardadas as coordenadas
do monstro em questão
*/
ESTADO iaMoves (ESTADO e,int i);
/**
\brief Coordena as funções de movimento aleatório e as de movimentos estratégicos
dos monstros.
@param e Estado do jogo.
*/
ESTADO move_monstros(ESTADO e);

#endif
