#ifndef __HTML_5_SPELLS_H__
#define __HTML_5_SPELLS_H__

#include "html5Playing.h"
#include "../items.h"

#define RED_CAST_TARGETS(jog)	{{jog.x-1,jog.y-3},\
								 {jog.x  ,jog.y-3},\
								 {jog.x+1,jog.y-3},\
								 \
								 {jog.x-2,jog.y-2},\
								 {jog.x-1,jog.y-2},\
								 {jog.x  ,jog.y-2},\
								 {jog.x+1,jog.y-2},\
								 {jog.x+2,jog.y-2},\
								 \
								 {jog.x-3,jog.y-1},\
								 {jog.x-2,jog.y-1},\
								 {jog.x-1,jog.y-1},\
								 {jog.x  ,jog.y-1},\
								 {jog.x+1,jog.y-1},\
								 {jog.x+2,jog.y-1},\
								 {jog.x+3,jog.y-1},\
								 \
								 {jog.x-3,jog.y  },\
								 {jog.x-2,jog.y  },\
								 {jog.x-1,jog.y  },\
								 {jog.x  ,jog.y  },\
								 {jog.x+1,jog.y  },\
								 {jog.x+2,jog.y  },\
								 {jog.x+3,jog.y  },\
								 \
								 {jog.x-3,jog.y+1},\
								 {jog.x-2,jog.y+1},\
								 {jog.x-1,jog.y+1},\
								 {jog.x  ,jog.y+1},\
								 {jog.x+1,jog.y+1},\
								 {jog.x+2,jog.y+1},\
								 {jog.x+3,jog.y+1},\
								 \
								 {jog.x-2,jog.y+2},\
								 {jog.x-1,jog.y+2},\
								 {jog.x  ,jog.y+2},\
								 {jog.x+1,jog.y+2},\
								 {jog.x+2,jog.y+2},\
								 \
								 {jog.x-1,jog.y+3},\
								 {jog.x  ,jog.y+3},\
								 {jog.x+1,jog.y+3}}

#define TARGET_MOLDS	{"red","yellow","green","blue"}

#define FIRE_IMAGE		"Spell_Fire.png"

void i_cTarget(int type,POSICAO p);
int cTgT2Int(POSICAO p);

/* RED ZONE */
void i_castTargetsRed(ESTADO *e);
void i_confirmCastRed(ESTADO *e);
void i_CastRed(ESTADO *e);
/* YELLOW ZONE */
void i_castTargetsYellow(ESTADO *e);
void i_confirmCastYellow(ESTADO *e);
void i_CastYellow(ESTADO *e);
/* BLUE ZONE */
void i_castTargetsBlue(ESTADO *e);
void i_confirmCastBlue(ESTADO *e);
void i_CastBlue(ESTADO *e);

void imprime_castSpell(ESTADO *e);
void imprime_confirmCast(ESTADO *e);
void imprime_castTargets(ESTADO *e);

#endif