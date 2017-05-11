#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jogo.h"
#include "move_monst.h"
#include "levelMaker.h"


int blocked0 (ESTADO e, POSICAO p){
  POSICAO p1,p2,p3,p4;
  int e1,e2,e3,e4,i;
  e1=e2=e3=e4=0;
  p1.x=p3.x=p.x;
  p2.y=p4.y= p.y;
  p2.x=p.x+1;
  p4.x=p.x-1;
  p1.y=p.y+1;
  p3.y=p.y-1;
  for (i=0;i<MAX_PEDRAS;i++){
     if(p1.x==e.pedras[i].x && p1.y==e.pedras[i].y) e1=1;
     if(p2.x==e.pedras[i].x && p2.y==e.pedras[i].y) e2=1;
     if(p3.x==e.pedras[i].x && p3.y==e.pedras[i].y) e3=1;
     if(p4.x==e.pedras[i].x && p4.y==e.pedras[i].y) e4=1;
   }
  return (e1 && e2 && e3 && e4);
}

int blocked1 (ESTADO e, POSICAO p){
  POSICAO p1;
  int u,i;
  u=1;
  for ((p1.x)=(p.x-1);(p1.x)<=(p.x+1);(p1.x)++){
    for((p1.y)=(p.y-1);p1.y<p.y+1;p1.y++){
      for (i=0;i<MAX_PEDRAS;i++){
        if (p1.x==e.pedras[i].x && p1.y== e.pedras[i].y) u=0;
      }
    }
  }
  return u; 
}

int outOfBounds(POSICAO p){
	if (p.x<0 || p.x>= SIZE || p.y<0 || p.y>=SIZE){
		return 1;
	}
	return 0;
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
	return flag;
}

int pos_ocupada (ESTADO e, POSICAO p){
	return com_jogador(e,p) || com_pedras(e,p) || com_monstros(e,p);
}

int poslivre(ESTADO e, POSICAO p){
    int flag=1; 
	if (com_jogador(e,p) || com_monstros(e,p)) flag=0;
	return flag;
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

int ve_jogador (ESTADO e,POSICAO p){
	int p1,p2;
	p1=abs(p.x-e.jog.x);
	p2=abs(p.y-e.jog.y);
   if (p1+p2 <= 3) return 1;
   return 0;
}

ESTADO mov_bat(ESTADO e,int i,POSICAO p){
    int q,w,flag;
    POSICAO p1;
    flag=1;
    q= (rand () % 3)-1;
    w= (rand () % 3)-1;
    p1.x=p.x+q;
    p1.y=p.y+w;
    if ( flag && poslivre(e,p1) && !outOfBounds(p1)){
       e.monstros[i].x=p1.x;
       e.monstros[i].y=p1.y;
       flag=0;
     }
    return e;
 }

ESTADO mov_ogre(ESTADO e,int i,POSICAO p){
	int q,w,flag;
    POSICAO p1;
    w=0; flag=1;
    q= (rand () % 3)-1;
    if (existe_jogador(e,p)){
    	e.hp-=OGRE_DMG;
    	flag=0;
    }
    if (blocked0(e,p)) 
        flag=0;
    if (q==0) 
        w=(rand () % 3)-1;
    p1.x=p.x+q;
    p1.y=p.y+w;    
    if (flag && !pos_ocupada(e,p1) && !outOfBounds(p1)){
    	e.monstros[i].x=p1.x;
        e.monstros[i].y=p1.y;
        e.monstros[i].monType=3;
        flag=0;
    }
    return e;
}

ESTADO mov_archer(ESTADO e,int i,POSICAO p){
	int q,w,flag;
    POSICAO p1;
    w=0; flag=1;
	q=(rand () % 3)-1;
	if (ve_jogador(e,p)){
        e.hp-=ARCHER_DMG;
    	flag=0;
    }
    if (blocked0(e,p)) 
        flag=0;
    if (q==0)
    	w=(rand () % 3)-1;
    p1.x=p.x+q;
    p1.y=p.y+w;
     if (!pos_ocupada(e,p1) && flag && !outOfBounds(p1)){
    	e.monstros[i].x=p1.x;
        e.monstros[i].y=p1.y;
		flag=0;
    }
    return e;
}

ESTADO mov_wolf (ESTADO e,int i,POSICAO p){
	int q,w,flag;
    POSICAO p1;
	flag=1;
	q=(rand () % 3)-1;
    w=(rand () % 3)-1;
    p1.x=p.x+q;
    p1.y=p.y+w;
	if (existe_jogador(e,p)){
		e.hp-=WOLF_DMG;
	    flag=0;
	}
    if (flag && blocked1(e,p)) flag=0;
	if (flag && !pos_ocupada(e,p1) && !outOfBounds(p1)){
		e.monstros[i].x=p1.x;
        e.monstros[i].y=p1.y;
		flag=0;
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
   srandom(time(NULL));
   e.pedras[1].x=3;
   e.pedras[1].y=5; 
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
