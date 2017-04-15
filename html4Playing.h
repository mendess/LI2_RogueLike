#ifndef __HTML4_H__
#define __HTML4_H__ 

#include "htmlMaster.h"
#include "jogo.h"

int getDirection(ESTADO e,POSICAO p);
void imprime_jogador (ESTADO e);
void imprime_jogadaS (ESTADO e);
void criar_jogada (ESTADO e, POSICAO p);
void imprime_jogada (ESTADO e,POSICAO p);
void imprime_monstros (ESTADO e);
void imprime_pedras (ESTADO e);
void imprime_saida (POSICAO p);
void imprime_casa (POSICAO p);
void imprime_background ();
void imprime_hpBar(int mp);
void imprime_mpBar(int mp);
void imprime_gameOverScreen();
void imprimePlaying(ESTADO e);

#endif