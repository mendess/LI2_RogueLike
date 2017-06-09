#include "colisions.h"

int outOfBounds(POSICAO p){
	return p.x<0 || p.x>= SIZE || p.y<0 || p.y>=SIZE;
}
int isOnPath(POSICAO p, int pathSize, POSICAO path[]){ 
	int i, flag;
	flag=0;
	for (i=1;i<pathSize && !flag;i++){
		if (path[i].x == p.x && path[i].y == p.y){
			flag=1;
		}
	}
	return flag;
}
int pos_ocupada (ESTADO e, POSICAO p){
	return com_jogador(e,p) || com_pedras(e,p) || com_monstros(e,p);
}
int pos_completamente_livre(ESTADO e, int x, int y){
	POSICAO tmp = {x,y};
	return !pos_ocupada(e,tmp) && !com_saida(e,tmp) && !outOfBounds(tmp) && !com_chest(e,tmp) && !com_droppedItem(e.droppedItems,tmp);
}
int com_saida (ESTADO e, POSICAO p){
	return (e.saida.x==p.x) && (e.saida.y==p.y);
}
int com_jogador (ESTADO e,POSICAO p){
	return (e.jog.x == p.x) && (e.jog.y == p.y);
}
int com_pedras (ESTADO e, POSICAO p){
	int i,flag;
	flag=0;
	for(i=0;i<e.num_pedras && !flag;i++){
		if (e.pedras[i].x == p.x && e.pedras[i].y == p.y){
			flag=1;
		}
	}
	return flag;
}
int com_monstros (ESTADO e, POSICAO p){
	int i,flag;
	flag=0;
	for (i=0;i<e.num_monstros && !flag;i++){
		if (e.monstros[i].x == p.x && e.monstros[i].y == p.y){
			flag=1;
		}
	}
	return flag;
}
int com_chest(ESTADO e, POSICAO p){
	int i,flag;
	flag=0;
	for(i=0;i<e.num_chests && !flag;i++){
		if(e.chests[i].pos.x == p.x && e.chests[i].pos.y == p.y){
			flag=1;
		}
	}
	return flag;
}
int com_droppedItem(CHEST droppedItems[], POSICAO p){
	int i=0, foundItem=0;
	while(i<MAX_DROPPED_ITEMS && !foundItem){
		if(droppedItems[i].item!=0 && droppedItems[i].pos.x == p.x && droppedItems[i].pos.y == p.y){
			foundItem=1;
		}else{
			i++;
		}
	}
	return foundItem;
}
int isBoss(ESTADO e, POSICAO p){
	return (e.isInBossBattle &&
			p.x>=e.monstros[0].x && p.x<=e.monstros[0].x+3 &&
			p.y>=e.monstros[0].y && p.y<=e.monstros[0].y+2   );
}