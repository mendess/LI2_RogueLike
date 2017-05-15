#include <stdio.h>
#include "IA.h"
 //PEDRAS
int blocked1_ (ESTADO e,POSICAO p){
  int i,flag;
  flag=0;
  for(i=0;i<e.num_pedras;i++){
    if(e.pedras[i].x==p.x && e.pedras[i].y==p.y) flag=1;
  }
  return flag;
}
// MONSTROS
int blocked2_ (ESTADO e,POSICAO p){
  int i,flag;
  flag=0;
  for(i=0;i<e.num_monstros;i++){
    if(e.monstros[i].x==p.x && e.monstros[i].y==p.y) flag=1;
  }
  return flag;
}
int possivel_ (ESTADO e,POSICAO p){
  int flag;
  flag=1;
  if(blocked1_(e,p) || blocked2_(e,p)) flag=0;
  return flag;
}
 int impossivel_(ESTADO e,POSICAO pos){
   int i,flag=0;
   for(i=0;i<e.num_pedras;i++){
    if(!flag && pos.x==e.pedras[i].x && pos.y==e.pedras[i].y) flag=1;
   }
   for(i=0;i<e.num_monstros;i++){
    if(!flag && pos.x==e.monstros[i].x && pos.y==e.monstros[i].y) flag=1;
   }
   return flag;
}
POSICAO move_vertical(POSICAO atual,POSICAO alternativa){
  POSICAO pos=atual;
  int flag=1;
    if(atual.y>alternativa.y){
     pos.y--;
     flag=0;
    }
    if(atual.y<alternativa.y){
     pos.y++;
     flag=0;
    }
  if(flag && atual.y==alternativa.y){
    pos.x=alternativa.x;
  }
  atual=pos;
  return atual;
}
POSICAO distancia(ESTADO e,POSICAO pos){
  POSICAO p1,p2;
  int i;
  p1=p2=pos;
  for(i=0;impossivel_(e,p1) && impossivel_(e,p2);i++){
    p1.y++;
    p2.y--;
  }
  if(abs(pos.y-p1.y)>=abs(pos.y-p2.y)) pos=p2;
  else pos=p1;
  return pos;
}
POSICAO instrucoes(POSICAO pos,POSICAO intersect){
	int flag=1;
  if(intersect.x>pos.x){
    pos.x+=1;
    flag=0;
  } 
  if(intersect.x<pos.x){
  	pos.x+=-1;
  	flag=0;
  }
  if(flag && intersect.y>pos.y) pos.y+=1;
  if(flag && intersect.y<pos.y) pos.y+=-1;
  return pos;
}
// estado - pos monstro-pos intercecao
POSICAO tracker_chest (ESTADO e,POSICAO p, POSICAO intersect){
 POSICAO alternativa,caminho[25];
 int i=0;int alt;
 caminho[0].x=p.x;
 caminho[0].y=p.y;
 while(caminho[i].x != intersect.x || caminho[i].y != intersect.y){
  caminho[i+1]=instrucoes(caminho[i],intersect);
  i++;

 }
 for(i=0;caminho[i].x!=intersect.x || caminho[i].y!=intersect.y;i++){
    if(impossivel_(e,caminho[i])){
      alternativa=distancia(e,caminho[i]);// alternativa=(8,5)
      alt=i;
      while(caminho[alt-1].x!=alternativa.x || caminho[alt-1].y!=alternativa.y){
        caminho[alt]=move_vertical(caminho[alt-1],alternativa);
        alt++;
      } 
      while(caminho[alt-1].x!= intersect.x || caminho[alt-1].y != intersect.y){
          caminho[alt]=instrucoes(caminho[alt-1],intersect);
          alt++;
      }  // caminho certo
    }
 }
 return caminho[1];
}
POSICAO nearest_chest(ESTADO e,POSICAO p){
	POSICAO chest;
	int i,j,x,u;
	u=0;
 j=abs(p.x-e.chests[0].pos.x)+abs(p.y-e.chests[0].pos.y);
	for(i=1;i<e.num_chests;i++){
   x=abs(p.x-e.chests[i].pos.x)+abs(p.y-e.chests[i].pos.y);
   if(x<j){
   	j=x;
   	u=i;
   }
	}
 chest.x=e.chests[u].pos.x;
 chest.y=e.chests[u].pos.y;
 return chest;
}

ESTADO  track_chest(ESTADO e,int i,POSICAO p){
 POSICAO chest,nova_pos;
	chest=nearest_chest(e,p);
	nova_pos=tracker_chest(e,p,chest);
	e.monstros[i].x=nova_pos.x;
	e.monstros[i].y=nova_pos.y;
}
ESTADO defO(ESTADO e,POSICAO c,POSICAO m,int i){
	POSICAO pos;
	int flag=1;
 pos=m;
	if(e.jog.x<c.x && m.x>=c.x){
   pos.x-=1;
   if(possivel_(e,pos)){
   	e.monstros[i].x=pos.x;
   	flag=0;
   }
	}
	if(flag && e.jog.x>c.x && m.x<=c.x){
   pos.x+=1;
   if(possivel_(e,pos)){
   	e.monstros[i].x=pos.x;
   	flag=0;
   }
	}
	if(flag && e.jog.y>c.y && m.y<=c.y){
   pos.y+=1;
   if(possivel_(e,pos)){
   	e.monstros[i].y=pos.y;
   	flag=0;
   }
 }
 if(flag && e.jog.y<c.y && m.y>=c.y){
   pos.y-=1;
   if(possivel_(e,pos)){
   	e.monstros[i].y=pos.y;
   }
 }
 return e;
}

ESTADO protect_it(ESTADO e,int i,POSICAO pos_monst){
    POSICAO pos_chest;
    e=defO(e,pos_chest,pos_monst,i);
    return e;
}
int next2chest(ESTADO e,int i,POSICAO p){
	  int x,y;int flag=0;
	  POSICAO pos;
   for(x=-1;x<1;x++){
   	for(y=-1;y<1;y++){
   		pos.x=p.x+x;
   		pos.y=p.y+y;
  	  	if(e.chests[i].pos.x==pos.x && e.chests[i].pos.y==pos.y){
  	  		flag=1;
  	  	}
   	}
  }
  return flag;
}
ESTADO estrat_ogre (ESTADO e,int i,POSICAO p){
	int flag=1;
   if (existe_jogador(e,p)){
        e.hp+=-OGRE_DMG;
        flag==0;
   } 
   if(flag && next2chest(e,i,p)){
   	e=protect_it(e,i,p);
   }
   if(flag) e=track_chest(e,i,p);
   return e;
}