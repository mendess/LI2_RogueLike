#include "UI5PlayingBoss.h"

void i_warningFireball(ESTADO *e){
	POSICAO p = itAct2Pos(e->action);
	int pXmax=p.x+2;
	int pYmax=p.y+2;
	for(p.x=pXmax-3;p.x<pXmax;p.x++){
		for (p.y=pYmax-3;p.y < pYmax; p.y++){
			if(!outOfBounds(p) && !com_pedras(*e,p) && !com_boss(*e,p)){
				IMAGEM(TAM*(p.x+1),TAM*(p.y+1),TAM,TAM,"Spell_Warning.png");
			}
		}
	}
}
void i_fireballs(ESTADO e){
	if(e.turn % 2){
		int i;
		for(i=0;i<dragon.num_fireballs;i++){
			e.action = cTgT2Int(e.dragon.fireballCenters[i]);
			i_warningFireball(&e);
		}
	}else{
		int i;
		for(i=0;i<dragon.num_fireballs;i++){
			e.action = cTgT2Int(e.dragon.fireballCenters[i]);
			i_castRed(&e);
		}
	}
}
void i_wingAttack(ESTADO e){
	POSICAO p = {e.dragon.pos.x-3,e.dragon.pos.y+3};
	while(p.x<0){
		p.x++;
	}
	int width=8;
	while(p.x+width>SIZE){
		width--;
	}
	if(e.turn % 2){
		for(x=p.x;x<2;x++){
			for(y=p.y;y<width;y++){
				IMAGEM_FORMATED(x,y,TAM,TAM,"Spell_Warning.png");
			}
		}
	}else{
		IMAGEM((p.x+1)*TAM,(p.y+1)*TAM,width*TAM,100,"Spell_WingAttack.png");
	}
}
void i_fireCone(ESTADO e){
	int linha=1;
	POSICAO startingP = {e.dragon.pos.x+2,e.dragon.pos.y+2};
	while((startingP.y+linha)<SIZE){
		int i;
		for(i=0;i<linha*2;i++){
			POSICAO tmp = {startingP.x-linha+i;startingP.y+linha}
			if(!outOfBounds(tmp)){
				if(e.turn % 2){
					IMAGEM_FORMATED(tmp.x,tmp.y,TAM,TAM,"Spell_Warning.png");
				}else{
					IMAGEM_FORMATED(tmp.x,tmp.y,TAM,TAM,"Spell_Warning.png");
				}
			}
		}
		linha++;
	}
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