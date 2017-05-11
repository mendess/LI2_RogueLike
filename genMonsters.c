#include "genMonsters.h"

ESTADO genBoss(ESTADO e){
	e.num_monstros=1;
	e.monstros[0].x   = (SIZE / 2) - 2;
	e.monstros[0].y   =	2;
	e.monstros[0].monType=	4;
	e.monstros[0].hp  = MON_HP_DRAGON;
	return e;
}
ESTADO genBossBattle(ESTADO e){
	e.jog.x=5;
	e.jog.y=9;
	e.saida.x=SIZE+2;
	e.saida.y=SIZE+2;
	return genBoss(e);
}
char getMonsterNumber(char world_lvl){
	char num_monstros = (world_lvl/3)+4;
	return ((num_monstros>MAX_MONSTROS) ? MAX_MONSTROS : num_monstros);
}
char setMonsterType(char world_lvl){
	int r = rand() % 100000;
	double wolf  = WOLF_ODDS(world_lvl);
	double archer= ARCHER_ODDS(world_lvl);
	double tmp   = 100000 - wolf - archer;
	double ogre  = tmp*TIER_SHIFT(world_lvl);
	double bat   = tmp - ogre;
	
	if(r<wolf){
		return 0;
	}
	if(r<wolf+bat){
		return 1;
	}
	if(r<wolf+bat+ogre){
		return 2;
	}
	return 3;
}
char getMonsterHP(char type){
	char monType;
	switch(type){
		case 0: monType = MON_HP_WOLF;
		case 1: monType = MON_HP_BAT;
		case 2: monType = MON_HP_OGRE;
		case 3: monType = MON_HP_ARCHER;
	}
	return monType;
}
/**
\brief Coloca um monstro numa posição aleatoria válida
@param e Estado do jogo
*/
ESTADO placeMonster(ESTADO e, int index){
	POSICAO p;
	int placed=0, i=0;
	while(!placed && i<20){
		i++;
		int x=rand() % SIZE;
		int y=rand() % SIZE;
		p.x=(char) x;
		p.y=(char) y;
		if (!pos_ocupada(e,p)){
			placed=1;
			e.monstros[index].x=p.x;
			e.monstros[index].y=p.y;
			e.monstros[index].hp=getMonsterHP(e.monstros[index].monType);
		}
	}
	return e;
}
/**
\brief Coloca todas os monstros para inicializar o novo nivel
@param e Estado do jogo
*/
ESTADO genMonsters(ESTADO e){
	int i;
	if(e.isInBossBattle){
		e=genBossBattle(e);
	}else{
		e.num_monstros = getMonsterNumber(e.world_lvl);
		for (int i = 0; i < e.num_monstros; ++i){
			e.monstros[i].monType=setMonsterType(e.world_lvl);
		}
		for (i=0;i<e.num_monstros;i++){
			e=placeMonster(e,i);
		}
	}
	return e;
}