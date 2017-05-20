#include "levelMaker.h"

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
		int x=rand() % SIZE;
		int y=rand() % SIZE;
		i++;
		p.x=(char) x;
		p.y=(char) y;
		if (!pos_ocupada(e,p) && !isOnPath(p,pathSize,path)){
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
		int x=rand() % SIZE;
		int y=rand() % SIZE;
		i++;
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
		case 1: return HP_WARRIOR;
		case 2: return HP_ARCHER;
		case 3: return HP_MAGE;
	}
	return -1;
}
/*
\brief Retorna o mp inicial da classe dada como argumento
@param type O numero da classe
*/
char getClassMp(char type){
	switch(type){
		case 1: return MP_WARRIOR;
		case 2: return MP_ARCHER;
		case 3: return MP_MAGE;
	}
	return -1;
}

INVT initINVT(INVT bag){
	int i;
	i=0;
	bag.gold=0;
	for (i = 0; i < INVT_SIZE; ++i)
	{
		bag.inv[i]=0;
	}
	bag.weapon=0;
	bag.armour=0;
	return bag;
}