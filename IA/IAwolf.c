#include <stdio.h>
#include "IAwolf.h"
/*
//PEDRAS
int blocked1 (ESTADO e,POSICAO p){
  int i,flag;
  flag=0;
  for(i=0;i<e.num_pedras;i++){
    if(e.pedras[i].x==p.x && e.pedras[i].y==p.y) flag=1;
  }
  return flag;
}
// MONSTROS
int blocked2 (ESTADO e,POSICAO p){
  int i,flag;
  flag=0;
  for(i=0;i<e.num_monstros;i++){
    if(e.monstros[i].x==p.x && e.monstros[i].y==p.y) flag=1;
  }
  return flag;
}
int possivel (ESTADO e,POSICAO p){
  int flag;
  flag=1;
  if(blocked1(e,p) || blocked2(e,p)) flag=0;
  return flag;
}
ESTADO persegue_wolf (ESTADO e,int i,POSICAO p){
  POSICAO pos;
  int flag=1;
  pos=p;
  if(e.jog.x>p.x && e.jog.y<p.y){
   pos.x=p.x+1;
   pos.y=p.y-1;
   if (possivel(e,pos)){
     e.monstros[i].x+=1;
     e.monstros[i].y+=-1;
     flag=0;
   }
  }
  if(e.jog.x<p.x && e.jog.y>p.y){
   pos.x=p.x-1;
   pos.y=p.y+1;
   if (possivel(e,pos)){
     e.monstros[i].x+=-1;
     e.monstros[i].y+=1;
      flag=0;
   }
  }
  if(e.jog.x>p.x && e.jog.y>p.y){
    pos.x=p.x+1;
    pos.y=p.y+1;
    if (possivel(e,pos)){
     e.monstros[i].x+=1;
     e.monstros[i].y+=1;
      flag=0;
   }
  }
  if(e.jog.x<p.x && e.jog.y<p.y){
     pos.x=p.x-1;
     pos.y=p.y-1;
   if (possivel(e,pos)){
     e.monstros[i].x+=-1;
     e.monstros[i].y+=-1;
      flag=0;
   }
  }
  pos.y=p.y+1;
  if(flag && e.jog.y>p.y && possivel(e,pos)){
    e.monstros[i].y+=1;
     flag=0;
  }
  pos.y=p.y-1;
  if(flag && e.jog.y<p.y && possivel(e,pos)){
    e.monstros[i].y+=-1;
     flag=0;
  }
  pos.x=p.x+1;
  if(flag && e.jog.x>p.x && possivel(e,pos)){
    e.monstros[i].x+=1;
     flag=0;
  }
  pos.x=p.x-1;
  if(flag && e.jog.x<p.x && possivel(e,pos)){
    e.monstros[i].x+=-1;
  }
 return e;
}
int impossivel(ESTADO e,POSICAO pos){
   int i,flag=0;
   for(i=0;i<e.num_pedras;i++){
    if(!flag && pos.x==e.pedras[i].x && pos.y==e.pedras[i].y) flag=1;
   }
   for(i=0;i<e.num_monstros;i++){
    if(!flag && pos.x==e.monstros[i].x && pos.y==e.monstros[i].y) flag=1;
   }
   return flag;
}
POSICAO anda_vertical(POSICAO atual,POSICAO alternativa){
  POSICAO pos=atual;
  int flag=1;
    if(atual.y>alternativa.y+1){
     pos.y--;
     flag=0;
    }
    if(atual.y<alternativa.y-1){
     pos.y++;
     flag=0;
    }
  if(flag && abs(atual.y-alternativa.y)==1){
    pos.x=alternativa.x;
    pos.y=alternativa.y;
  }
  atual=pos;
  return atual;
}
POSICAO vertical1(ESTADO e,POSICAO pos){
  POSICAO p1,p2;
  int i;
  p1=p2=pos;
  for(i=0;impossivel(e,p1) && impossivel(e,p2);i++){
    p1.y++;
    p2.y--;
  }
  if(abs(pos.y-p1.y)>=abs(pos.y-p2.y)) pos=p2;
  else pos=p1;
  return pos;
}
POSICAO direcao(POSICAO pos,POSICAO intersect){
  if(intersect.x>pos.x) pos.x+=1;
  if(intersect.x<pos.x) pos.x+=-1;
  if(intersect.y>pos.y) pos.y+=1;
  if(intersect.y<pos.y) pos.y+=-1;
  return pos;
}
// estado - pos monstro-pos intercecao
POSICAO tracker (ESTADO e,POSICAO p, POSICAO intersect){
 POSICAO alternativa,caminho[25];
 int i=0;int alt;
 caminho[0].x=p.x;
 caminho[0].y=p.y;
 while(caminho[i].x != intersect.x || caminho[i].y != intersect.y){
  caminho[i+1]=direcao(caminho[i],intersect);
  i++;

 }
 for(i=0;caminho[i].x!=intersect.x || caminho[i].y!=intersect.y;i++){
    if(impossivel(e,caminho[i])){
      alternativa=vertical1(e,caminho[i]);// alternativa=(8,5)
      alt=i;
      while(caminho[alt-1].x!=alternativa.x || caminho[alt-1].y!=alternativa.y){
        caminho[alt]=anda_vertical(caminho[alt-1],alternativa);
        alt++;
      } 
      while(caminho[alt-1].x!= intersect.x || caminho[alt-1].y != intersect.y){
          caminho[alt]=direcao(caminho[alt-1],intersect);
          alt++;
      }  // caminho certo
    }
 }
 return caminho[1];
}
POSICAO buscaW1 (ESTADO e,int a[SIZE][SIZE]){
  int x,y,flag;
  POSICAO intersect,pos;
  flag=1;
  for(y=0;y<10;y++){
    pos.y=y;
    for(x=9;x>=0;x--){
       pos.x=x;
       if(a[x][y] == 0 && possivel(e,pos) && flag){
         intersect.x=x;
         intersect.y=y;
         flag=0;
       }
    }
  }
 return intersect;
}
POSICAO buscaW2 (ESTADO e,int a[SIZE][SIZE]){
  int x,y,flag;
  POSICAO intersect,pos;
  flag=1;
  for(y=9;y>=0;y--){
    pos.y=y;
    for(x=0;x<10;x++){
      pos.x=x;
      if(a[x][y] == 0 && possivel(e,pos) && flag){
         intersect.x=x;
         intersect.y=y;
         flag=0;
       }
    }
  }
  return intersect;
}
POSICAO buscaW3 (ESTADO e,int a[SIZE][SIZE]){
  int x,y,flag;
  POSICAO intersect,pos;
  flag=1;
  for(y=0;y<10;y--){
    pos.y=y;
    for(x=0;x<10;x++){
      pos.x=x;
      if(a[x][y] == 0 && possivel(e,pos) && flag){
         intersect.x=x;
         intersect.y=y;
         flag=0;
       }
    }
  }
  return intersect;
}
POSICAO buscaW4 (ESTADO e,int a[SIZE][SIZE]){
  int x,y,flag;
  POSICAO intersect,pos;
  flag=1;
  for(y=9;y>=0;y--){
    pos.y=y;
    for(x=9;x>=0;x--){
      pos.x=x;
      if(a[x][y] == 0 && possivel(e,pos) && flag){
         intersect.x=x;
         intersect.y=y;
         flag=0;
       }
    }
  }
  return intersect;
}
POSICAO mapa1 (ESTADO e,POSICAO p,int q){
  int d,x,y;
  int a[10][10];
  POSICAO intersect;
  d=abs(e.jog.x-p.x)+abs(e.jog.y-p.y);
  for(y=0;y<10;y++){
    for(x=0;x<10;x++){
       if (abs(x-e.jog.x)>abs(y-e.jog.y)){
          a[y][x]=abs(x-e.jog.x)-d;
       }
       else{
          a[y][x]=abs(y-e.jog.y)-d;
       } 
    }
  }
  if(q==1) intersect=buscaW1(e,a);
  if(q==2) intersect=buscaW2(e,a);
  if(q==3) intersect=buscaW3(e,a);
  if(q==4) intersect=buscaW4(e,a);
  return intersect;
}
*/
ESTADO persegue_wolf_SE (ESTADO e,int i,POSICAO p,int a[10][10]){
  int x,y,flag;
  flag=1;
  for(x=p.x+1;x>=p.x-1 && flag;x--){
    for(y=p.y+1;y>=p.y-1 && flag;y--){
       if(a[x][y]<=a[p.x][p.y]){
        e.monstros[i].x=x;
        e.monstros[i].y=y;
        flag=0;
       }
    }
  }
  return e;
}
ESTADO persegue_wolf_NE (ESTADO e,int i,POSICAO p,int a[10][10]){
  int x,y,flag;
  flag=1;
  for(x=p.x+1;x>=p.x-1 && flag;x--){
    for(y=p.y-1;y<=p.y+1 && flag;y++){
       if(a[x][y]<=a[p.x][p.y]){
        e.monstros[i].x=x;
        e.monstros[i].y=y;
        flag=0;
       }
    }
  }
  return e;
}
ESTADO persegue_wolf_SO (ESTADO e,int i,POSICAO p,int a[10][10]){
  int x,y,flag;
  flag=1;
  for(x=p.x-1;x<=p.x+1 && flag;x++){
    for(y=p.y+1;y>=p.y-1 && flag;y--){
       if(a[x][y]<=a[p.x][p.y]){
        e.monstros[i].x=x;
        e.monstros[i].y=y;
        flag=0;
       }
    }
  }
  return e;
}
ESTADO persegue_wolf_NO (ESTADO e,int i,POSICAO p,int a[10][10]){
  int x,y,flag;
  flag=1;
  for(x=p.x-1;x<=p.x+1 && flag;x++){
    for(y=p.y-1;y<=p.y+1 && flag;y++){
       if(a[x][y]<=a[p.x][p.y]){
        e.monstros[i].x=x;
        e.monstros[i].y=y;
        flag=0;
       }
    }
  }
  return e;
}
ESTADO persegue_wolf (ESTADO e,int i,POSICAO p,int a[10][10]){
  int flag=1;
  /* // implementar modo mais inteligente no nivel 8
  if(e.world_lvl>7) {
    e=persegue_wolf1(e,i,p,a);
    flag=0;
  }
  */
  if(flag && p.x<e.jog.x && p.y<e.jog.y){
    e=persegue_wolf_SE(e,i,p,a);
    flag=0;
  }
  if(flag && p.x<e.jog.x && p.y>e.jog.y){
    e=persegue_wolf_NE(e,i,p,a);
    flag=0;
  }
  if(flag && p.x>e.jog.x && p.y<e.jog.y){
    e=persegue_wolf_SO(e,i,p,a);
    flag=0;
  }
  if(flag && p.x>e.jog.x && p.y>e.jog.y){
    e=persegue_wolf_NO(e,i,p,a);
    flag=0;
  }
  return e;
}
ESTADO defW1 (ESTADO e, int i,POSICAO p,int a[10][10]){
  int x,y,d,flag;
  flag=1;
  d= a[p.x][p.y]/2; // o monstro deve ir para d para intersetar o jogador;
  for(x=p.x-1;x<=p.x+1 && flag;x++){
    for(y=p.y-1;y<=p.y+1 && flag;y++){
      if(a[x][y]>=d && a[x][y]<a[p.x][p.y]){
        e.monstros[i].x=x;
        e.monstros[i].y=y;
        flag=0;
      }
    }
  }
  return e;
}
ESTADO defW2 (ESTADO e, int i,POSICAO p,int a[10][10]){
 int x,y,d,flag;
  flag=1;
  d= a[p.x][p.y]/2; // o monstro deve ir para d para intersetar o jogador;
  for(x=p.x+1;x>=p.x-1 && flag;x--){
    for(y=p.y-1;y<=p.y+1 && flag;y++){
      if(a[x][y]>=d && a[x][y]<a[p.x][p.y]){
        e.monstros[i].x=x;
        e.monstros[i].y=y;
        flag=0;
      }
    }
  }
  return e;
}
ESTADO defW3 (ESTADO e, int i,POSICAO p,int a[10][10]){
  int x,y,d,flag;
  flag=1;
  d= a[p.x][p.y]/2; // o monstro deve ir para d para intersetar o jogador;
  for(x=p.x+1;x>=p.x-1 && flag;x--){
    for(y=p.y+1;y>=p.y-1 && flag;y--){
      if(a[x][y]>=d && a[x][y]<a[p.x][p.y]){
        e.monstros[i].x=x;
        e.monstros[i].y=y;
        flag=0;
      }
    }
  }
  return e;
}
ESTADO defW4 (ESTADO e, int i,POSICAO p,int a[10][10]){
 int x,y,d,flag;
  flag=1;
  d= a[p.x][p.y]/2; // o monstro deve ir para d para intersetar o jogador;
  for(x=p.x-1;x<=p.x+1 && flag;x++){
    for(y=p.y+1;y>=p.y-1 && flag;y--){
      if(a[x][y]>=d && a[x][y]<a[p.x][p.y]){
        e.monstros[i].x=x;
        e.monstros[i].y=y;
        flag=0;
      }
    }
  }
  return e;
}
int sem_pedras(ESTADO e,int n,int x,int y){
  int i,flag;
  flag=1;
  for(i=0;i<n;i++){
    if(e.pedras[i].x==x && e.pedras[i].y == y) return 0;
  }
    return flag;
}
void dist (ESTADO e,int a[10][10],int x,int y,int i){
    int a1,a2;
    if(x<10 && x>=0 && y<10 && y>=0){
      if(sem_pedras(e,e.num_pedras,x,y) && i<a[x][y]){
        a[x][y]=i;
        i++;
        for(a1=x-1;a1<=x+1;a1++){
          for(a2=y-1;a2<=y+1;a2++){
            if(a1!=0 || a2!=0){
              dist(e,a,a1,a2,i);
            }
          }
        }
      }
    }
}

void preenche(int a[10][10]){
  int x,y;
  for(x=0;x<10;x++){
    for(y=0;y<10;y++){
      a[x][y]=50;
    }
  }
}

ESTADO estrat_wolf (ESTADO e,int i,POSICAO p){
  int flag=1;
  int a[10][10];
  preenche(a);
  dist(e,a,e.jog.x,e.jog.y,0);
  if (existe_jogador(e,p)){
    e.hp-=WOLF_DMG;
  	flag=0;
  } // J M →ŧ
  if(flag && e.jog.x<p.x && e.jog.y>p.y && p.x<e.saida.x && e.saida.y<p.y && e.saida.x>e.jog.x && e.saida.y<e.jog.y){
    e=defW1(e,i,p,a);
    flag=0;
  } // J M←ŧ
  if(flag && e.jog.x>p.x && e.jog.y>p.y && e.saida.x<p.x && e.saida.y<p.y && e.saida.x<e.jog.x && e.saida.y<e.jog.y){
    e= defW2(e,i,p,a);
    flag=0;
  } // J M←↓
  if(flag && e.jog.x>p.x && e.jog.y<p.y && e.saida.x<p.x && e.saida.y>p.y && e.saida.x<e.jog.x && e.saida.y>e.jog.y){
    e=defW3(e,i,p,a);
    flag=0;
  } // J M→↓
  if(flag && e.jog.x<p.x && e.jog.y<p.y && e.saida.x>p.x && e.saida.y>p.y && e.saida.x>e.jog.x && e.saida.y>e.jog.y){
    e=defW4(e,i,p,a);
    flag=0;
  }
  // na persegue dá-se primasia as diagonais
  if(flag) e=persegue_wolf(e,i,p,a);
  return e;
}
