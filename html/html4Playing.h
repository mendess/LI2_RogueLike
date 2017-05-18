#ifndef __HTML4_H__
#define __HTML4_H__

#include "../colisions.h"

#include "htmlMaster.h"

int getDirection(ESTADO e,POSICAO p);
void imprime_jogador (ESTADO e);
void imprime_jogadaS (ESTADO e);
void criar_jogada (ESTADO e, POSICAO p);
void imprime_jogada (ESTADO e,POSICAO p);
void imprime_monstros (ESTADO e);
void imprime_pedras (ESTADO e);
void imprime_saida (POSICAO p);
void imprime_casa (POSICAO p);
void imprime_background (char classe);
void imprime_hpBar(int hp);
void imprime_mpBar(int mp, char classe);
void imprime_gameOverScreen();
void imprime_inv_slot(char item,int i);
void imprime_equipment(INVT bag);
void imprime_inventory(INVT bag);
void imprimePlaying(ESTADO e);

#endif
