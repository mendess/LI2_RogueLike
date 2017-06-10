//#define DEBUG
#include <stdio.h>
#include "IAwolf.h"

int sem_monstros(ESTADO e,int n,int x,int y){
  int i,flag;
  flag=1;
  for(i=0;i<n;i++){
    if(e.monstros[i].x==x && e.monstros[i].y == y) return 0;
  }
    return flag;
}
int sem_pedras(ESTADO e,int n,int x,int y){
  int i,flag;
  flag=1;
  for(i=0;i<n;i++){
    if(e.pedras[i].x==x && e.pedras[i].y == y) return 0;
  }
    return flag;
}
ESTADO persegue_wolf_SE (ESTADO e,int i,POSICAO p,int a[10][10]){
  int x,y,flag;
  flag=1;
  for(x=p.x+1;x>=p.x-1 && flag;x--){
    for(y=p.y+1;y>=p.y-1 && flag;y--){
       if(a[x][y]<=a[p.x][p.y] && sem_monstros(e,e.num_monstros,x,y) && sem_pedras(e,e.num_pedras,x,y)){
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
       if(a[x][y]<=a[p.x][p.y] && sem_monstros(e,e.num_monstros,x,y) && sem_pedras(e,e.num_pedras,x,y)){
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
       if(a[x][y]<=a[p.x][p.y] && sem_monstros(e,e.num_monstros,x,y) && sem_pedras(e,e.num_pedras,x,y)){
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
       if(a[x][y]<=a[p.x][p.y] && sem_monstros(e,e.num_monstros,x,y) && sem_pedras(e,e.num_pedras,x,y)){
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
  if(e.world_lvl>10) {
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
ESTADO defesa_WOLF_NE (ESTADO e, int i,POSICAO p,int a[10][10]){
  int x,y,d,flag;
  flag=1;
  d= a[p.x][p.y]/2; // o monstro deve ir para d para intersetar o jogador;
  for(x=p.x-1;x<=p.x+1 && flag;x++){
    for(y=p.y-1;y<=p.y+1 && flag;y++){
      if(a[x][y]>=d && a[x][y]<a[p.x][p.y] && sem_monstros(e,e.num_monstros,x,y)){
        e.monstros[i].x=x;
        e.monstros[i].y=y;
        flag=0;
      }
    }
  }
  return e;
}
ESTADO defesa_WOLF_NO (ESTADO e, int i,POSICAO p,int a[10][10]){
 int x,y,d,flag;
  flag=1;
  d= a[p.x][p.y]/2; // o monstro deve ir para d para intersetar o jogador;
  for(x=p.x+1;x>=p.x-1 && flag;x--){
    for(y=p.y-1;y<=p.y+1 && flag;y++){
      if(a[x][y]>=d && a[x][y]<a[p.x][p.y] && sem_monstros(e,e.num_monstros,x,y)){
        e.monstros[i].x=x;
        e.monstros[i].y=y;
        flag=0;
      }
    }
  }
  return e;
}
ESTADO defesa_WOLF_SE (ESTADO e, int i,POSICAO p,int a[10][10]){
  int x,y,d,flag;
  flag=1;
  d= a[p.x][p.y]/2; // o monstro deve ir para d para intersetar o jogador;
  for(x=p.x+1;x>=p.x-1 && flag;x--){
    for(y=p.y+1;y>=p.y-1 && flag;y--){
      if(a[x][y]>=d && a[x][y]<a[p.x][p.y] && sem_monstros(e,e.num_monstros,x,y)){
        e.monstros[i].x=x;
        e.monstros[i].y=y;
        flag=0;
      }
    }
  }
  return e;
}
ESTADO defesa_WOLF_SO (ESTADO e, int i,POSICAO p,int a[10][10]){
 int x,y,d,flag;
  flag=1;
  d= a[p.x][p.y]/2; // o monstro deve ir para d para intersetar o jogador;
  for(x=p.x-1;x<=p.x+1 && flag;x++){
    for(y=p.y+1;y>=p.y-1 && flag;y--){
      if(a[x][y]>=d && a[x][y]<a[p.x][p.y] && sem_monstros(e,e.num_monstros,x,y)){
        e.monstros[i].x=x;
        e.monstros[i].y=y;
        flag=0;
      }
    }
  }
  return e;
}
void distancia_WOLF (ESTADO e,int a[10][10],int x,int y,int i){
    int a1,a2;
    if(x<10 && x>=0 && y<10 && y>=0){
      if(sem_pedras(e,e.num_pedras,x,y) && i<a[x][y] && sem_monstros(e,e.num_monstros,x,y)){
        a[x][y]=i;
        i++;
        for(a1=x-1;a1<=x+1;a1++){
          for(a2=y-1;a2<=y+1;a2++){
            if(a1!=x || a2!=y){
              distancia_WOLF(e,a,a1,a2,i);
            }
          }
        }
      }
    }
}
void preenche_matriz(int a[10][10]){
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
  preenche_matriz(a);
  distancia_WOLF(e,a,e.jog.x,e.jog.y,0);
  if (existe_jogador(e,p)){
    e.hp-=WOLF_DMG;
  	flag=0;
  } // J M →ŧ
  if(flag && BLOQUEAVEL_NE){
    e=defesa_WOLF_NE(e,i,p,a);
    flag=0;
  } // J M←ŧ
  if(flag && BLOQUEAVEL_NO){
    e= defesa_WOLF_NO(e,i,p,a);
    flag=0;
  } // J M←↓
  if(flag && BLOQUEAVEL_SE){
    e=defesa_WOLF_SE(e,i,p,a);
    flag=0;
  } // J M→↓
  if(flag && BLOQUEAVEL_SO){
    e=defesa_WOLF_SO(e,i,p,a);
    flag=0;
  } // na persegue dá-se primasia as diagonais
  if(flag) e=persegue_wolf(e,i,p,a);
  return e;
}