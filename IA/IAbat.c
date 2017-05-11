#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "IAbat.h"


POSICAO buscaB1 (ESTADO e,int a[SIZE][SIZE]){
  int x,y,flag;
  POSICAO intersect;
  flag=1;
  for(y=0;y<10;y++){
    for(x=9;x>=0;x--){
       if(a[x][y] == 0 && livre(e,x,y) && flag){
         intersect.x=x;
         intersect.y=y;
         flag=0;
       }
    }
  }
 return intersect;
}
POSICAO buscaB2 (ESTADO e,int a[SIZE][SIZE]){
  int x,y,flag;
  POSICAO intersect;
  flag=1;
  for(y=9;y>=0;y--){
    for(x=0;x<10;x++){
      if(a[x][y] == 0 && livre(e,x,y) && flag){
         intersect.x=x;
         intersect.y=y;
         flag=0;
       }
    }
  }
  return intersect;
}
POSICAO buscaB3 (ESTADO e,int a[SIZE][SIZE]){
    int x,y,flag;
  POSICAO intersect;
  flag=1;
  for(y=0;y<10;y--){
    for(x=0;x<10;x++){
      if(a[x][y] == 0 && livre(e,x,y) && flag){
         intersect.x=x;
         intersect.y=y;
         flag=0;
       }
    }
  }
  return intersect;
}
POSICAO buscaB4 (ESTADO e,int a[SIZE][SIZE]){
  int x,y,flag;
  POSICAO intersect;
  flag=1;
  for(y=9;y>=0;y--){
    for(x=9;x>=0;x--){
      if(a[x][y] == 0 && livre(e,x,y) && flag){
         intersect.x=x;
         intersect.y=y;
         flag=0;
       }
    }
  }
  return intersect;
}
POSICAO mapa3 (ESTADO e,POSICAO p,int q){
  int d,x,y;
  int a[10][10];
  POSICAO intersect;
  d=abs(e.jog.x-p.x)+abs(e.jog.y-p.y);
  for(y=0;y<10;y++){
    for(x=0;x<10;x++){
       if (abs(x-e.jog.x)>abs(y-e.jog.y)){
          a[y][x]=abs(x-e.jog.x)-d;
       }
       if (abs(y-e.jog.y)>abs(x-e.jog.x)){
          a[y][x]=abs(y-e.jog.y)-d;
       } 
    }
  }
  if(q==1) intersect=buscaB1(e,a);
  if(q==2) intersect=buscaB2(e,a);
  if(q==3) intersect=buscaB3(e,a);
  if(q==4) intersect=buscaB4(e,a);
  return intersect;
}
int livre (ESTADO e,int x,int y){
  int i,flag;
  flag=1;
  for(i=0;i<e.num_monstros;i++){
     if (e.monstros[i].x==x && e.monstros[i].y==y){
      flag=0;
     }
  }
  return flag;
}
ESTADO estrat_bat1 (ESTADO e, int i, POSICAO intersect){
   POSICAO p;
   int flag=1;
   p.x=e.monstros[i].x;
   p.y=e.monstros[i].y;
   if (flag && p.x > intersect.x && p.y > intersect.y && livre(e,p.x-1,p.y-1)){
    e.monstros[i].x+=-1;
    e.monstros[i].y+=-1;
    flag=0;
   }
   if (flag && p.x > intersect.x && p.y < intersect.y && livre(e,p.x-1,p.y+1)){
    e.monstros[i].x+=-1;
    e.monstros[i].y+=1;
    flag=0;
   }
   if (flag && p.x < intersect.x && p.y > intersect.y && livre(e,p.x+1,p.y-1)){
    e.monstros[i].x+=1;
    e.monstros[i].y+=-1;
    flag=0;
   }
   if (flag && p.x < intersect.x && p.y < intersect.y && livre(e,p.x+1,p.y+1)){
    e.monstros[i].x+=1;
    e.monstros[i].y+=1;
    flag=0;
   }
   if (flag && p.x > intersect.x && livre(e,p.x+1,p.y)){
    e.monstros[i].x+=1;
    flag=0;
   }
   if (flag && p.y < intersect.y && livre(e,p.x,p.y-1)){
    e.monstros[i].y+=-1;
    flag=0;
   }
   if (flag && p.x < intersect.x && livre(e,p.x-1,p.y)){
    e.monstros[i].x+=-1;
    flag=0;
   }
   if (flag && p.y > intersect.y && livre(e,p.x,p.y-1)){
    e.monstros[i].y+=1;
    flag=0;
   }
   return e;
}
ESTADO defB (ESTADO e, int i,POSICAO p,int num){
  POSICAO intersect;
  intersect= mapa3(e,p,num);
  e=estrat_bat1(e,i,intersect);
  return e;
}
// ve se o monstro está entre o jogador e a saida e em que quadrante está.
ESTADO estrat_bat(ESTADO e,int i,POSICAO p){
   int flag=1;;
   if (existe_jogador(e,p)){
        e.hp-=BAT_DMG;
      flag=0;
   } // J M →ŧ
   if(flag && e.jog.x<=p.x && e.jog.y>=p.y && e.saida.x>=e.jog.x && e.saida.y<=e.jog.y){
     e=defB(e,i,p,1);
     flag=0;
   } // J M←ŧ
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
   return e;
}

