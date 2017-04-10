#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
# include "jogo.h"

// ataca_jogador
//existe_jogador (estado, pos monstro)

// estado -> turn (nº de jogadas)
// mover montros
int posocupada3(ESTADO e, int p.x, int p.y){
	if (com_jogador(e,p) || com_monstro(e,p)) return 0;
	return 1;
}

int posocupada2(ESTADO e, int p.x, int p.y){
	if (posocupada(e,p)) return 0;
	return 1;
}
int mov_bat(Estado e,int i,POS p){
    int q,flag;
    flag=1;
	q= rand () % 7;
	if (q=0 && posocupada3(e,p.x+1,p.y)) {
        e.monstros[i].x+=1;
	  	flag=0;
	}
	if (q=1 && posocupada3(e,p.x+1,p.y+1)) {
		e.monstros[i].x+=1;
		e.monstros[i].y+=1;
		flag=0;
	}
	if (q=2 && posocupada3(e,p.x+1,p.y-1)) {
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
	if (existe_jogador(e,p)){
		ataca_jogador(e);
		flag=0;
	}
	return flag;

}
int mov_ogre(Estado e,int i,POS p){
	int q,flag;
	flag=1;
    q= rand () % 3;
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
    if (existe_jogador(e,p)){
    	ataca_jogador(e);
    	flag=0;
    }
    return flag;


}
// ataca se a dferença de posições for de 3 quadriculas x+y <=3
int mov_archer(Estado e,int i,POS p){
	int q,flag;
	flag=1;
	 q=rand () % 3;
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
    if (ve_jogador(e,p)){
    	ataca_jogador(e);
    	flag=0;
    }
    return flag;

}
int mov_wolf (ESTADO e,int i,POS p){
	int q,flag;
	flag=1;
	q=rand () % 7;
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
	if (existe_jogador(e,p)){
		ataca_jogador(e);
		flag=0;
	}
	return flag;
}
 // (pos1,pos2,tipo,dano,hp) ->(x,y,z,d,v)
void move_monstros (ESTADO e){
   int i;
   for (i=0;i<MAX_MONSTROS;i++){
   	POS p;
	p.x=e.monstros[i].x;
    p.y=e-monstros[i].y;
    srandom(time(NULL));
   	if(e.monstros[i].z == 1){
   		if(mov_bat(e,i,p)) i--;
   	}
   	if(e.monstros[i].z == 2){
   		if(mov_wolf(e,i,p)) i--;
   	} 
    if(e.monstros[i].z == 3){
   		if(mov_ogre(e,i,p)) i--;
   	}
   	if(e.monstros[i].z == 4){
   		if(mov_archer(e,i,p)) i--;
   	}
   }
 
}

int main(){
  ESTADO e;
  int i;
  move_monstros(e,i);
  return 1;
}  




