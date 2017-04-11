#ifndef __MVMON_H__
#define __MVMON_H__

#include "jogo.h"

#define WOLF_DMG      10
#define WOLF_HP       10
#define BAT_DMG       7
#define BAT_HP        10
#define ARCHER_DMG    8
#define ARCHER_HP     8
#define OGRE_DMG      15
#define OGRE_HP       15


int posocupada3(ESTADO e,POSICAO p);
void ataca_jogador(ESTADO e,int i);
int existe_jogador(ESTADO e,POSICAO p);
int blocked0 (ESTADO e, POSICAO p);
int blocked1 (ESTADO e, POSICAO p);
int ve_jogador (ESTADO e,POSICAO p);
int mov_bat(ESTADO e,int i,POSICAO p);
int mov_ogre(ESTADO e,int i,POSICAO p);
int mov_archer(ESTADO e,int i,POSICAO p);
int mov_wolf (ESTADO e,int i,POSICAO p);
ESTADO move_monstros(ESTADO e);

#endif
