#include "antiCheat.h"

int validMenu(ESTADO e){
	return e.screen==1
		|| e.screen==2
		|| e.screen==3
		|| e.hp<0;
}
int validNewLevel(ESTADO e){
	POSICAO cima	= {e.jog.x  ,e.jog.y-1};
	POSICAO direita	= {e.jog.x+1,e.jog.y  };
	POSICAO baixo	= {e.jog.x  ,e.jog.y+1};
	POSICAO esquerda= {e.jog.x-1,e.jog.y  };
	return com_saida(e,cima)
		|| com_saida(e,direita)
		|| com_saida(e,baixo)
		|| com_saida(e,esquerda);
}
int validMove(ESTADO e){
	POSICAO tmp = calculaNovaPosicao(e.jog, e.action);
	return !outOfBounds(tmp)
		&& !pos_ocupada(e,tmp)
		&& !com_saida(e,tmp);
}
int validAtack(ESTADO e){
	POSICAO tmp = calculaNovaPosicao(e.jog, e.action-10);
	return com_monstros(e,tmp);
}
int validItemUse(ESTADO e){
	return e.bag.inv[e.action-20]!=0;
}
int validBossAtack(ESTADO e){//FINISH THIS validAction.c l32
	return 0;
}
int isInMenu(ESTADO e){
	return e.screen==0;
}
int isInCharSelect(ESTADO e){
	return e.screen==1;
}
int isInShop(ESTADO e){
	return e.screen==5;
}
int validAction(ESTADO e){
	if(e.action==0){//main menu
		return validMenu(e);
	}
	if(e.action==5){//saida
		return validNewLevel(e);
	}
	if(e.action>0 && e.action<10){//mover jogador
		return validMove(e);
	}
	if(e.action>10 && e.action<20){//ataque normal
		return validAtack(e);
	}
	if(e.action>19 && e.action<30){
		return validItemUse(e);
	}
	if(e.action==30){
		return validBossAtack(e);
	}
	if(e.action>50 && e.action<60){//escolha do menu
		return isInMenu(e);
	}
	if(e.action>60 && e.action<70){//novo jogo
		return isInCharSelect(e);
	}
	if(e.action>69 && e.action<82){//loja
		return isInShop(e);
	}

	return 1;
}