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
int getNumMonst(int world_lvl){
	int num_monstros = (world_lvl/3)+4;
	return ((num_monstros>MAX_MONSTROS) ? MAX_MONSTROS : num_monstros);
}
int getMonsterHP(int type){
	int monType;
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
ESTADO placeMonster(ESTADO e, int type){
	POSICAO p;
	int placed=0, i=0;
	while(!placed && i<20){
		i++;
		p.x=rand() % SIZE;
		p.y=rand() % (SIZE-2);
		if (!pos_ocupada(e,p) && !com_chest(e,p)){
			placed=1;
			e.monstros[e.num_monstros].x=p.x;
			e.monstros[e.num_monstros].y=p.y;
			e.monstros[e.num_monstros].monType=type;
			e.monstros[e.num_monstros].hp=getMonsterHP(e.monstros[e.num_monstros].monType);
		}
	}
	e.num_monstros++;
	return e;
}
ESTADO placeOgre(ESTADO e){
	e=placeMonster(e,2);
	CHEST chest;
	chest.pos.x=e.monstros[0].x;
	chest.pos.y=e.monstros[0].y;
	chest=genChest(e,chest);
	e.num_chests++;
	e.chests[0]=chest;
	return e;

}
int pos_ocupada_aux(ESTADO e, int x, int y){
	POSICAO tmp = {x,y};
	return pos_ocupada(e,tmp) || com_saida(e,tmp) || outOfBounds(tmp);
}
CHEST genChest(ESTADO e,CHEST chest){
	if(      !pos_ocupada_aux(e,chest.pos.x,chest.pos.y-1)){
		chest.pos.y--;
	}else if(!pos_ocupada_aux(e,chest.pos.x+1,chest.pos.y)){
		chest.pos.x++;
	}else if(!pos_ocupada_aux(e,chest.pos.x-1,chest.pos.y)){
		chest.pos.x--;
	}else if(!pos_ocupada_aux(e,chest.pos.x,chest.pos.y+1)){
		chest.pos.y++;
	}
	int r = rand() % 60;
	if(r<30){
		chest.item=generateScroll();
	}else if(r<45){
		chest.item=generateSword(e.world_lvl+10);
	}else{
		chest.item=generateArmour(e.world_lvl+10);
	}
	return chest;
}
/**
\brief Coloca todas os monstros para inicializar o novo nivel
@param e Estado do jogo
*/
ESTADO genMonsters(ESTADO e){
	e.num_chests=0;
	if(e.isInBossBattle){
		e=genBossBattle(e);
	}else{
		if(e.world_lvl>4 && (e.world_lvl>11 || e.world_lvl % 2)){
			e=placeOgre(e);
		}
		if(e.world_lvl>7 && (e.world_lvl>20 || !((e.world_lvl+1) % 3))){
			e=placeMonster(e,3);
		}
		int range;
		if(e.world_lvl>2){
			range=2;
		}else{
			range=1;
		}
		int target_num_monst = getNumMonst(e.world_lvl);
		int i=e.num_monstros;
		while(i<target_num_monst){
			int type = rand() % range;
			e=placeMonster(e,type);
			i++;
		}
	}
	return e;
}