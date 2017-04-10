#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jogo.h"
#include "movemonstros.h" 

// ataca_jogador
//existe_jogador (estado, pos monstro)

// estado -> turn (nº de jogadas)
// mover montros
int posocupada3(ESTADO e, int q, int w){
	POSICAO p;
	p.x=q;
	p.y=w;
	if (com_jogador(e,p) || com_monstro(e,p)) return 0;
	return 1;
}

int posocupada2(ESTADO e, int q, int w){
	POSICAO p;
	p.x=q;
	p.y=w;
	if (posocupada(e,p)) return 0;
	return 1;
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

int  ve_jogador (ESTADO e,POSICAO p){
	int p1,p2;
	p1=abs(p.x-e.jog.x);
	p2=abs(p.y-e.jog.y);
   if (p1+p2 <= 3) return 1;
   return 0;
}

int mov_bat(Estado e,int i,POSICAO p){
    int q,flag;
    flag=1;
	q= rand () % 7;
	if (existe_jogador(e,p)){
		ataca_jogador(e,BAT_DMG);
		return 0;
	}
	if (q=0 && posocupada3(e,p.x+1,p.y) && flag) {
        e.monstros[i].x+=1;
	  	flag=0;
	}
	if (q=1 && posocupada3(e,p.x+1,p.y+1)&& flag) {
		e.monstros[i].x+=1;
		e.monstros[i].y+=1;
		flag=0;
	}
	if (q=2 && posocupada3(e,p.x+1,p.y-1) && flag) {
		e.monstros[i].x+=1;
   		e.monstros[i].y-=1;
	   	flag=0; 
	}
	if (q=3 && posocupada3(e,p.x,p.y+1)) {
		e.monstros[i].y+=1;
    	flag=0;
	}
	if (q=4 && posocupada3(e,p.x,p.y-1)) {
		e.monstros[i].y-=1;
	   	flag=0;
	}
	if (q=5 &&posocupada3(e,p.x-1,p.y)) {
		e.monstros[i].x-=1;
	   	flag=0;
	}
	if (q=6 && posocupada3(e,p.x-1,p.y+1)) {
		e.monstros[i].x-=1;
	    e.monstros[i].y+=1;
    	flag=0;
	}
	if (q==7 && posocupada3(e,p.x-1,p.y-1)){
    	e.monstros[i].x-=1;
		e.monstros[i].y-=1;
		flag=0;
	}
	return flag;

}
int mov_ogre(Estado e,int i,POSICAO p){
	int q,flag;
	flag=1;
    q= rand () % 3;
    if (existe_jogador(e,p)){
    	ataca_jogador(e,OGRE_DMG);
    	return 0;
    }
    if (q=0 && posocupada2(e,p)){
    	e.monstros[i].x+=1;
		flag=0;
    }
     if (q=1 && posocupada2(e,p)){
    	e.monstros[i].y+=1;
		flag=0;
    }
     if (q=2 && posocupada2(e,p)){
    	e.monstros[i].x-=1;
		flag=0;
    }
     if (q=3 && posocupada2(e,p)){
    	e.monstros[i].y-=1;
		flag=0;
    }
    return flag;
}
// ataca se a dferença de posições for de 3 quadriculas x+y <=3
int mov_archer(Estado e,int i,POSICAO p){
	int q,flag;
	flag=1;
	q=rand () % 3;
	if (ve_jogador(e,p)){
        ataca_jogador(e,ARCHER_DMG);
    	return 0;
    }
    if (q=0 && posocupada2(e,p.x)){
    	e.monstros[i].x+=1;
		flag=0;
    }
     if (q=1 && posocupada2(e,p)){
    	e.monstros[i].y+=1;
		flag=0;
    }
     if (q=2 && posocupada2(e,p)){
    	e.monstros[i].x-=1;
		flag=0;
    }
     if (q=3 && posocupada2(e,p)){
    	e.monstros[i].y-=1;
		flag=0;
    }
    return flag;

}
int mov_wolf (ESTADO e,int i,POSICAO p){
	int q,flag;
	flag=1;
	q=rand () % 7;
	if (existe_jogador(e,p)){
		ataca_jogador(e,WOLF_DMG);
		return 0;
	}
	if (q==0 && posocupada2(e,p.x+1,p.y)){
		e.monstros[i].x+=1;
		flag=0;
	}
	if (q==1 && posocupada2(e,p.x+1,p.y+1)){
		e.monstros[i].x+=1;
		e.monstros[i].y+=1;
		flag=0;
	}
	if (q==2 && posocupada2(e,p.x+1,p.y-1)){
		e.monstros[i].x+=1;
		e.monstros[i].y-=1;
		flag=0;
	}
	if (q==3 && posocupada2(e,p.x,p.y+1)){
		e.monstros[i].y+=1;
		flag=0;
	}
	if (q==4 && posocupada2(e,p.x,p.y-1)){
		e.monstros[i].y-=1;
		flag=0;
	}
	if (q==5 && posocupada2(e,p.x-1,p.y)){
		e.monstros[i].x-=1;
		flag=0;
	}
	if (q==6 && posocupada2(e,p.x-1,p.y+1)){
		e.monstros[i].x-=1;
		e.monstros[i].y+=1;
		flag=0;
	}
	if (q==7 && posocupada2(e,p.x-1,p.y-1)){
		e.monstros[i].x-=1;
		e.monstros[i].y-=1;
		flag=0;
	}
	return flag;
}
 // (pos1,pos2,tipo,dano,hp) ->(x,y,z,d,v)
void move_monstros (ESTADO e){
   int i;
   for (i=0;i<MAX_MONSTROS;i++){
   	POSICAO p;
	p.x=e.monstros[i].x;
    p.y=e.monstros[i].y;
    srandom(time(NULL));
   	if(e.monstros[i].monType == 1){
   		if(mov_bat(e,i,p)) i--;
   	}
   	if(e.monstros[i].monType == 2){
   		if(mov_wolf(e,i,p)) i--;
   	} 
    if(e.monstros[i].monType == 3 && (e.turn%2 == 0){
   		if(mov_ogre(e,i,p)) i--;
   	}
   	if(e.monstros[i].monType == 4){
   		if(mov_archer(e,i,p)) i--;
   	}
  }
}
 

  




