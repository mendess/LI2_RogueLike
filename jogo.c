#include "jogo.h"

ESTADO calcularNovoEstado(ESTADO e){
	if(!validAction(e)){
		return e;
	}

	e.feedback=0;
	if(ACT_GOTO_MENU){/* main menu*/
		e.screen=1;
		return e;
	}
	if(ACT_MENU_SCORE_OR_HELP){/* escolha do menu */
		e.turn=0;
		e.screen = e.action-50;
		return e;
	}
	if(ACT_TOGGLE_SB_TYPE){
		e.turn = !e.turn;
		return e;
	}
	if(ACT_MENU_PLAY){
		if(e.hp<=0){
			e.screen = 2;
		}else{
			e.screen = 5;
		}
		return e;
	}
	if(ACT_CLASS_CHOICE){/* novo jogo */
		e.classe = e.action-60;
		return inicializar(e);
	}
	if(ACT_EXIT){/* saida */
		if(e.isInBossBattle == 1){
			e.isInBossBattle=0;
		}
		return newLevel(e);
	}
	if(ACT_TOGGLE_INGAME_HELP){
		e.isInIngameHelp = !e.isInIngameHelp;
		return e;
	}
	if(ASKING_FOR_INGAME_HELP){
		return e;
	}
	if(ACT_USE_ITEM){
		e=useItem(e);
		if(e.complexItem.isBeingUsed || e.isDeletingItems){
			return e;
		}
	}
	if(ACT_TOGGLE_ITEM_MODE){
		e.isDeletingItems=!e.isDeletingItems;
		return e;
	}
	if(PICKING_ITEM_TGT){
		if(e.complexItem.isBeingUsed){
			e=handleComplexItem(e);
			if(!e.complexItem.isBeingCast){
				return e;
			}
		}
	}
	if(ACT_SHOP_CHOICE){/* loja */
		e.feedback=buyItem(e.action,e.lootTable,&(e.bag));
		return e;
	}
	if(PLR_FACING_LEFT){/* set direction */
		e.direction=0;
	}
	if(PLR_FACING_RIGHT){/* set direction */
		e.direction=1;
	}
	if(ACT_MOVE){/* mover jogador */
		e.jog=calcularNovaPosicao(e.jog,e.action);
	}
	if(ACT_LESSER_TELEPORT){
		e.jog=calcularLesserTeleport(e.jog,e.action);
		e.mp-=LESSER_TP_COST;
	}
	if(ACT_ATACK){/* ataque normal */
		e=calcularCombate(e);
	}
	#ifdef BOSS
	if(ACT_BOSS_ATTACK){
		e=calcularDanoBoss(e);
	}
	#endif
	if(ACT_PICK_UP_ITEM){
		e.feedback=pickUpItem(e.jog,e.bag.inv,e.droppedItems,e.action);
		e.jog=calcularNovaPosicao(e.jog,e.action-80);
	}
	if(ACT_OPEN_CHEST){
		openChest(&e);
	}

	e=move_monstros(e);

	e.turn++;

	if(e.hp<1){
		e.hp=0;
	}
	if(e.mp<1){
		e.mp=0;
	}
	if(e.screen==5 && e.hp==0){
		if(e.score>99999){// isto nunca deve acontecer 
			e.score=99999;// mas assim tenho a certeza 
		}				  // que ao imprimir não causa problemas
		updateScoreBoard(e.name,e.score);
	}

	return e;
}
ESTADO ler_estado (char *args){
	int act;
	char name[100];
	ESTADO e = estadoZero;
	if(args[0]=='N' && args[1]=='='){	// Se o jogador submeteu um nome
		strncpy(name,args+2,100);		// Guardar o nome
		act = 0;						// Por a action a 0 (ir para o main menu)
	}else{								// Caso contrario
		sscanf(args,"%100[^,],%d",name,&act); // Guardar o nome e a action
	}
	FILE *gamestateFile;
	char path[100];
	sprintf(path,"%s%s",FILEPATH,name);
	gamestateFile = fopen(path,"r");
	if(gamestateFile){ 					// Se o jogador escolheu uma save que existe
		int r=fread(&e, sizeof(ESTADO), 1, gamestateFile);	// Ler o estado
		fclose(gamestateFile);			// Fechar o ficheiro
		if(r<1){						// Se o ficheiro for mais pequeno do que é esperado
			e = estadoZero;				// Inicializar um novo a 0
		}
	}
	e.action = act;			// Inicializar a ação
	strncpy(e.name,name,13);// Inicializar o nome
	return e;
}
void escrever_estado(ESTADO e){
	if(e.name[0]){
		FILE *gamestateFile;
		char path[100];
		sprintf(path,"%s%s",FILEPATH,e.name);
		gamestateFile = fopen(path,"w");
		if(gamestateFile==NULL){
			perror("Não consegui escrever o estado");
			exit(-1);
		}else{
			fwrite(&e, sizeof(ESTADO), 1, gamestateFile);
			fclose(gamestateFile);
		}
	}
}
ESTADO runGame(){
	char *args = getenv("QUERY_STRING");
	ESTADO e = estadoZero;
	if(strlen(args)==0){
		e.screen = 0;
	}else{
		e = ler_estado(args);
		e = calcularNovoEstado(e);
	}
	escrever_estado(e);
	return e;
}
int main(){
	srand(time(NULL));
	ESTADO e = runGame();

	imprime(e);

	return 0;
}