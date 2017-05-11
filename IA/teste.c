#include "jogo.h"

int existe_jogador(ESTADO e,POSICAO p){
  int q,w;
  for(q=-1;q<=1;q++){
    for(w=-1;w<=1;w++){
      if (e.jog.x==p.x+q && e.jog.y == p.y+w) return 1;
    }
  }
  return 0;
}

ESTADO defB (ESTADO e,POSICAO p,int num){
  POSICAO intersect;
  intersect= mapa3(e,p,num);
  e=estrat_bat1(e,i,intersect);
  return e;
}
ESTADO estrat_bat(ESTADO e,int i,POSICAO p){
   int flag=1;;
   if (existe_jogador(e,p)){
        e.hp-=BAT_DMG;
      flag=0;
   } // J M →ŧ
   if(flag && e.jog.x<=p.x && e.jog.y>=p.y && e.saida.x>=e.jog.x && e.saida.y<=e.jog.y){
     e=defB(e,p,1);
     flag=0;
   } // J M←ŧ
   /*
   if(flag && e.jog.x>=p.x && e.jog.y>=p.y && e.saida.x<=e.jog.x && e.saida.y<=e.jog.y){
     e= defB(e,i,p,2);
     flag=0;
   } // J M←↓
   if(flag && e.jog.x>=p.x && e.jog.y<=p.y && e.saida.x<=e.jog.x && e.saida.y>=e.jog.y){
     e=defB(e,i,p,3);
     flag=0;
   } // J M→↓
   if(flag && e.jog.x<=p.x && e.jog.y<=p.y && e.saida.x>=e.jog.x && e.saida.y>=e.jog.y){
     e=defB(e,i,p,4);
     flag=0;
   }
   if(flag) e=estrat_bat1(e,i,e.jog);
   */
   return e;
}


int main (){
ESTADO e;
e.jog.x=3;
e.jog.y=4;
e.hp=40;
printf("%d\n",e.hp);
}