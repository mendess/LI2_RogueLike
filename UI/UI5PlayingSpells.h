#ifndef __UI_5_SPELLS_H__
#define __UI_5_SPELLS_H__

/**
@file UI5PlayingSpells.h
Definição da interface de uso de items complexos
*/
#include <stdio.h>

#include "../estrutura.h"
#include "../items.h"
#include "UIMacros.h"

/** \brief Cores das molduras de dos feitiços */
#define TARGET_MOLDS		{"red","yellow","green","blue"}
/** \brief Nome da imagem do spell de fogo */
#define FIRE_IMAGE			"Spell_Fire.png"
/** \brief Nome da imagem do feitiço de veneno */
#define POISON_IMAGE		"Spell_Poison.png"
/** \brief Nome da imagem do feitiço de veneno quando jogada no Boss */
#define POISON_IMAGE_BOSS	"Spell_Poison_Dragon.png"

/**
\brief Imprime um quadrado sombreado onde o feitiço vai ter efeito
@param type Tipo de feitiço
@param p Posição do quadrado
*/
void i_cTarget(int type,POSICAO p);
/**
\brief Comverte um par de coordenadas X e Y numa ação no formato 1XXYY
@param p Posição a converter
@returns Ação convertida
*/
int cTgT2Int(POSICAO p);
/**
\brief Verifica se uma posição esta perto do jogador
@param jog Posição do jogador
@param p Posição a verificar
@returns 1 se sim 0 caso contrario
*/
int nearPlayer(POSICAO jog, POSICAO p);

// RED ZONE
/**
\brief Imprime os alvos do feitiço vermelho (fogo)
@param e Apontador para o Estado do Jogo
*/
void i_castTargetsRed(ESTADO *e);
/**
\brief Sombreia as zona onde o feitiço vermelho (fogo) vai ter efeito
@param e Apontador para o Estado do Jogo
*/
void i_confirmCastRed(ESTADO *e);
/**
\brief Imprime o efeito do feitiço vermelho (fogo)
@param e Apontador para o Estado do Jogo
*/
void i_CastRed(ESTADO *e);

// YELLOW ZONE
/**
\brief Imprime os alvos do feitiço amarelo (relampago)
@param e Apontador para o Estado do Jogo
*/
void i_castTargetsYellow(ESTADO *e);
/**
\brief Sombreia as zona onde o feitiço amarelo (relampago) vai ter efeito
@param e Apontador para o Estado do Jogo
*/
void i_confirmCastYellow(ESTADO *e);
/**
\brief Imprime o efeito do feitiço amarelo (relampago)
@param e Apontador para o Estado do Jogo
*/
void i_CastYellow(ESTADO *e);

// BLUE ZONE
/**
\brief Imprime os alvos do feitiço azul (teleport)
@param e Apontador para o Estado do Jogo
*/
void i_castTargetsBlue(ESTADO *e);
/**
\brief Sombreia as zona onde o feitiço azul (teleport) vai ter efeito
@param e Apontador para o Estado do Jogo
*/
void i_confirmCastBlue(ESTADO *e);
/**
\brief Imprime o efeito do feitiço azul (teleport)
@param e Apontador para o Estado do Jogo
*/
void i_CastBlue(ESTADO *e);

// GREEN ZONE
/**
\brief Imprime os alvos do feitiço verde (veneno)
@param e Apontador para o Estado do Jogo
*/
void i_castTargetsGreen(ESTADO *e);
/**
\brief Sombreia as zona onde o feitiço verde (veneno) vai ter efeito
@param e Apontador para o Estado do Jogo
*/
void i_confirmCastGreen(ESTADO *e);
/**
\brief Imprime o efeito do feitiço verde (veneno)
@param e Apontador para o Estado do Jogo
*/
void i_CastGreen(ESTADO *e);

/**
\brief Imprime os alvos do feitiço
@param e Apontador para o Estado do Jogo
*/
void imprime_castTargets(ESTADO *e);
/**
\brief Sombreia as zona onde o feitiço vai ter efeito
@param e Apontador para o Estado do Jogo
*/
void imprime_confirmCast(ESTADO *e);
/**
\brief Imprime o efeito do feitiço
@param e Apontador para o Estado do Jogo
*/
void imprime_castSpell(ESTADO *e);

#endif