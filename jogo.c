//#define DEBUG

#include "estado.h"
#include "path.h"
#include "parser.h"
#include "score.h"
#include "levelMaker.h"
#include "move_monst.h"
#include "jogo.h"
/**
\brief Inicializa o estado do jogo
*/
ESTADO inicializar(){

	ESTADO e;
	POSICAO path[MAX_CAMINHO];
	int n=pathMaker(path);
	srandom(time(NULL));
	//Classe {Warrior=0, Archer=1, Mage=2}
	e.classe=0;
	//Vida do jogador
	e.hp=getClassHp(e.classe);
	//Mana do jogador
	e.mp=getClassMp(e.classe);
	//Nivel
	e.world_lvl=0;
	//Score
	e.score=0;
	//Turno
	e.turn=0;
	//Lado para que o jogador esta a olhar 0:direita e 1:esquerda
	e.direction=0;
	//Action
	e.action=0;
	// Posição do jogador
	e.jog.x=path[0].x;
	e.jog.y=path[0].y;
	// Posição da saida
	e.saida.x=path[n-1].x;
	e.saida.y=path[n-1].y;
	// Numero de Monstros
	e.num_monstros=0;
	// Numero de pedras
	e.num_pedras=0;
	// Posições da pedras
	e=colocar_pedras(e,n,path);
	// Posições dos monstros
	e=colocar_monstros(e);

	return e;
}
ESTADO newLevel(ESTADO e){

	POSICAO path[MAX_CAMINHO];
	int n=pathMaker(path);
	srandom(time(NULL));
	//Vida do jogador
	if(e.hp>(getClassHp(e.classe)-NEW_LEVEL_HP_BONUS)){
		e.hp=getClassHp(e.classe);
	}else{
		e.hp+=NEW_LEVEL_HP_BONUS;
	}
	//Mana do jogador
	if(e.mp>(getClassMp(e.classe)-NEW_LEVEL_MP_BONUS)){
		e.mp=getClassMp(e.classe);
	}else{
		e.mp+=NEW_LEVEL_MP_BONUS;
	}
	//Nivel
	e.world_lvl+=1;
	//Score
	e.score+=NEW_LEVEL_SC_BONUS;
	//Turno
	e.turn=0;
	//Lado para que o jogador esta a olhar 0:direita e 1:esquerda
	e.direction=0;
	//Action
	e.action=0;
	// Posição do jogador
	e.jog.x=path[0].x;
	e.jog.y=path[0].y;
	// Posição da saida
	e.saida.x=path[n-1].x;
	e.saida.y=path[n-1].y;
	// Numero de Monstros
	e.num_monstros=0;
	// Numero de pedras
	e.num_pedras=0;
	// Posições da pedras
	e=colocar_pedras(e,n,path);
	// Posições dos monstros
	e=colocar_monstros(e);

	return e;
}
/**
\brief Calcula a nova posição do jogador
@param jog A posição antiga do jogador
@param act Ação selecionada
*/
POSICAO calculaNovaPosicao(POSICAO jog, int act){
	int x[10]={5,-1, 0, 1,-1, 5, 1,-1, 0, 1};
//             0  1  2  3  4  5  6  7  8  9
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
/*ESTADO movemonstros(ESTADO e){
	return e;
}*/
/**
\brief Calcula um novo estado conforme a ação que esteja no estado que recebe
@param e Estado do jogo
*/
ESTADO calcularNovoEstado(ESTADO e){
	//saida
	if(e.action==5){
		return newLevel(e);
	}
	//set direction
	if(e.action==9 || e.action==6 || e.action==3){
		e.direction=0;
	}
	if(e.action==7 || e.action==4 || e.action==1){
		e.direction=1;
	}
	if(e.action>0 && e.action<10){
		e.jog=calculaNovaPosicao(e.jog,e.action);
	}
	if(e.action>10 && e.action>20){
		e=calcularCombate(e);
	}

	e=move_monstros(e);

	e.turn+=1;

	return e;
}
/**
\brief Verifica se tem de se criar um estado novo (QUERY_STRING vazia)
	   ou se já existe ler a query e convertela no estado do jogo
@param args QUERY_STRING
*/
ESTADO ler_estado (char *args,FILE *gamestateFile){
	char str[MAX_BUFFER];
	int act;
	fscanf(gamestateFile,"%s",str);
	ESTADO e = str2estado(str);
	sscanf(args,"%d",&act);
	e.action = act;
	return e;
}
ESTADO runGame(){
	char *args = getenv("QUERY_STRING");
	FILE *gamestateFile;
	ESTADO e;

	if(strlen(args)==0){
		#ifdef DEBUG
		gamestateFile = fopen("gamestate","w");
		#else
		gamestateFile = fopen("/tmp/gamestate","w");
		#endif
		e = inicializar();
	}else{
		#ifdef DEBUG
		gamestateFile = fopen("gamestate","r+");
		#else
		gamestateFile = fopen("/tmp/gamestate","r+");
		#endif
		e = ler_estado(args,gamestateFile);
		e = calcularNovoEstado(e);
		#ifdef DEBUG
		gamestateFile = freopen("gamestate","w",gamestateFile);
		#else
		gamestateFile = freopen("/tmp/gamestate","w",gamestateFile);
		#endif
	}
	fprintf(gamestateFile,"%s",estado2str(e));
	fclose(gamestateFile);
	return e;
}

/**
\brief Main
*/
int main(){
  
	ESTADO e = runGame();
	if(e.hp<=0){
		updateScoreBoard(e.score);
	}

	imprime(e);

	return 0;
}
