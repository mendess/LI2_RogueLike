#include <stdio.h>
#include "IA.h"

int blocked1 (ESTADO e,POSICAO p){
	int i,flag;
	flag=0;
	for(i=0;i<e.num_pedras;i++){
		if(e.pedras[i].x==p.x && e.pedras[i].y==p.y) flag=1;
	}
	return flag;
}// MONSTROS
int blocked2 (ESTADO e,POSICAO p){
	int i,flag;
	flag=0;
	for(i=0;i<e.num_monstros;i++){
		if(e.monstros[i].x==p.x && e.monstros[i].y==p.y) flag=1;
	}
	return flag;
}
int possivel (ESTADO e,POSICAO p){
	int flag;
	flag=1;
	if(blocked1(e,p) || blocked2(e,p) || p.x <0 || p.x==10 || p.y<0 || p.y==10) flag=0;
	return flag;
}
ESTADO blocked_chest(ESTADO e,int i,POSICAO chest,POSICAO monstro){
	POSICAO pos=monstro;
	int flag=1;
	if(e.jog.y<chest.y && monstro.y>=chest.y){
		pos.y-=1;
		if(possivel(e,pos)){
			e.monstros[i].y=pos.y;
			flag=0;
		}
	}
	if(flag && e.jog.y>chest.y && monstro.y<=chest.y){
		pos.y+=1;
		if(possivel(e,pos)){
			e.monstros[i].y=pos.y;
			flag=0;
		}
	}
	if(flag && e.jog.x<=chest.x && monstro.x>=chest.x){
		pos.x-=1;
		if(possivel(e,pos)){
			e.monstros[i].x=pos.x;
			flag=0;
		}
	}
	if(flag && e.jog.x>=chest.x && monstro.x<=chest.x){
		pos.x+=1;
		if(possivel(e,pos)){
			e.monstros[i].x=pos.x;
		}
	}
	return e;
}
ESTADO protect_it(ESTADO e,int i,POSICAO p){
	int x,y,z,flag;flag=1;
	POSICAO chest;
	for(x=-1;x<=1 && flag;x++){
		for(y=-1;y<=1 && flag;y++){
			chest.x=p.x+x;
			chest.y=p.y+y;
			for(z=0;z<e.num_chests && flag;z++){
				if(chest.x==e.chests[z].pos.x && chest.y==e.chests[z].pos.y) flag=0;
			}
		}
	}
	e= blocked_chest(e,i,chest,p);
	return e;
}
int next2chest(ESTADO e,POSICAO p){
	int x,y,z,flag=0;
	POSICAO pos;
	for(x=-1;x<=1;x++){
		for(y=-1;y<=1;y++){
			pos.x=p.x+x;
			pos.y=p.y+y;
			for(z=0;z<e.num_chests;z++){
				if(e.chests[z].pos.x==pos.x && e.chests[z].pos.y==pos.y){
					flag=1;
				}
			}
		}
	}
	return flag;
}
ESTADO estrat_ogre (ESTADO e,int i,POSICAO p){
	int flag=1;
	if (existe_jogador(e,p)){
		e=ataca_jogador(e,OGRE_DMG);
		flag=0;
	}
	if(flag && next2chest(e,p)){
		e=protect_it(e,i,p);
	}
	return e;
}
