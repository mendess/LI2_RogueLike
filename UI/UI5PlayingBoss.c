#include "UI5PlayingBoss.h"

void i_fireballs(ESTADO e){
	int i;
	for(i=0;i<dragon.num_fireballs;i++){
		e.action = cTgT2Int(e.dragon.fireballCenters[i]);
		i_castRed(&e);
	}
}
void i_wingAttack(ESTADO e){

}
void i_fireCone(ESTADO e){

}
void imprime_boss(ESTADO e){
	IMAGEM((e.dragon.pos.x+1)*TAM,(e.dragon.pos.y+1)*TAM,200,150,"Monstro_Dragon_1.png");
	switch(e.dragon.attack){
		case 0: break;
		case 1: i_fireballs(e);
				break;
		case 2: i_wingAttack(e);
				break;
		case 3: i_fireCone(e);
				break;
	}
}