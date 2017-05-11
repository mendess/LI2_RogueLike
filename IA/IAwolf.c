#include <stdio.h>
#include "IAwolf.h"


ESTADO persegue_wolf (ESTADO e,int i,POSICAO p){
  POSICAO pos;
  pos=p;
  if(e.jog.x>p.x && e.jog.y<p.y){
   pos.x=p.x+1;
   pos.y=p.y-1;
   if (possivel(e,pos)){
     e.monstros[i].x+=1;
     e.monstros[i].y+=-1;
   }
  }
  if(e.jog.x<p.x && e.jog.y>p.y){
   pos.x=p.x-1;
   pos.y=p.y+1;
   if (possivel(e,pos)){
     e.monstros[i].x+=-1;
     e.monstros[i].y+=1;
   }
  }
  if(e.jog.x>p.x && e.jog.y>p.y){
    pos.x=p.x+1;
    pos.y=p.y+1;
    if (possivel(e,pos)){
     e.monstros[i].x+=1;
     e.monstros[i].y+=1;
   }
  }
  if(e.jog.x<p.x && e.jog.y<p.y){
     pos.x=p.x-1;
     pos.y=p.y-1;
   if (possivel(e,pos)){
     e.monstros[i].x+=-1;
     e.monstros[i].y+=-1;
   }
  }
  pos.y=p.y+1;
  if(e.jog.x==p.x && e.jog.y>p.y && possivel(e,pos)){
    e.monstros[i].y+=1;
  }
  pos.y=p.y-1;
  if(e.jog.x==p.x && e.jog.y<p.y && possivel(e,pos)){
    e.monstros[i].y+=-1;
  }
  pos.x=p.x+1;
  if(e.jog.y==p.y && e.jog.x>p.x && possivel(e,pos)){
    e.monstros[i].x+=1;
  }
  pos.x=p.x-1;
  if(e.jog.y==p.y && e.jog.x<p.x && possivel(e,pos)){
    e.monstros[i].x+=-1;
  }
 return e;
}
// PEDRAS
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
int primeira_livre (ESTADO e,POSICAO p){
  int i,j,k,r,flag0,flag1;
  POSICAO pos;
  flag0=flag1=1;k=r=0;pos.x=p.x;
  for(i=p.y;i>=0;i--){
     pos.y=i;
     if(!blocked1(e,pos)){
      i=0;
      flag0=0;
    }
    k--;
  }
  for(j=p.y;j<10;j++){
    pos.y=j;
    if(!blocked1(e,pos)){
      i=0;
      flag1=0;
    }
    r++;
  }
  if(flag0==1) k=10;
  if(flag1==1) r=10;
  if(r>abs(k)) k=r;
  return k;
}

POSICAO altera1(ESTADO e, POSICAO seguinte){
  POSICAO pos;
  pos.x=seguinte.x-1;
  pos.y=seguinte.y+1; 
  if(blocked1(e,pos))return seguinte;
  else{
    seguinte.x+=-1;
    seguinte.y+=1;
  }
  return seguinte;
}
POSICAO altera2(ESTADO e, POSICAO seguinte){
  POSICAO pos;
  pos.x=seguinte.x+1;
  pos.y=seguinte.y+1;
  if(blocked1(e,pos))return seguinte;
  else{
    seguinte.x+=1;
    seguinte.y+=1;
  }
  return seguinte;
}
POSICAO altera3(ESTADO e, POSICAO seguinte){
  POSICAO pos;
  pos.x=seguinte.x-1;
  pos.y=seguinte.y-1;
  if(blocked1(e,pos))return seguinte;
  else{
    seguinte.x+=-1;
    seguinte.y+=-1;
  }
  return seguinte;
}
POSICAO altera4(ESTADO e, POSICAO seguinte){
  POSICAO pos;
  pos.x=seguinte.x+1;
  pos.y=seguinte.y-1;
  if(blocked1(e,pos))return seguinte;
  else{
    seguinte.x+=1;
    seguinte.y+=-1;
  }
  return seguinte;
}
POSICAO *corrige (ESTADO e,POSICAO caminho[],POSICAO q,POSICAO intersect){
   POSICAO pos;
   int i;
   for(i=0;caminho[i].x != intersect.x && caminho[i].y != intersect.y;i++){
    if (caminho[0].x == q.x && caminho[0].y != q.y) break;
    i++;
     while(caminho[i].x != q.x && caminho[i].y != q.y){
      pos=caminho[i-1];
      if(q.y<caminho[i].y && q.x>caminho[i].x){
        pos.x+=-1;
        pos.y+=1;
        if(caminho[i].x!=pos.x && caminho[i].y != pos.y){
          caminho[i]=altera1(e,caminho[i-1]);
        }
      }
       if(q.y>caminho[i].y && q.x>caminho[i].x){
        pos.x+=1;
        pos.y+=1;
        if(caminho[i].x!=pos.x && caminho[i].y != pos.y){
          caminho[i]=altera2(e,caminho[i-1]);
        }
      }
        if(q.y<caminho[i].y && q.x<caminho[i].x){
        pos.x+=-1;
        pos.y+=-1;
        if(caminho[i].x!=pos.x && caminho[i].y != pos.y){
          caminho[i]=altera3(e,caminho[i-1]);
        }
      }
        if(q.y<caminho[i].y && q.x>caminho[i].x){
        pos.x+=1;
        pos.y+=-1;
        if(caminho[i].x!=pos.x && caminho[i].y != pos.y){
          caminho[i]=altera4(e,caminho[i-1]);
        }
      }
      i++;
    }
    while(caminho[i].x!=intersect.x && caminho[i].y != intersect.y){
      if(intersect.y<caminho[i].y){
        pos.x+=1;
        pos.y+=-1;
        if(caminho[i].x!=pos.x && caminho[i].y!=pos.y){
          caminho[i]=altera1(e,caminho[i-1]);
        }
      }
      if(intersect.y>caminho[i].y){
        pos.x+=1;
        pos.y+=1;
        if(caminho[i].x!=pos.x && caminho[i].y!=pos.y){
          caminho[i]=altera2(e,caminho[i-1]);
        }
      }
      if(q.y<caminho[i].y && q.x<caminho[i].x){
        pos.x+=-1;
        pos.y+=-1;
        if(caminho[i].x!=pos.x && caminho[i].y!=pos.y){
          caminho[i]=altera3(e,caminho[i-1]);
        }
      }
      if(q.y<caminho[i].y && q.x>caminho[i].x){
        pos.x+=1;
        pos.y+=-1;
        if(caminho[i].x!=pos.x && caminho[i].y!=pos.y){
          caminho[i]=altera4(e,caminho[i-1]);
        }
      }
      i++;
    }
  }
  return caminho;
}
void vertical(ESTADO e,POSICAO caminho[],int i){
  int diferenca;
  diferenca=primeira_livre(e,caminho[i]); // soma/subtrai posições ao y;
  if (diferenca > 0) caminho[i].y+=1;
  if (diferenca < 0) caminho[i].y+=-1;
}
int contacaminho(POSICAO caminho[],POSICAO q){
  int i=0;
  while(caminho[i].x!=q.x && caminho[i].y!=q.y){
    i++;
  }
  return i;
}
POSICAO tracker(ESTADO e,POSICAO p, POSICAO intersect){
  int i,flag1;
  POSICAO caminho[25],q,pos;
  flag1=1;
  caminho[0]=p;
  for(i=1;caminho[i].x!=intersect.x && caminho[i].y !=intersect.y;i++){// a paragem esta mal pode passar de uma posição para o intersect
      pos=caminho[i-1];
      if(blocked1(e,caminho[i])){
      flag1=0;
      }
      if(caminho[i-1].y<=intersect.y-1 && caminho[i-1].x<=intersect.x-1){ // pega no pos ant. e muda em direcao a intersect o valor seguinte
        pos.x+=1;
        pos.y+=1;
        if(possivel(e,pos)){
          caminho[i].x=caminho[i-1].x+1;
          caminho[i].y=caminho[i-1].y+1;
        }
        if(!possivel(e,caminho[i]) && !flag1){ // encontrar lugar mais proximo vago em filas de pedras 
           vertical(e,caminho,i);
           q=caminho[i];
           corrige(e,caminho,q,intersect);
           i=contacaminho(caminho,q);
        } 
      }
      if(caminho[i].y>=intersect.y+1 && caminho[i].x<=intersect.x-1){ 
        pos.x+=1;
        pos.y+=-1;
        if(possivel(e,pos)){
          caminho[i].x=caminho[i-1].x+1;
          caminho[i].y=caminho[i-1].y+-1;
        }
        if(!possivel(e,caminho[i]) && !flag1){  
           vertical(e,caminho,i);
           q=caminho[i];
           corrige(e,caminho,q,intersect);
           i=contacaminho(caminho,q);
        }  
      }  
      if(caminho[i].y<=intersect.y-1 && caminho[i].x>=intersect.x+1){ 
        pos.x+=-1;
        pos.y+=1;
        if(possivel(e,pos)){
          caminho[i].x=caminho[i-1].x+-1;
          caminho[i].y=caminho[i-1].y+1;
        }
        if(!possivel(e,caminho[i]) && !flag1){  
           vertical(e,caminho,i);
           q=caminho[i];
           corrige(e,caminho,q,intersect);
           i=contacaminho(caminho,q);
        } 
      }
      if(caminho[i].y>=intersect.y+1 && caminho[i].x>=intersect.x+1){ 
        pos.x+=-1;
        pos.y+=-1;
        if(possivel(e,pos)){
          caminho[i].x=caminho[i-1].x+-1;
          caminho[i].y=caminho[i-1].y+-1;
        }
        if(!possivel(e,caminho[i]) && !flag1){  
           vertical(e,caminho,i);
           q=caminho[i];
           corrige(e,caminho,q,intersect);
           i=contacaminho(caminho,q);
        }  
      }
      if(caminho[i-1].y==intersect.y && caminho[i-1].x<intersect.x){
        pos.x+=1;
        if (possivel(e,pos)){
          caminho[i].x=caminho[i-1].x+1;
        }
      }
       if(caminho[i-1].y==intersect.y && caminho[i-1].x>intersect.x){
         pos.x+=-1;
        if (possivel(e,pos)){
          caminho[i].x=caminho[i-1].x+-1;
        }
      }
      if(caminho[i-1].x==intersect.x && caminho[i-1].y<intersect.y){
        pos.y+=1;
       if(possivel(e,pos)){
        caminho[i].y=caminho[i-1].y+1;
       }
      }
       if(caminho[i-1].x==intersect.x && caminho[i-1].y>intersect.y){
        pos.y+=-1;
       if(possivel(e,pos)){
        caminho[i].y=caminho[i-1].y+-1;
       }
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

ESTADO defW1 (ESTADO e, int i,POSICAO p){
  POSICAO intersect,nova_pos;
  intersect= mapa1(e,p,1);
  nova_pos=tracker(e,p,intersect);
  e.monstros[i].x=nova_pos.x;
  e.monstros[i].y=nova_pos.y;
  return e;
}
ESTADO defW2 (ESTADO e, int i,POSICAO p){
  POSICAO intersect,nova_pos;
  intersect= mapa1(e,p,2);
  nova_pos=tracker(e,p,intersect);
  e.monstros[i].x=nova_pos.x;
  e.monstros[i].y=nova_pos.y;
  return e;
}
ESTADO defW3 (ESTADO e, int i,POSICAO p){
  POSICAO intersect,nova_pos;
  intersect= mapa1(e,p,3);
  nova_pos=tracker(e,p,intersect);
  e.monstros[i].x=nova_pos.x;
  e.monstros[i].y=nova_pos.y;
  return e;
}
ESTADO defW4 (ESTADO e, int i,POSICAO p){
  POSICAO intersect,nova_pos;
  intersect= mapa1(e,p,4);
  nova_pos=tracker(e,p,intersect);
  e.monstros[i].x=nova_pos.x;
  e.monstros[i].y=nova_pos.y;
  return e;
}

ESTADO estrat_wolf (ESTADO e,int i,POSICAO p){
  int flag=1;;
  if (existe_jogador(e,p)){
    e.hp-=WOLF_DMG;
  	flag=0;
  } // J M →ŧ
  if(flag && e.jog.x<=p.x && e.jog.y>=p.y && e.saida.x>=e.jog.x && e.saida.y<=e.jog.y){
    e=defW1(e,i,p);
    flag=0;
  } // J M←ŧ
  if(flag && e.jog.x>=p.x && e.jog.y>=p.y && e.saida.x<=e.jog.x && e.saida.y<=e.jog.y){
    e= defW2(e,i,p);
    flag=0;
  } // J M←↓
  if(flag && e.jog.x>=p.x && e.jog.y<=p.y && e.saida.x<=e.jog.x && e.saida.y>=e.jog.y){
    e=defW3(e,i,p);
    flag=0;
  } // J M→↓
  if(flag && e.jog.x<=p.x && e.jog.y<=p.y && e.saida.x>=e.jog.x && e.saida.y>=e.jog.y){
    e=defW4(e,i,p);
    flag=0;
  }
  // na persegue dá-se primasia as diagonais
  if(flag) e=persegue_wolf(e,i,p);
  return e;
}
