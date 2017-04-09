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
	return calcularNovoEstado(str2estado(args));
}
/**
\brief Main
*/
int main(){
	print_header();
	imprime_background();
	int x,y;
	POSICAO p;

	ESTADO e = ler_estado(getenv("QUERY_STRING"));

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