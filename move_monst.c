#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jogo.h"
#include "move_monst.h" 
#include "levelMaker.h"
#include "parser.h"

// ataca_jogador
//existe_jogador (estado, pos monstro)

// estado -> turn (nº de jogadas)
// mover montros
int poslivre(ESTADO e, POSICAO p){
    int flag=1; 
	if (com_jogador(e,p) || com_monstros(e,p)) flag=0;
	return flag;
}
void ataca_jogador(ESTADO e,int i){
	e.hp-=i;
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
// impede que os monstros presos ao procurarem mover-se entrem em ciclos infinitos
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
// indica se há posições livres para o monstro se mover.
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
	if (existe_jogador(e,p)){
		e.hp-=BAT_DMG;
		flag=0;
	}
    if (flag && poslivre(e,p1) && !outOfBounds(p1)){
       e.monstros[i].x+=q;
       e.monstros[i].y+=w;
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
    if (flag && !pos_ocupada(e,p1)){
    	e.monstros[i].x+=q;
        e.monstros[i].y+=w;
        flag=0;
    }
    return e;
}
// ataca se a dferença de posições for de 3 quadriculas x+y <=3

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
     if (!pos_ocupada(e,p1) && flag){
    	e.monstros[i].y+=q;
        e.monstros[i].y+=w;
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
    p1.y=p.x+w;
	if (existe_jogador(e,p)){
		e.hp-=WOLF_DMG;
	    flag=0;
	}
    if (blocked1(e,p)) flag=0;
	if (!pos_ocupada(e,p1) && flag){
		e.monstros[i].x+=q;
        e.monstros[i].y+=w;
		flag=0;
	}
	return e;
}
// (pos1,pos2,tipo,hp) ->(x,y,z,d,v)
ESTADO move_monstros (ESTADO e){
   ESTADO n=e;
   int i;
   for (i=0;i<MAX_MONSTROS;i++){
   	POSICAO p;
	p.x=e.monstros[i].x;
    p.y=e.monstros[i].y;
    srandom(time(NULL));
   	if(e.monstros[i].monType == 1){
   	   mov_bat(e,i,p);
   	}
   	if(e.monstros[i].monType == 2){
   	   mov_wolf(e,i,p);
   	} 

    if(e.monstros[i].monType == 3 && (e.turn%2 == 0)){
   		mov_ogre(e,i,p);
   	}
   	if(e.monstros[i].monType == 4){
   		mov_archer(e,i,p);
   	}
    e=n;
  }
  return e;
}
