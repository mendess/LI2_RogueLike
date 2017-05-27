/* #define DEBUG */

#include "jogo.h"

ESTADO calcularNovoEstado(ESTADO e){
	#ifdef ANTICHEAT
	if(!validAction(e)){
		return e;
	}
	#endif
	if(ACT_GOTO_MENU){/* main menu*/
		e.screen=1;
		return e;
	}
	if(ACT_EXIT){/* saida */
		return newLevel(e);
	}
	if(PLR_FACING_LEFT){/* set direction */
		e.direction=0;
	}
	if(PLR_FACING_RIGHT){/* set direction */
		e.direction=1;
	}
	if(ACT_MOVE){/* mover jogador */
		e.jog=calculaNovaPosicao(e.jog,e.action);
	}
	if(ACT_ATACK){/* ataque normal */
		e=calcularCombate(e);
	}
	if(ACT_MENU_SCORE_OR_HELP){/* escolha do menu */
		e.screen = e.action-50;
		return e;
	}
	if(ACT_MENU_PLAY){
		if(e.hp<=0){
			e.screen = 2;
		}else{
			e.screen = 5;
		}
	}
	if(ACT_CLASS_CHOICE){/* novo jogo */
		e.classe = e.action-60;
		return inicializar(e);
	}
	if(ACT_SHOP_CHOICE){/* loja */
		e.shopFeedback=0;
		return shop(e);
	}

	e=move_monstros(e);

	e.turn++;

	if(e.hp<1){
		e.hp=0;
	}
	if(e.mp<1){
		e.mp=0;
	}

	return e;
}
ESTADO ler_estado (char *args){
	int act;
	ESTADO e = estadoZero;
	// Se o jogador submeteu um nome
	if(args[0]=='N' && args[1]=='='){
		strcpy(e.name,args+2);
		act = 0;
	}else{
		sscanf(args,"%[^,],%d",e.name,&act);
	}
	FILE *gamestateFile;
	char path[100];
	sprintf(path,"%s%s",FILEPATH,e.name);
	gamestateFile = fopen(path,"r");
	if(gamestateFile){ // Se o jogador escolheu uma save que existe
		int r=fread(&e, sizeof(ESTADO), 1, gamestateFile);
		fclose(gamestateFile);
		if(r<1){
			e = estadoZero;
		}
		e.action = act;
		if(ACT_GOTO_MENU){
			e.screen=1;
		}
	}
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
	#ifdef DEBUG
	keepLog(e);
	#endif
	return e;
}
int main(){

	ESTADO e = runGame();
	if(e.screen==4 && e.hp==0){
		if(e.score>99999){/* isto nunca deve acontecer */
			e.score=99999;/* mas assim tenho a certeza */
		}				  /* que ao imprimir não causa problemas */
		updateScoreBoard(e.score);
	}

	imprime(e);

	return 0;
}
#ifdef DEBUG
void keepLog(ESTADO e){
	FILE *fp;
	char str[50];
	sprintf(str,"/var/www/html/files/gamestate%d",e.turn);
	fp=fopen(str,"w");
	fwrite(&e, sizeof(ESTADO), 1, fp);
	fclose(fp);
}
#endif