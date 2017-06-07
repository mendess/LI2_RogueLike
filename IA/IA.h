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

int inBounds(POSICAO p);
int poslivre(ESTADO e, POSICAO p);
void ataca_jogador(ESTADO e,int i);
int existe_jogador(ESTADO e,POSICAO p);
/*int blocked0 (ESTADO e, POSICAO p);
int blocked1 (ESTADO e, POSICAO p);*/
int ve_jogador (ESTADO e,POSICAO p);
ESTADO mov_bat(ESTADO e,int i,POSICAO p);
ESTADO mov_ogre(ESTADO e,int i,POSICAO p);
ESTADO mov_archer(ESTADO e,int i,POSICAO p);
ESTADO mov_wolf (ESTADO e,int i,POSICAO p);
ESTADO acao_bat(ESTADO e, int i, POSICAO p);
ESTADO acao_wolf (ESTADO e,int i, POSICAO p);
ESTADO acao_ogre(ESTADO e,int i,POSICAO p);
ESTADO acao_archer(ESTADO e, int i, POSICAO p);
ESTADO estrat_wolf(ESTADO e, int i, POSICAO p);
ESTADO estrat_bat(ESTADO e, int i, POSICAO p);
ESTADO estrat_ogre(ESTADO e, int i, POSICAO p);
ESTADO estrat_archer(ESTADO e, int i, POSICAO p);
POSICAO quemAtaca(ESTADO e);
ESTADO iaMoves (ESTADO e,int i);
ESTADO move_monstros(ESTADO e);

#endif
