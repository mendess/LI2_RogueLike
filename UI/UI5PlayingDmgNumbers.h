#ifndef __UI5_DMGNUM__
#define __UI5_DMGNUM__

#include "../calcularCombate.h"

#include "UI5Playing.h"

/** \brief Macro que imprime o dano causado */
#define DMG_NUM(X,Y,DMG)	printf("<text x=%d y=%d style=\"fill:#000000;stroke:#000000\">-%d</text>\n",((X+1)*TAM)+TAM/2,((Y+1)*TAM)+TAM/5,DMG);

/**
\brief Imprime o dano que o jogador levou
@param jog Posição do jogador
@param dmgTaken Dano que o jogador levou
*/
void i_dmgTaken(POSICAO jog, int dmgTaken);
/**
\brief Imprime o dano que o jogador causou com o feitiço de fogo (vermelho)
@param e Apontador para o Estado do Jogo
*/
void i_dmgDealtSpells_Fire(ESTADO *e);
/**
\brief Imprime o dano que o jogador causou com o feitiço de relampago (amarelo)
@param e Apontador para o Estado do Jogo
*/
void i_dmgDealtSpells_Lightning(ESTADO *e);
/**
\brief Imprime o dano que o jogador causou com o feitiço de veneno (verde)
@param e Apontador para o Estado do Jogo
*/
void i_dmgDealtSpells_Poison(ESTADO *e);
/**
\brief Imprime o dano que o jogador causou com feitiços
@param e Apontador para o Estado do Jogo
*/
void i_dmgDealtSpells(ESTADO *e);
/**
\brief Imprime o dano que o jogador causou com um ataque normal
@param e Apontador para o Estado do Jogo
*/
void i_dmgDealtNormal(ESTADO *e);
/**
\brief Imprime o dano que o jogador levou e causou
@param e Apontador para o Estado do Jogo
*/
void imprime_dmgNum(ESTADO *e);
#endif