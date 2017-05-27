#include "antiCheat.h"

int validMenu(ESTADO e){
	return e.screen==0
		|| e.screen==1
		|| e.screen==2
		|| e.screen==3
		|| e.screen==4
		|| (e.screen==5 && e.hp<=0);
}
int validNewLevel(ESTADO e){
	POSICAO cima;
	POSICAO direita;
	POSICAO baixo;
	POSICAO esquerda;
	cima.x		=e.jog.x;	cima.y		=e.jog.y-1;
	direita.x	=e.jog.x+1;	direita.y	=e.jog.y;
	baixo.x		=e.jog.x;	baixo.y		=e.jog.y+1;
	esquerda.x	=e.jog.x-1;	esquerda.y	=e.jog.y;
	return e.screen==6
		|| (e.screen==5
			&& (com_saida(e,cima)
				|| com_saida(e,direita)
				|| com_saida(e,baixo)
				|| com_saida(e,esquerda)));
}
int validMove(ESTADO e){
	POSICAO tmp = calculaNovaPosicao(e.jog, e.action);
	return e.screen==5
		&& !outOfBounds(tmp)
		&& !pos_ocupada(e,tmp)
		&& !com_saida(e,tmp);
}
int validAtack(ESTADO e){
	POSICAO tmp = calculaNovaPosicao(e.jog, e.action-10);
	return e.screen==5
		&& com_monstros(e,tmp);
}
int validItemUse(ESTADO e){
	return e.screen==5
		&& e.bag.inv[e.action-40]!=0;
}
/*
int validBossAtack(ESTADO e){ FINISH THIS validAction.c l32
	return 0;
}*/
int isInMenu(ESTADO e){
	return e.screen==1;
}
int isInCharSelect(ESTADO e){
	return e.screen==2;
}
int isInShop(ESTADO e){
	return e.screen==6;
}
int validAction(ESTADO e){
	if(ACT_GOTO_MENU){/* main menu */
		return validMenu(e);
	}
	if(ACT_EXIT){/* saida */
		return validNewLevel(e);
	}
	if(ACT_MOVE){/* mover jogador */
		return validMove(e);
	}
	if(ACT_ATACK){/* ataque normal */
		return validAtack(e);
	}
	if(ACT_USE_ITEM){
		return validItemUse(e);
	}
/*	if(e.action==30){
		return validBossAtack(e);
	}
*/	if(ACT_MENU_SCORE_OR_HELP || ACT_MENU_PLAY){/* escolha do menu */
		return isInMenu(e);
	}
	if(ACT_CLASS_CHOICE){/* novo jogo */
		return isInCharSelect(e);
	}
	if(ACT_SHOP_CHOICE){/* loja */
		return isInShop(e);
	}

	return 1;
}
