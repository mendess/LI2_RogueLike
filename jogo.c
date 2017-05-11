//#define DEBUG
#include "path.h"
#include "html/htmlMaster.h"
#include "score.h"
#include "levelMaker.h"
#include "colisions.h"
#include "loot.h"
#include "genMonsters.h"
#include "shop.h"
#include "IA/IA.h"
#include "jogo.h"
/**
\brief Inicializa o estado do jogo
*/
ESTADO inicializar(char classe){

	ESTADO e;
	POSICAO path[MAX_CAMINHO];
	int n=pathMaker(path);
	srandom(time(NULL));
	e.screen=4;					//Ecra de jogo
	e.classe=classe;			//Classe {Warrior=1, Archer=2, Mage=3}
	e.hp=getClassHp(e.classe);	//Vida do jogador
	e.mp=getClassMp(e.classe);	//Mana do jogador
	e.world_lvl=1;				//Nivel
	e.score=0;					//Score
	e.turn=0;					//Turno
	e.direction=0;				//Lado para que o jogador esta a olhar 0:drt e 1:esq
	e.action=0;					//Action
	generateLoot(e.lootTable,e.world_lvl);//Inicializar LootTable para o primeiro nivel
	e.isInShop=0;				//O jogador começa fora da loja 
	e.shopFeedback=0;
	e.isInBossBattle=0;			//O jogador começa fora da boss battle
	e.bag=initINVT(e.bag);		//Inicializar o inventario
	e.jog.x=path[0].x;			//Posição do jogador (x)
	e.jog.y=path[0].y;			//Posição do jogador (y)
	e.saida.x=path[n-1].x;		//Posição da saida (x)
	e.saida.y=path[n-1].y;		//Posição da saida (y)
	e.num_monstros=0;			//Numero de Monstros
	e.num_pedras=0;				//Numero de pedras
	e.num_chests=0;				//Numero de chests
	e=colocar_pedras(e,n,path);	//Posições da pedras
	e=genMonsters(e);			//Posições dos monstros

	return e;
}
/**
\brief Gera um novo nivel quando o jogador chega a saida
@param e Estado do Jogo
*/
ESTADO newLevel(ESTADO e){

	#ifdef BOSS
	if(!((e.world_lvl+1) % 10)){	//Se o jogador chegou a um nivel multiplo de 10:
		e.isInBossBattle=1;		//Começa uma boss battle
	}
	#endif
	if(!(e.world_lvl % 5)){	//Se o jogador acabou de sair de um nivel multiplo de 5:
		if(e.isInShop){		//Se estava na loja:
			e.screen=4;		//Sai
			e.isInShop=0;	//da loja
		}else{										//Se não estava na loja:
			generateLoot(e.lootTable,e.world_lvl);	//Entra
			e.screen=5;								//na
			e.isInShop=1;							//loja
			return e;
		}
	}
	POSICAO path[MAX_CAMINHO];		//Gera um caminho para garantir
	int n=pathMaker(path);			//que o jogador consegue chegar ao fim
	srandom(time(NULL));
	if(e.hp>(getClassHp(e.classe)-NEW_LEVEL_HP_BONUS)){	//Adiciona um bonus
		e.hp=getClassHp(e.classe);						//de vida por 
	}else{												//ter passado
		e.hp+=NEW_LEVEL_HP_BONUS;						//de nivel
	}
	if(e.mp>(getClassMp(e.classe)-NEW_LEVEL_MP_BONUS)){	//Adiciona um bonus
		e.mp=getClassMp(e.classe);						//de mana por
	}else{												//ter passado
		e.mp+=NEW_LEVEL_MP_BONUS;						//de nivel
	}
	e.world_lvl++;				//Incrementa o nivel.
	e.score+=NEW_LEVEL_SC_BONUS;			//Adiciona score de passar de nivel
	e.turn=0;								//Turno a 0
	e.direction=0;							//Lado para que o jogador esta a olhar 0:drt e 1:esq
	e.action=0;								//Action
	generateLoot(e.lootTable,e.world_lvl);	//Inicializar LootTable para o nivel
	e.jog.x=path[0].x;						//Posição do jogador (x)
	e.jog.y=path[0].y;						//Posição do jogador (y)
	e.saida.x=path[n-1].x;					//Posição da saida (x)
	e.saida.y=path[n-1].y;					//Posição da saida (y)
	e.num_monstros=0;						//Numero de Monstros
	e.num_pedras=0;							//Numero de pedras
	e.num_chests=0;							//Numero de chests
	e=colocar_pedras(e,n,path);				//Posições da pedras
	e=genMonsters(e);						//Posições dos monstros

	return e;
}
/**
\brief Calcula a nova posição do jogador
@param jog A posição antiga do jogador
@param act Ação selecionada
*/
POSICAO calculaNovaPosicao(POSICAO jog, int act){
	int x[10]={5,-1, 0, 1,-1, 5, 1,-1, 0, 1};
	//         0  1  2  3  4  5  6  7  8  9
	int y[10]={5, 1, 1, 1, 0, 5, 0,-1,-1,-1};

	if(act!=0 && act!=5){
		jog.x+=x[act];
		jog.y+=y[act];
	}
	return jog;
}
ESTADO calcularCombate(ESTADO e){
	return e;
}
ESTADO calcularDanoBoss(ESTADO e){
	return e;
}
/**
\brief Calcula um novo estado conforme a ação que esteja no estado que recebe
@param e Estado do jogo
*/
ESTADO calcularNovoEstado(ESTADO e){
	if(e.action==0){//main menu
		e.screen=0;
		return e;
	}
	if(e.action==5){//saida
		if(e.isInBossBattle == 1){e.isInBossBattle=0;}
		return newLevel(e);
	}
	if(e.action==9 || e.action==6 || e.action==3){//set direction
		e.direction=0;
	}
	if(e.action==7 || e.action==4 || e.action==1){//set direction
		e.direction=1;
	}
	if(e.action>0 && e.action<10){//mover jogador
		e.jog=calculaNovaPosicao(e.jog,e.action);
	}
	if(e.action>10 && e.action<20){//ataque normal
		e=calcularCombate(e);
	}
	if(e.action==30){
		e=calcularDanoBoss(e);
	}
	if(e.action>50 && e.action<60){//escolha do menu
		e.screen = e.action-50;
		return e;
	}
	if(e.action>60 && e.action<70){//novo jogo
		return inicializar(e.action-60);
	}
	if(e.action>69 && e.action<82){//loja
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
ESTADO ler_estado (char *args,FILE *gamestateFile){
	int act;
	ESTADO e;
	if(fread(&e, sizeof(ESTADO), 1, gamestateFile)){
		sscanf(args,"%d",&act);
		e.action = act;
		return e;
	}else{
		return e; //PERGUNTAR AOS STORES
	}
}
/**
\brief Corre o jogo.
Cria um novo jogo se estiver a começar ou faz "update" ao estado conforme o que o jogador fez.
*/
ESTADO runGame(){
	char *args = getenv("QUERY_STRING");
	ESTADO e;
	FILE *gamestateFile;
	char filepath[15];

	#ifdef DEBUG
	strcpy(filepath,"gamestate");
	#else
	strcpy(filepath,"/tmp/gamestate");
	#endif

	if(strlen(args)==0){
		gamestateFile = fopen(filepath,"w");
		e.screen = 0;
	}else{
		gamestateFile = fopen(filepath,"r+");
		e = ler_estado(args,gamestateFile);
		e = calcularNovoEstado(e);
		gamestateFile = freopen(filepath,"w",gamestateFile);
	}
	fwrite(&e, sizeof(ESTADO), 1, gamestateFile);
	fclose(gamestateFile);
	return e;
}
/**
\brief Main
*/
int main(){

	ESTADO e = runGame();
	if(e.screen==4 && e.hp==0){
		if(e.score>99999){//isto nunca deve acontecer
			e.score=99999;//mas assim tenho a certeza
		}				  //que ao imprimir não causa problemas
		updateScoreBoard(e.score);
	}

	imprime(e);

	return 0;
}
