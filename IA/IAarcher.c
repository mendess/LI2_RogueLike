#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "IA.h"

// PEDRAS
int block_pedra (ESTADO e,POSICAO p){
  int i,flag;
  flag=0;
  for(i=0;i<e.num_pedras;i++){
    if(e.pedras[i].x==p.x && e.pedras[i].y==p.y) flag=1;
  }
  return flag;
}
// MONSTROS
int block_monst (ESTADO e,POSICAO p){
  int i,flag;
  flag=0;
  for(i=0;i<e.num_monstros;i++){
    if(e.monstros[i].x==p.x && e.monstros[i].y==p.y) flag=1;
  }
  return flag;
}

int possivel_casa (ESTADO e,POSICAO p){
  int flag;
  flag=1;
  if(block_pedra(e,p) || block_monst(e,p)) flag=0;
  return flag;
}
ESTADO persegue_arch(ESTADO e,int i,POSICAO p){
  POSICAO pos;
  int flag=1;
  pos.x=p.x-1;
  pos.y=p.y;
  if(p.x>e.jog.x && abs(e.jog.y-p.y)<3 && possivel_casa(e,pos)){
  e.monstros[i].x+=(-1);
  flag=0;
  }
  pos.x=p.x+1;
  pos.y=p.y;
   if(flag && p.x<e.jog.x && abs(e.jog.y-p.y)<2 && possivel_casa(e,pos)){
  e.monstros[i].x+=(-1);
  flag=0;
  }
  pos.x=p.x;
  pos.y=p.y+1;
  if(flag && p.y<e.jog.y && abs(e.jog.x-p.x)<2 && possivel_casa(e,pos)){
  e.monstros[i].y+=1;
  flag=0;
  }
  pos.x=p.x;
  pos.y=p.y-1;
  if(flag && p.y>e.jog.y && abs(e.jog.x-p.x)<2 && possivel_casa(e,pos)){
  e.monstros[i].y+=(-1);
  flag=0;
  }
  return e;
}
int livre1(ESTADO e,int x,int y){
  POSICAO pos;
  pos.x=x;
  pos.y=y;
  int i;
  i=possivel_casa(e,pos);
  return i;
}
POSICAO buscaA1(ESTADO e,int a[SIZE][SIZE]){
  int i,x,y,flag;
  POSICAO intersect;
  flag=1;i=0;
  for(y=0;y<10;y++){
  for(x=0;x<10;x++){
     if(a[x][y] == 0 && i!=3){
       i++;
     }
     if(i==3 && livre1(e,x,y)  && flag){
      intersect.x=x;
      intersect.y=y;
      x=10;
      y=10;
      flag=0;
     }
  }
  }
 return intersect;
}
POSICAO buscaA2(ESTADO e,int a[SIZE][SIZE]){
   int i,x,y,flag;
  POSICAO intersect;
  flag=1;i=0;
  for(y=0;y<10;y++){
   for(x=9;x>=0;x--){
     if(a[x][y] == 0 && i!=3){
     i++;
     }
     if(i==3 && livre1(e,x,y) && flag){
    intersect.x=x;
    intersect.y=y;
    x=-1;
    y=10;
    flag=0;
    }
   }
  }
 return intersect;
}
POSICAO buscaA3(ESTADO e,int a[SIZE][SIZE]){
   int i,x,y,flag;
  POSICAO intersect;
  flag=1;i=0;
  for(y=9;y>=0;y--){
  for(x=9;x>=0;x--){
     if(a[x][y] == 0 && i!=3){
      i++;
     }
     if(i==3 && livre1(e,x,y) && flag){
      intersect.x=x;
      intersect.y=y;
      x=-1;
      y=-1;
      flag=0;
     }
  }
  }
 return intersect;
}
POSICAO buscaA4(ESTADO e,int a[SIZE][SIZE]){
   int i,x,y,flag;
  POSICAO intersect;
  flag=1;i=0;
  for(y=0;y<10;y++){
  for(x=0;x<10;x++){
     if(a[x][y] == 0 && i!=3){
      i++;
     }
     if(i==3 && livre1(e,x,y) && flag){
      intersect.x=x;
      intersect.y=y;
      x=-1;
      y=10;
      flag=0;
     }
  }
  }
 return intersect;
}
POSICAO mapa4 (ESTADO e,int i,POSICAO p,int q){
  int x,y;
  int a[10][10];
  POSICAO intersect;
  for(y=0;y<10;y++){
  for(x=0;x<10;x++){
     if (abs(x-e.jog.x)>abs(y-e.jog.y)){
      a[y][x]=abs(x-e.jog.x)-2;
     }
     if (abs(y-e.jog.y)>abs(x-e.jog.x)){
      a[y][x]=abs(y-e.jog.y)-2;
     } 
  }
  }
  if(q==1) intersect=buscaA1(e,a);
  if(q==2) intersect=buscaA2(e,a);
  if(q==3) intersect=buscaA3(e,a);
  if(q==4) intersect=buscaA4(e,a);
  return intersect;
}
ESTADO decide(ESTADO e,int i, POSICAO intersect){
  POSICAO pos;
  int flag=1;
  pos.x=e.monstros[i].x+1;
  pos.y=e.monstros[i].y;
  if (intersect.x>e.monstros[i].x && possivel_casa(e,pos)){
    e.monstros[i].x+=1;
    flag=0;
   }
   pos.x=e.monstros[i].x-1;
   pos.y=e.monstros[i].y;
   if (flag && intersect.x<e.monstros[i].x && possivel_casa(e,pos)){
    e.monstros[i].x+=-1;
    flag=0;
   }
   pos.x=e.monstros[i].x;
   pos.y=e.monstros[i].y+1;
  if (flag && intersect.y>e.monstros[i].y && possivel_casa(e,pos)){
    e.monstros[i].y+=1;
    flag=0;
   }
   pos.x=e.monstros[i].x;
   pos.y=e.monstros[i].y-1;
   if (flag && intersect.y<e.monstros[i].y && possivel_casa(e,pos)){
    e.monstros[i].y+=-1;
    flag=0;
   }
   return e;
}
ESTADO defA (ESTADO e, int i, POSICAO p,int num){
   POSICAO intersect;
   intersect=mapa4(e,i,p,num);
   e=decide(e,i,intersect);
   return e;
}
ESTADO estrat_archer (ESTADO e,int i,POSICAO p){
   int flag=1;;
   if (ve_jogador(e,p)){
    e.hp-=ARCHER_DMG;
    flag=0;
   } // J M →ŧ
   if(flag && e.jog.x<=p.x && e.jog.y>=p.y && e.saida.x>=e.jog.x && e.saida.y<=e.jog.y){
   e=defA(e,i,p,1);
   flag=0;
   } // J M←ŧ
   if(flag && e.jog.x>=p.x && e.jog.y>=p.y && e.saida.x<=e.jog.x && e.saida.y<=e.jog.y){
   e=defA(e,i,p,2);
   flag=0;
   } // J M←↓
   if(flag && e.jog.x>=p.x && e.jog.y<=p.y && e.saida.x<=e.jog.x && e.saida.y>=e.jog.y){
   e=defA(e,i,p,3);
   flag=0;
   } // J M→↓
   if(flag && e.jog.x<=p.x && e.jog.y<=p.y && e.saida.x>=e.jog.x && e.saida.y>=e.jog.y){
   e=defA(e,i,p,4);
   flag=0;
   }
   // na persegue dá-se primasia as diagonais
   if(flag) e=persegue_arch(e,i,p);
   return e;
}