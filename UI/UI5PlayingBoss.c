#include "UI5PlayingBoss.h"

void i_fireballs(ESTADO e){
	if(e.turn % 2){
		int i;
		for(i=0;i<e.dragon.num_fireballs;i++){
			POSICAO p = e.dragon.fireballCenters[i];
			IMAGEM_FORMATED(p.x,p.y,TAM,TAM,"Spell_Warning.png");
		}
	}else{
		int i;
		for(i=0;i<e.dragon.num_fireballs;i++){
			POSICAO p = e.dragon.fireballCenters[i];
			IMAGEM_FORMATED(p.x,p.y,TAM,TAM,"Spell_Fire.png");
		}
	}
}
void i_wingAttack(ESTADO e){
	POSICAO p = {e.dragon.pos.x-2,e.dragon.pos.y+4};
	while(p.x<0){
		p.x++;
	}
	int width=8;
	while(p.x+width>SIZE){
		width--;
	}
	if(e.turn % 2){
		int x,y;
		for(x=p.x;x<p.x+width;x++){
			for(y=p.y;y<p.y+2;y++){
				IMAGEM_FORMATED(x,y,TAM,TAM,"Spell_Warning.png");
			}
		}
	}else{
		IMAGEM((p.x+1)*TAM,(p.y+1)*TAM,width*TAM,100,"Spell_WingAttack.png");
	}
}
void i_fireCone(ESTADO e){
	int x,y;
	for(x=0;x<SIZE;x++){
		for(y=0;y<SIZE;y++){
			if(x>=((e.dragon.pos.x+1)-((((y-1)-e.dragon.pos.y)/2)-1)) && x<=((e.dragon.pos.x+2)+(((y-1)-e.dragon.pos.y)/2)-1) && y>(e.dragon.pos.y+2)) {
				if(e.turn % 2){
					IMAGEM_FORMATED(x,y,TAM,TAM,"Spell_Warning.png");
				}else{
					IMAGEM_FORMATED(x,y,TAM,TAM,"Spell_Fire.png");
				}
			}
		}
	}
}
int getDragonImg(int turn){
	if(turn % 2){
		while(turn>3){
			turn-=4;
		}
	}else{
		turn=2;
	}
	return turn-1;
}
void imprime_boss(ESTADO e){
	if(e.dragon.hp>0){
		char *dragonImgs[] = {"Monstro_Dragon_2.png","Monstro_Dragon_1.png","Monstro_Dragon_3.png"};
		IMAGEM((e.dragon.pos.x+1)*TAM,(e.dragon.pos.y+1)*TAM,200,150,dragonImgs[getDragonImg(e.turn)]);
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
}