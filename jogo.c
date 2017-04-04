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
		e=colocar_pedra (e,pathSize,path);
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
/**
\brief Inicializa o estado do jogo
*/
ESTADO inicializar(){

	ESTADO e;

	POSICAO path[MAX_CAMINHO];
	int n=pathMaker(path);
	
	e.jog.x=path[0].x;
	e.jog.y=path[0].y;
	
	e.saida.x=path[n-1].x;
	e.saida.y=path[n-1].y;
	
	e.num_monstros=0;
	
	e.num_pedras=0;

	e=colocar_pedras(e,n,path);
	e=colocar_monstros(e);
	
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
\brief Verifica se tem de se criar um estado novo (QUERY_STRING vazia) 
	   ou se já existe ler a query e convertela no estado do jogo
@param args QUERY_STRING
*/
ESTADO ler_estado (char *args){
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
	return str2estado(args);
}
/**
\brief Main
*/
int main(){
	print_header ();
	imprime_background();
	srandom(time(NULL));
	int x,y;
	POSICAO p;

	ESTADO e = ler_estado(getenv("QUERY_STRING"));

	for(y = 0; y < SIZE; y++){
		for(x = 0; x < SIZE; x++){
			p.x= x;
			p.y= y;
			imprime_casa(p);
		}
	}

	imprime_saida(e.saida);
	imprime_monstros(e);
	imprime_pedras(e);
	imprime_jogador(e);

	print_footer();

	return 0;
}

//commentario para testar branching