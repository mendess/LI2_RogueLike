//#define DEBUG

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "estado.h"
#include "path.h"
#include "parser.h"
#include "jogo.h"

/**
\brief Verifica se esta posição está em cima do caminho entre o heroi e a saida
@param e Estado do jogo
@param p Posição a verificar
@param pathSize Tamanho do caminho
@param path Array de posições do caminho
*/
int isOnPath(ESTADO e, POSICAO p, int pathSize, POSICAO path[]){ 
	int i, flag;
	flag=0;
	for (i=1;i<pathSize && !flag;i++){
		if (path[i].x == p.x && path[i].y == p.y){
			flag=1;
		}
	}
	return flag;
}
/**
\brief Verifica se esta algum monstro, pedra ou jogador na posição dada
@param e Estado do jogo
@param p Posição a verificar
*/
int pos_ocupada (ESTADO e, POSICAO p){
	return com_jogador(e,p) || com_pedras(e,p) || com_monstros(e,p);
}
/**
\brief Coloca uma pedra numa posição aleatoria válida
@param e Estado do jogo
@param pathSize Tamanho do caminho
@param path Caminho a evitar
*/
ESTADO colocar_pedra (ESTADO e, int pathSize, POSICAO path[]){
	POSICAO p;
	int placed=0, i=0;
	while(!placed && i<20){
		i++;
		int x=rand() % SIZE;
		int y=rand() % SIZE;
		p.x=(char) x;
		p.y=(char) y;
		if (!pos_ocupada(e,p) && !isOnPath(e,p,pathSize,path)){
			placed=1;
			e.pedras[(int) e.num_pedras].x=p.x;
			e.pedras[(int) e.num_pedras].y=p.y;
			e.num_pedras++;
		}
	}
	return e;
}
/**
\brief Coloca um monstro numa posição aleatoria válida
@param e Estado do jogo
*/
ESTADO colocar_monstro (ESTADO e){
	POSICAO p;
	int placed=0, i=0;
	while(!placed && i<20){
		i++;
		int x=rand() % SIZE;
		int y=rand() % SIZE;
		p.x=(char) x;
		p.y=(char) y;
		if (!pos_ocupada(e,p)){
			placed=1;
			e.monstros [(int) e.num_monstros].x=p.x;
			e.monstros [(int) e.num_monstros].y=p.y;
			e.num_monstros++;
		}
	}
	return e;
}
/**
\brief Coloca todas as pedras para inicializar o estado
@param e Estado do jogo
@param pathSize Tamanho do caminho a evitar
@param path Array de coordenadas do caminho a evitar
*/
ESTADO colocar_pedras (ESTADO e, int pathSize, POSICAO path[]){
	int i;
	for(i=0;i<MAX_PEDRAS;i++){
		e=colocar_pedra(e,pathSize,path);
	}
	return e;
}

/**
\brief Coloca todas os monstros para inicializar o estado
@param e Estado do jogo
*/
ESTADO colocar_monstros (ESTADO e){
	int i;
	for (i=0;i<MAX_MONSTROS;i++){
		e=colocar_monstro(e);
	}
	return e;
}
char getClassHp(char type){
	switch(type){
		case 0: return HP_WARRIOR;
		case 1: return HP_ARCHER;
		case 2: return HP_MAGE;
	}
	return -1;
}
char getClassMp(char type){
	switch(type){
		case 0: return MP_WARRIOR;
		case 1: return MP_ARCHER;
		case 2: return MP_MAGE;
	}
	return -1;
}
/**
\brief Inicializa o estado do jogo
*/
ESTADO inicializar(){

	ESTADO e;
	srandom(time(NULL));
	
	POSICAO path[MAX_CAMINHO];
	int n=pathMaker(path);
	
	e.action=0;

	e.direction=0;

	e.jog.x=path[0].x;
	e.jog.y=path[0].y;
	
	e.saida.x=path[n-1].x;
	e.saida.y=path[n-1].y;
	
	e.num_monstros=0;
	
	e.num_pedras=0;

	e=colocar_pedras(e,n,path);
	e=colocar_monstros(e);
	
	e.classe=0;
	e.hp=getClassHp(e.classe);
	e.mp=getClassMp(e.classe);
	e.world_lvl=0;
	e.score=0;
	e.turn=0;

	return e;
}
/**
\brief Verifica se o jogador esta num certo par de coordenadas
@param e Estado do jogo
@param p Posição a verificar
*/
int com_jogador (ESTADO e,POSICAO p){
	return (e.jog.x == p.x) && (e.jog.y == p.y);
}
/**
\brief Verifica se existem pedras nas coordenadas dadas
@param e Estado do jogo
@param p Posição a verificar
*/
int com_pedras (ESTADO e, POSICAO p){
	int i,flag;
	flag=0;
	for(i=0;i<MAX_PEDRAS && !flag;i++){
		if (e.pedras[i].x == p.x && e.pedras[i].y == p.y){
			flag=1;
		}
	}
	return flag;
}
/**
\brief Verifica se existem monstros nas coordenadas dadas
@param e Estado do jogo
@param p Posição a verificar
*/
int com_monstros (ESTADO e, POSICAO p){
	int i,flag;
	flag=0;
	for (i=0;i<MAX_MONSTROS && !flag;i++){
		if (e.monstros[i].x == p.x && e.monstros[i].y == p.y){
			flag=1;
		}
	}
	return flag;
}
/**
\brief Calcula a nova posição do jogador
@param jog A posição antiga do jogador
@param act Ação selecionada
*/
POSICAO calculaNovaPosicao(POSICAO jog, int act){
	switch(act){
		case 0: return jog;

		case 1: jog.x+=-1;
				jog.y+=1;
				return jog;

		case 2: jog.x+=0;
				jog.y+=1;
				return jog;

		case 3: jog.x+=1;
				jog.y+=1;
				return jog;

		case 4: jog.x+=-1;
				jog.y+=0;
				return jog;

		case 5: return jog;

		case 6: jog.x+=1;
				jog.y+=0;
				return jog;

		case 7: jog.x+=-1;
				jog.y+=-1;
				return jog;

		case 8: jog.x+=0;
				jog.y+=-1;
				return jog;

		case 9: jog.x+=1;
				jog.y+=-1;
				return jog;
	}
	return jog;
}
ESTADO calcularCombate(ESTADO e){
	return e;
}
ESTADO movemonstros(ESTADO e){
	return e;
}
/**
\brief Calcula um novo estado conforme a ação que esteja no estado que recebe
@param e Estado do jogo
*/
ESTADO calcularNovoEstado(ESTADO e){
	//saida
	if(e.action==5){
		return inicializar();
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
		return e;
	}
	if(e.action>10 && e.action>20){
		e=calcularCombate(e);
	}
	e=movemonstros(e);
	return e;
}
/**
\brief Verifica se tem de se criar um estado novo (QUERY_STRING vazia) 
	   ou se já existe ler a query e convertela no estado do jogo
@param args QUERY_STRING
*/
ESTADO ler_estado (char *args,FILE *gamestate){
	#ifdef DEBUG
	if(!args){
		return inicializar();
	}
	#endif
	#ifndef DEBUG
	if(strlen(args)==0){
		return inicializar();
	}
	#endif
	char str[MAX_BUFFER];
	int act;
	fscanf(gamestate,"%s",str);
	ESTADO e = str2estado(str);
	sscanf(args,"%d",&act);
	e.action = act;
	return e;
}
/**
\brief Main
*/
int main(){
	print_header();
	imprime_background();
	int x,y;
	POSICAO p;
	FILE *gamestateFile = fopen("gamestate","w+");
	ESTADO e;

	e = ler_estado(getenv("QUERY_STRING"),gamestateFile);
	e = calcularNovoEstado(e);

	srand(e.pedras[0].x);
	for(y = 0; y < SIZE; y++){
		for(x = 0; x < SIZE; x++){
			int r = rand() % 4;
			p.x= x;
			p.y= y;
			imprime_casa(r,p);
		}
	}

	imprime_saida(e.saida);
	imprime_monstros(e);
	imprime_pedras(e);
	imprime_jogador(e);

	print_footer();

	return 0;
}