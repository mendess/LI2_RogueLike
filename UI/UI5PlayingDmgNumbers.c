#include "UI5PlayingDmgNumbers.h"

void i_dmgTaken(POSICAO jog, int dmgTaken){
	if(dmgTaken){
		DMG_NUM(jog.x,jog.y,dmgTaken,"blood_red.png");
	}
}
void i_dmgDealtSpells_Fire(ESTADO *e){
	if(e->isInBossBattle){
		POSICAO p = itAct2Pos(e->action);
		int hitBoss=0;
		int pXmax=p.x+2;
		int pYmax=p.y+2;
		for(p.x=pXmax-3;p.x<pXmax && !hitBoss;p.x++){
			for (p.y=pYmax-3;p.y < pYmax && !hitBoss; p.y++){
				int hit = 0;
				if(!com_pedras(*e,p)){
					hit = hitMonster(e,p,SCROLL_FIRE_DMG);
				}
				if(hit){
					DMG_NUM(e->dragon.pos.x+3,e->dragon.pos.y,SCROLL_FIRE_DMG,"blood_orange.png");
					hitBoss=1;
				}
			}
		}
	}else{
		POSICAO p = itAct2Pos(e->action);
		int pXmax=p.x+2;
		int pYmax=p.y+2;
		for(p.x=pXmax-3;p.x<pXmax;p.x++){
			for (p.y=pYmax-3;p.y < pYmax; p.y++){
				if(com_monstros(*e,p) && !outOfBounds(p) && !com_pedras(*e,p)){
					DMG_NUM(p.x,p.y,SCROLL_FIRE_DMG,"blood_orange.png");
				}
			}
		}
	}
}
void i_dmgDealtSpells_Lightning(ESTADO *e){
	int i;
	for(i=0;i<e->complexItem.num_bolts;i++){
		DMG_NUM(e->complexItem.boltTargets[i].x,e->complexItem.boltTargets[i].y,SCROLL_LIGHTNING_DMG - (10*i),"blood_yellow.png");
	}
}
void i_dmgDealtSpells_Poison(ESTADO *e){
	if(e->isInBossBattle){
		if(e->dragon.poison){
			DMG_NUM(e->dragon.pos.x+3,e->dragon.pos.y,POISON_DMG,"blood_green.png");
		}
	}else{
		int i;
		for(i=0;i<e->num_monstros;i++){
			if(e->monstros[i].poison){
				DMG_NUM(e->monstros[i].x,e->monstros[i].y,POISON_DMG,"blood_green.png");
			}
		}
	}
}
void i_dmgDealtSpells(ESTADO *e){
	switch(e->complexItem.type){
		case 3: i_dmgDealtSpells_Fire(e);
				break;
		case 4: i_dmgDealtSpells_Lightning(e);
				break;
	}
}
void i_dmgDealtNormal(ESTADO *e){
	POSICAO tgt = {-1,-1};
	if(e->isInBossBattle){
		tgt.x = e->dragon.pos.x+3;
		tgt.y = e->dragon.pos.y;	
	}else if(e->action<20){
		tgt = calcularNovaPosicao(e->jog,e->action-10);
	}else if(e->action<30){
		tgt = calculaRangedAtackPos(e->jog,e->action);
	}
	DMG_NUM(tgt.x,tgt.y,calcPlayerDmg(e->classe,e->bag),"blood_red.png");
}
void imprime_dmgNum(ESTADO *e){
	i_dmgTaken(e->jog,e->dmgTaken);
	if(e->complexItem.isBeingCast && e->action>9999 && !e->isInIngameHelp){
		i_dmgDealtSpells(e);
	}else{
		i_dmgDealtSpells_Poison(e);
	}
	if(e->action>10 && e->action<30){
		i_dmgDealtNormal(e);
	}
}