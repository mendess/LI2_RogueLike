#include "colisions.h"

/**
\brief Verifica se um par de coordenadas esta fora dos limites do mapa
@param p Posição a verficar
*/
int outOfBounds(POSICAO p){
	return p.x<0 || p.x>= SIZE || p.y<0 || p.y>=SIZE;
}
/**
\brief Verifica se esta posição está em cima do caminho entre o heroi e a saida
@param e Estado do jogo
@param p Posição a verificar
@param pathSize Tamanho do caminho
@param path Array de posições do caminho
*/
int isOnPath(POSICAO p, int pathSize, POSICAO path[]){ 
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
\brief Verifica se a saida esta num certo par de coordenadas
@param e Estado do jogo
@param p Posição a verificar
*/
int com_saida (ESTADO e, POSICAO p){
	return (e.saida.x==p.x) && (e.saida.y==p.y);
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
	for(i=0;i<e.num_pedras && !flag;i++){
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
	for (i=0;i<e.num_monstros && !flag;i++){
		if (e.monstros[i].x == p.x && e.monstros[i].y == p.y){
			flag=1;
		}
	}
	return flag;
}
/**
\brief Verifica se existem chests nas coordenadas dadas
@param e Estado do jogo
@param p Posição a verificar
*/
int com_chest(ESTADO e, POSICAO p){
	int i,flag;
	flag=0;
	for(i=0;i<e.num_chests && !flag;i++){
		if(e.chests[i].pos.x == p.x && e.chests[i].pos.y == p.y){
			flag=1;
		}
	}
	return flag;
}
int isBoss(ESTADO e, POSICAO p){
	return (e.isInBossBattle &&
			p.x>=e.monstros[0].x && p.x<=e.monstros[0].x+3 &&
			p.y>=e.monstros[0].y && p.y<=e.monstros[0].y+2   );
}