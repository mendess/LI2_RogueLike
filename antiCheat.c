#include "antiCheat.h"

int validMenu(ESTADO e){
	return 1
		|| e.screen==0
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
	POSICAO tmp = calcularNovaPosicao(e.jog, e.action);
	return e.screen==5
		&& !outOfBounds(tmp)
		&& !pos_ocupada(e,tmp)
		&& !com_saida(e,tmp);
}
int validLesserTeleport(ESTADO e){
	return e.screen==5
		&& CAN_USE_LESSER_TELEPORT;
}
int validAtack(ESTADO e){
	POSICAO tmp;
	if(e.action>20){
		tmp = calculaRangedAtackPos(e.jog,e.action);
	}else{
		tmp = calcularNovaPosicao(e.jog, e.action-10);
	}
	return e.screen==5
		&& com_monstros(e,tmp);
}
int validItemPickup(ESTADO e){
	POSICAO p = calcularNovaPosicao(e.jog,e.action-80);
	return e.screen==5
		&& !com_monstros(e,p)
		&& com_droppedItem(e.droppedItems,p);
}
int validItemUse(ESTADO e){
	return e.bag.inv[e.action-40]!=0
		&& (e.screen==5
			|| (e.screen==6 
				&& e.isDeletingItems));
}
int validOpenChest(ESTADO e){
	POSICAO p = calcularNovaPosicao(e.jog,e.action-90);
	return e.screen==5
		&& !com_monstros(e,p)
		&& com_chest(e,p);
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
	if(ACT_TOGGLE_INGAME_HELP){
		return e.screen==5;
	}
	if(ASKING_FOR_INGAME_HELP){
		return e.isInIngameHelp;
	}
	if(ACT_MOVE){/* mover jogador */
		return validMove(e);
	}
	if(ACT_LESSER_TELEPORT){
		return validLesserTeleport(e);
	}
	if(ACT_ATACK){/* ataque normal */
		return validAtack(e);
	}
	if(ACT_PICK_UP_ITEM){
		return validItemPickup(e);
	}
	if(ACT_USE_ITEM){
		return validItemUse(e);
	}
	if(ACT_TOGGLE_ITEM_MODE){
		return e.screen==5 || e.screen==6;
	}
	if(PICKING_ITEM_TGT){
		return e.complexItem.isBeingUsed==1;
	}
	if(ACT_OPEN_CHEST){
		return validOpenChest(e);
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

	return 0;
}