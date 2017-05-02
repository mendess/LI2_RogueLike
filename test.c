#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jogo.h"
#include "move_monst.h" 
#include "levelMaker.h"
#include "parser.h"

/*
int blocked1 (ESTADO e, POSICAO p){
  POSICAO p1;
  int u,i;
  u=1;
  for ((p1.x)=(p.x-1);(p1.x)<=(p.x+1);(p1.x)++){
    for((p1.y)=(p.y-1);(p1.y)<=(p.y+1);p1.y++){
      for (i=0;i<MAX_PEDRAS;i++){
        if (p1.x==e.pedras[i].x && p1.y== e.pedras[i].y) u=0;
      }
    }
  }
  return u; 
}


int com_jogador (ESTADO e,POSICAO p){
	return (e.jog.x == p.x) && (e.jog.y == p.y);
}


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

int com_pedras (ESTADO e, POSICAO p){
	int i,flag;
	flag=0;
	for(i=0;i<MAX_PEDRAS && !flag;i++){
		if (e.pedras[i].x == p.x && e.pedras[i].y == p.y){
			flag=1;
		}
	}
}
int existe_jogador(ESTADO e,POSICAO p){
   int q,w;
   for(q=-1;q<=1;q++){
   	for(w=-1;w<=1;w++){
   		if (e.jog.x==p.x+q && e.jog.y == p.y+w) return 1;
   	}
   }
   return 0;
}

int poslivre(ESTADO e, POSICAO p){
    int flag=1; 
	if (com_monstros(e,p)) flag=0;
	return flag;
}
int outOfBounds(POSICAO p){
	if (p.x<0 || p.x>= SIZE || p.y<0 || p.y>=SIZE){
		return 1;
	}
	return 0;
}
*/
int com_jogador (ESTADO e,POSICAO p){
    int flag=0;
	if((e.jog.x == p.x) && (e.jog.y == p.y)) flag=1;
    return flag;
}


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

int inBounds(POSICAO p){
	if (p.x>=0 || p.x< SIZE || p.y>=0 || p.y<SIZE){
		return 1;
	}
	return 0;
}

int pos_ocupada (ESTADO e, POSICAO p){
	return (com_jogador(e,p) || com_pedras(e,p) || com_monstros(e,p));
}


// recebo estado para alterar, e posição original.
ESTADO mov_wolf (ESTADO e,int i,POSICAO p){
	int q,w;
    POSICAO p1;
     srandom(time(NULL));
    do{
    q=(rand () % 3) -1;
    w=(rand () % 3) -1;
    }while(q==0 && w==0);
    p1.x=p.x+q;
    p1.y=p.y+w;
    if (pos_ocupada(e,p1)==0 ){
      e.monstros[i].x=p1.x;
      e.monstros[i].y=p1.y;
    }
    return e;
}

ESTADO criaestado(ESTADO e){
  int i,q,w;
  for (i=0;i<10;i++){
    q=rand () % 10;
    w=rand () % 10;
    e.monstros[i].x=q;
    e.monstros[i].y=w;
    e.monstros[i].monType=1;
    e.monstros[i].hp=30;
  }
  e.jog.x=7;
  e.jog.y=7;
  return e;
}

int main (){
   int i,q;
   ESTADO e,n;
   POSICAO p;
   srandom(time(NULL));
   e=criaestado(e);
   for(q=0;q<10;q++){
     printf("(%d,%d,%d,%d)",e.monstros[q].x,e.monstros[q].y,e.monstros[q].monType,e.monstros[q].hp);
   }
   // não desaparece nada até aqui.
   e.hp=50;
   printf("  hp:%d\n",e.hp); 
   for (i=0;i<10;i++){
      p.x=e.monstros[i].x;
      p.y=e.monstros[i].y;
      n=mov_wolf(e,i,p);
      printf("(%d,%d,%d,%d)",n.monstros[i].x,n.monstros[i].y,n.monstros[i].monType,n.monstros[i].hp);
      e=n;	
   }
   printf("%d", n.hp);
   return 0;
}
