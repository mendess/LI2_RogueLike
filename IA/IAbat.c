// falta persegue
// no .h fazer include "../move_monst.h"
#include <stdio.h>
#include "IA.h"


ESTADO persegue_bat(e,i,p){

}
POSICAO buscaB1 (ESTADO mov){
  int x,y,flag;
  POSICAO intersect;
  flag=1;
  for(y=0;y<10;y++){
    for(x=9;x>=0;x--){
       if(mov[x][y] == 0 && livre(e,x,y) && flag){
         intersec=(x,y);
         flag=0;
       }
    }
  }
 return intersect;
}
POSICAO buscaB2 (ESTADO mov){
  int x,y,flag;
  POSICAO intersect;
  flag=1;
  for(y=9;y>=0;y--){
    for(x=0;x<10;x++){
      if(mov[x][y] == 0 && livre(e,x,y) && flag){
         intersec=(x,y);
         flag=0;
       }
    }
  }
  return intersect;
}
POSICAO buscaB3 (ESTADO mov){
    int x,y,flag;
  POSICAO intersect;
  flag=1;
  for(y=0;y<10;y--){
    for(x=0;x<10;x++){
      if(mov[x][y] == 0 && livre(e,x,y) && flag){
         intersec=(x,y);
         flag=0;
       }
    }
  }
  return intersect;
}
POSICAO buscaB4 (ESTADO mov){
  int x,y,flag;
  POSICAO intersect;
  flag=1;
  for(y=9;y>=0;y--){
    for(x=9;x>=0;x+--){
      if(mov[x][y] == 0 && livre(e,x,y) && flag){
         intersec=(x,y);
         flag=0;
       }
    }
  }
  return intersect;
}
POSICAO mapa1 (Estado e,int i,POSICAO p,int q){
  int d,x,y,flag;
  int a[10][10];
  d=abs(e.jog.x-p.x)+abs(e.jog.y-p.y);
  flag=1;
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
  if(q==1) intersect=buscaA1(a);
  if(q==2) intersect=buscaA2(a);
  if(q==3) intersect=buscaA3(a);
  if(q==4) intersect=buscaA4(a);
  return intersect;
}

int livre (ESTADO e,int x,int y){
  int i,flag;
  flag=1;
  for(i=0;i<num_monstros;i++){
     if (e.monstros[i].x==x && e.monstros[i].y==y) flag=0;
  }
  return flag;
}


ESTADO estrat_bat1 (ESTADO e, int i, POSICAO intersect){
   POSICAO p;
   p.x=e.monstros[i].x;
   p.y=e.monstros[i].y;
   if (p.x > intersect.x && livre(e,p.x+1,p.y)) e.monstros[i].x+1;
   if (p.y < intersect.y && livre(e,p.x,p.y-1)) e.monstros[i].y-1;
   if (p.x < intersect.x && livre(e,p.x-1,p.y)) e.monstros[i].x-1;
   if (p.y > intersect.y && livre(e,p.x,p.y-1)) e.monstros[i].y+1;
   return e;
}

ESTADO defB1 (ESTADO e, int i,POSICAO p){
  POSICAO intersect;
  intersect= mapa1(e,i,p,1);
  e=estrat_bat1(e,i,intersect);
  return e;
}
ESTADO defB2 (ESTADO e, int i,POSICAO p){
  POSICAO intersect;
  intersect= mapa1(e,i,p,2);
  e=estrat_bat1(e,i,intersect);
  return e;
}
ESTADO defB3 (ESTADO e, int i,POSICAO p){
  POSICAO intersect;
  intersect= mapa1(e,i,p,3);
  e=estrat_bat1(e,i,intersect);
  return e;
}
ESTADO defB4 (ESTADO e, int i,POSICAO p){
  POSICAO intersect;
 intersect= mapa1(e,i,p,4);
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
     e=defB1(e,i,p);
     flag=0;
   } // J M←ŧ
   if(flag && e.jog.x>=p.x && e.jog.y>=p.y && e.saida.x<=e.jog.x && e.saida.y<=e.jog.y){
     e= defB2(e,i,p);
     flag=0;
   } // J M←↓
   if(flag && e.jog.x>=p.x && e.jog.y<=p.y && e.saida.x<=e.jog.x && e.saida.y>=e.jog.y){
     e=defB3(e,i,p);
     flag=0;
   } // J M→↓
   if(flag && e.jog.x<=p.x && e.jog.y<=p.y && e.saida.x>=e.jog.x && e.saida.y>=e.jog.y){
     e=defB4(e,i,p);
     flag=0;
   }
   // na persegue dá-se primasia as diagonais
   if(flag) e=persegue_bat(e,i,p);
   return e;
/*
   // jogador por baixo saida a direita- verificar monstros
   if (abs(e.jog.x-p.x)>1 && e.jog.x<p.x && abs(e.jog.y-p.y)==1 && flag){
     e.monstros[i].x-1;
     e.monstros[i].y-1;
     flag=0;
   }
 if (abs(e.jog.x-p.x)>1 && e.jog.x>p.x && abs(e.jog.y-p.y)==1 && flag){
     e.monstros[i].x+1;
     e.monstros[i].y-1;
     flag=0;
   }
 if (abs(e.jog.x-p.x)<3 && e.jog.x<p.x && abs(e.jog.y-p.y)>1 && flag){
     e.monstros[i].x-1;
     e.monstros[i].y+1;
     flag=0;
   }
 if (abs(e.jog.x-p.x)>1 && e.jog.x>p.x && abs(e.jog.y-p.y)>1 && flag){
     e.monstros[i].x+1;
     e.monstros[i].y+1;
     flag=0;
   }
   if (abs(e.jog.y-p.y)>2 && e.jog.y>p.y && flag){
     if(e.jog.x>p.x){
        e-monstros[i].x+1;
     }
     if(e.jog.x<p.
     e.monstros
   }
*/
}

