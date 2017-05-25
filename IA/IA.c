#include "IA.h"

// ataca_jogador
//existe_jogador (estado, pos monstro)

// estado -> turn (nº de jogadas)
// mover montros

int inBounds(POSICAO p){
	if (p.x>0 && p.x< SIZE && p.y>0 && p.y<SIZE){
		return 1;
	}
	return 0;
}
int poslivre(ESTADO e, POSICAO p){
	int flag=1;
	if (com_monstros(e,p)) flag=0;
	return flag;
}
void ataca_jogador(ESTADO e,int i){
	e.hp-=i;
}
int existe_jogador(ESTADO e,POSICAO p){
	int flag=0;
	if (abs(e.jog.x-p.x)<=1 && abs(e.jog.y-p.y)<=1) flag=1;
	return flag;
}
/*
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
*/
int ve_jogador (ESTADO e,POSICAO p){
	int p1,p2;
	p1=abs(p.x-e.jog.x);
	p2=abs(p.y-e.jog.y);
	if (p1+p2 <= 3) return 1;
	return 0;
}
ESTADO mov_bat(ESTADO e,int i,POSICAO p){
	int q,w;
		POSICAO p1;
		srandom(time(NULL));
		do{
			q=(rand () % 3) -1;
			w=(rand () % 3) -1;
		}while(q==0 && w==0);
			p1.x=p.x+q;
			p1.y=p.y+w;
		if (!pos_ocupada(e,p1) && inBounds(p1)){
			e.monstros[i].x=p1.x;
			e.monstros[i].y=p1.y;
		}
		return e;
}
ESTADO mov_ogre(ESTADO e,int i,POSICAO p){
	int q,w;
	POSICAO p1;
	do{
		q=(rand () % 3) -1;
		w=(rand () % 3) -1;
	}while((q==0 && w==0) || (q!=0 && w!=0));
	p1.x=p.x+q;
	p1.y=p.y+w;
	if (!pos_ocupada(e,p1) && inBounds(p1)){
		e.monstros[i].x=p1.x;
		e.monstros[i].y=p1.y;
	}
	return e;
}
// ataca se a dferença de posições for de 3 quadriculas x+y <=3
ESTADO mov_archer(ESTADO e,int i,POSICAO p){
	int q,w;
	POSICAO p1;
	w=0;
	q=(rand () % 3)-1;
	if (q==0)
		w=(rand () % 3)-1;
	p1.x=p.x+q;
	p1.y=p.y+w;
	if (!pos_ocupada(e,p1) && inBounds(p1)){
		e.monstros[i].x=p1.x;
		e.monstros[i].y=p1.y;
	}
	return e;
}
ESTADO mov_wolf (ESTADO e,int i,POSICAO p){
	int q,w;
	POSICAO p1;
	do{
		q=(rand () % 3) -1;
		w=(rand () % 3) -1;
	}while(q==0 && w==0);
	p1.x=p.x+q;
	p1.y=p.y+w;
	if (!pos_ocupada(e,p1) && inBounds(p1)){
		e.monstros[i].x=p1.x;
		e.monstros[i].y=p1.y;
	}
	return e;
}
ESTADO acao_bat(ESTADO e, int i, POSICAO p){
	int flag=1;
	if (existe_jogador(e,p)){
		e.hp-=BAT_DMG;
		flag=0;
	}
	if(flag){
		e=mov_bat(e,i,p);
	}
	return e;
}
ESTADO acao_wolf (ESTADO e,int i, POSICAO p){
	int flag=1;
	if (existe_jogador(e,p)){
		e.hp-=WOLF_DMG;
		flag=0;
	}
	if(flag){
		e=mov_wolf(e,i,p);
	}
	return e;
}
ESTADO acao_ogre(ESTADO e,int i,POSICAO p){
	int flag=1;
	if (existe_jogador(e,p)){
		e.hp-=OGRE_DMG;
		flag=0;
	}
	if(flag){
		e=mov_ogre(e,i,p);
	}
	return e;
}
ESTADO acao_archer(ESTADO e, int i, POSICAO p){
	int flag=1;
	if (ve_jogador(e,p)){
		e.hp-=ARCHER_DMG;
		flag=0;
	}
	if(flag){
		e=mov_archer(e,i,p);
	}
	return e;
}
// certo devolve 2 monstros
POSICAO quemAtaca(ESTADO e){
  POSICAO w;
  int i,j,i1,i2;
  w.x=10;
  w.y=10;
  i1=1;i2=0;
  for (i=0;i<e.num_monstros;i++){
     j=abs(e.monstros[i].x-e.jog.x) + abs(e.monstros[i].y-e.jog.y);
     if(e.monstros[i].monType==4) j-=3;
     if (j<=w.x && w.x>=w.y){
       w.x=j;
       i1=i;
     }
      if (w.x != j && j<w.y && w.y>=w.x){
       w.y=j;
       i2=i;
     }
  }
  w.x=i1;
  w.y=i2;
  return w;
}
ESTADO iaMoves (ESTADO e,int i){
  POSICAO p;
  int flag=1;
  p.x=e.monstros[i].x;
  p.y=e.monstros[i].y;
  if(e.monstros[i].monType == 0 && flag){
     e=estrat_wolf(e,i,p);
  }
  if(e.monstros[i].monType == 1  && flag){
     e=estrat_bat(e,i,p);
 	} 
  if(e.monstros[i].monType == 2 && (e.turn%2 == 0) && flag){
     e=estrat_ogre(e,i,p);
  }
  if(e.monstros[i].monType == 3 && flag){
     e=estrat_archer(e,i,p);
  }
  return e;
}
ESTADO move_monstros (ESTADO e){
   POSICAO p,q;
   int i;
   q=quemAtaca(e);
   srandom(time(NULL));
   for (i=0;i<e.num_monstros;i++){
        if(i==q.x || i== q.y){
           e=iaMoves(e,i);
        }
        if(i!=q.x && i!= q.y){
          p.x=e.monstros[i].x;
          p.y=e.monstros[i].y;
          if(e.monstros[i].monType == 0){
            e=acao_wolf(e,i,p);
          }
        	if(e.monstros[i].monType == 1){//por wolf
            e=acao_bat(e,i,p);
        	} 
         if(e.monstros[i].monType == 2 && (e.turn%2 == 0)){
   	    	  e=acao_ogre(e,i,p);
         }
         if(e.monstros[i].monType == 3){// por archer
            e=acao_archer(e,i,p);
         }
        }
  }
  return e;
}
