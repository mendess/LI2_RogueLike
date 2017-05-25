/* #define DEBUG */
#define ANTICHEAT
#include "path.h"
#include "html/htmlMaster.h"
#include "score.h"
#include "levelMaker.h"
#include "move_monst.h"
#include "colisions.h"
#include "calcularCombate.h"
#include "loot.h"
#include "shop.h"
#include "antiCheat.h"
#include "calcularCombate.h"
#include "jogo.h"

/**
\brief Inicializa o estado do jogo
*/
ESTADO inicializar(char classe){

	ESTADO e;
	POSICAO path[MAX_CAMINHO];
	int n=pathMaker(path);
	srand(time(NULL));
	e.screen=4;					/* Ecra de jogo */
	e.classe=classe;			/* Classe {Warrior=1, Archer=2, Mage=3} */
	e.hp=getClassHp(e.classe);	/* Vida do jogador */
	e.mp=getClassMp(e.classe);	/* Mana do jogador */
	e.world_lvl=1;				/* Nivel */
	e.score=0;					/* Score */
	e.turn=0;					/* Turno */
	e.direction=0;				/* Lado para que o jogador esta a olhar 0:drt e 1:esq */
	e.action=0;					/* Action */
	generateLoot(e.lootTable,e.world_lvl);/* Inicializar LootTable para o primeiro nivel */
	e.isInShop=0;				/* O jogador começa fora da loja logo começa a 0 */
	e.shopFeedback=0;
	e.bag=initINVT(e.bag);		/* Inicializar o inventario */
	e.jog.x=path[0].x;			/* Posição do jogador (x) */
	e.jog.y=path[0].y;			/* Posição do jogador (y) */
	e.saida.x=path[n-1].x;		/* Posição da saida (x) */
	e.saida.y=path[n-1].y;		/* Posição da saida (y) */
	e.num_monstros=0;			/* Numero de Monstros */
	e.num_pedras=0;				/* Numero de pedras */
	e=colocar_pedras(e,n,path);	/* Posições da pedras */
	e=colocar_monstros(e);		/* Posições dos monstros */
	return e;
}
/**
\brief Gera um novo nivel quando o jogador chega a saida
@param e Estado do Jogo
*/
ESTADO newLevel(ESTADO e){

	POSICAO path[MAX_CAMINHO];
	int n;
	if(!(e.world_lvl % 5)){
		if(e.isInShop){
			e.screen=4;
			e.isInShop=0;
		}else{
			generateLoot(e.lootTable,e.world_lvl);
			e.screen=5;
			e.isInShop=1;
			e.shopFeedback=0;
			return e;
		}
	}
	n=pathMaker(path);
	srand(time(NULL));
	/* Vida do jogador */
	if(e.hp>(getClassHp(e.classe)-NEW_LEVEL_HP_BONUS)){
		e.hp=getClassHp(e.classe);
	}else{
		e.hp+=NEW_LEVEL_HP_BONUS;
	}
	/* Mana do jogador */
	if(e.mp>(getClassMp(e.classe)-NEW_LEVEL_MP_BONUS)){
		e.mp=getClassMp(e.classe);
	}else{
		e.mp+=NEW_LEVEL_MP_BONUS;
	}
	e.world_lvl+=1;				/* Nivel */
	e.score+=NEW_LEVEL_SC_BONUS;/* Score */
	e.turn=0;					/* Turno */
	e.direction=0;				/* Lado para que o jogador esta a olhar 0:direita e 1:esquerda */
	e.action=0;					/* Action */
	generateLoot(e.lootTable,e.world_lvl);/* Inicializar LootTable para o nivel */
	e.jog.x=path[0].x;			/* Posição do jogador (x) */
	e.jog.y=path[0].y;			/* Posição do jogador (y) */
	e.saida.x=path[n-1].x;		/* Posição da saida (x) */
	e.saida.y=path[n-1].y;		/* Posição da saida (y) */
	e.num_monstros=0;			/* Numero de Monstros */
	e.num_pedras=0;				/* Numero de pedras */
	e=colocar_pedras(e,n,path);	/* Posições da pedras */
	e=colocar_monstros(e);		/* Posições dos monstros */
	return e;
}
/**
\brief Calcula a nova posição do jogador
@param jog A posição antiga do jogador
@param act Ação selecionada
*/
POSICAO calculaNovaPosicao(POSICAO jog, int act){
	int x[10]={5,-1, 0, 1,-1, 5, 1,-1, 0, 1};
	/*          0  1  2  3  4  5  6  7  8  9 */
	int y[10]={5, 1, 1, 1, 0, 5, 0,-1,-1,-1};

	if(act!=0 && act!=5){
		jog.x+=x[act];
		jog.y+=y[act];
	}
	return jog;
}
/**
\brief Calcula um novo estado conforme a ação que esteja no estado que recebe
@param e Estado do jogo
*/
ESTADO calcularNovoEstado(ESTADO e){
	#ifdef ANTICHEAT
	if(!validAction(e)){
		return e;
	}
	#endif
	if(ACT_GOTO_MENU){/* main menu*/
		e.screen=0;
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
	if(ACT_MENU_CHOICE){/* escolha do menu */
		e.screen = e.action-50;
		return e;
	}
	if(ACT_CLASS_CHOICE){/* novo jogo */
		return inicializar(e.action-60);
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
/**
\brief Lê o estado de um ficheiro
Converte o estado que estava em hexadecimal no ficheiro para uma struct ESTADO e muda a action conforme a que está na QUERY_STRING
@param args QUERY_STRING
@param gamestateFile Apontador para um ficheiro com o estado
*/
ESTADO ler_estado (char *args){
	int act;
	ESTADO e = estadoZero;
	FILE *gamestateFile;
	gamestateFile = fopen("/var/www/html/files/gamestate","r");
	if(gamestateFile){
		int r=fread(&e, sizeof(ESTADO), 1, gamestateFile);
		fclose(gamestateFile);
		if(r<1){
			e = estadoZero;
		}
	}
	sscanf(args,"%d",&act);
	e.action = act;
	return e;
}
void escrever_estado(ESTADO e){
	FILE *gamestateFile;
	gamestateFile = fopen("/var/www/html/files/gamestate","w");
	if(gamestateFile==NULL){
		perror("Não consegui escrever o estado");
		exit(-1);
	}else{
		fwrite(&e, sizeof(ESTADO), 1, gamestateFile);
		fclose(gamestateFile);
	}
}
/**
\brief Corre o jogo.
Cria um novo jogo se estiver a começar ou faz "update" ao estado conforme o que o jogador fez.
*/
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
/**
\brief Main
*/
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