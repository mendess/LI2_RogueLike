#include "levelMaker.h"

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
			e.monstros [(int) e.num_monstros].monType=1;
			e.monstros [(int) e.num_monstros].hp=30;
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
/*
\brief Retorna o hp inicial da classe dada como argumento
@param type O numero da classe
*/
char getClassHp(char type){
	switch(type){
		case 0: return HP_WARRIOR;
		case 1: return HP_ARCHER;
		case 2: return HP_MAGE;
	}
	return -1;
}
/*
\brief Retorna o mp inicial da classe dada como argumento
@param type O numero da classe
*/
char getClassMp(char type){
	switch(type){
		case 0: return MP_WARRIOR;
		case 1: return MP_ARCHER;
		case 2: return MP_MAGE;
	}
	return -1;
}