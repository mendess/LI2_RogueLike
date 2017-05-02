#include <stdio.h>
#include "IA.h"


ESTADO persegue_wolf (ESTADO e,int i,int p){
   if(e.jog.x>p.x && e.jog.y<p.y){
    if (possivel(e,p+(1,-1))){
      e.monstros[i].x+=1;
      e.monstros[i].y+=-1;
    }
   }
   if(e.jog.x<p.x && e.jog.y>p.y){
    if (possivel(e,p+(-1,1))){
      e.monstros[i].x+=-1;
      e.monstros[i].y+=1;
    }
   }
     if(e.jog.x>p.x && e.jog.y>p.y){
    if (possivel(e,p+(1,1))){
      e.monstros[i].x+=1;
      e.monstros[i].y+=1;
    }
   }
    if(e.jog.x<p.x && e.jog.y<p.y){
    if (possivel(e,p+(-1,-1))){
      e.monstros[i].x+=-1;
      e.monstros[i].y+=-1;
    }
   }
   if(e.jog.x==p.x && e.jog.y>p.y && possivel(e.p+(0,1))){
     e.monstros[i].y+=1;
     p+=(0,1);
   }
   if(e.jog.x==p.x && e.jog.y<p.y && possivel(e.p+(0,1))){
     e.monstros[i].y+=-1;
     p+=(0,-1);
   }
    if(e.jog.y==p.y && e.jog.x>p.x && possivel(e.p+(1,0))){
     e.monstros[i].x+=1;
   }
    if(e.jog.y==p.y && e.jog.x<p.x && possivel(e.p+(-1,0))){
     e.monstros[i].x+=-1;
   }
   return e;
}
























































































// PEDRAS
int blocked1 (ESTADO e,POSICAO p){
  int i,flag;
  flag=0;
  for(i=0;i<num_pedras;i++){
    if(e.pedras[i].x==p.x && e.pedras[i].y==p.y) flag=1;
  }
  return flag;
}
// MONSTROS
int blocked2 (ESTADO e,POSICAO p){
  int i,flag;
  flag=0;
  for(i=0;i<num_monstros;i++){
    if(e.monstros[i].x==p.x && e.monstros[i].y==p.y) flag=1;
  }
  return flag;
}

int possivel (ESTADO e,POSICAO p){
  int flag,i;
  flag=1;
  if(blocked1(e,p) || blocked2(e,p)) flag=0;
  return flag;
}
int primeira_livre (ESTADO e,POSICAO p){
  int i,j,k,r,flag0,flag1;
  POSICAO pos;
  flag0=flag1=1;k=0;pos.x=p.x;
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
  if(flag0=1) k=10;
  if(flag1=1) r=10;
  if(r>abs(k)) k=r;
  return k;
}

POSICAO altera1(ESTADO e, POSICAO seguinte){
  POSICAO pos;
  pos=seguinte+(1,-1); 
  if(blocked1(e,pos))return seguinte;
  else{
    seguinte+=(1,-1);
  }
  return seguinte;
}
POSICAO altera2(ESTADO e, POSICAO seguinte){
  POSICAO pos;
  pos=seguinte+(1,1); 
  if(blocked1(e,pos))return seguinte;
  else{
    seguinte+=(1,1);
  }
  return segunite;
}
POSICAO altera3(ESTADO e, POSICAO seguinte){
  POSICAO pos;
  pos=seguinte+(-1,-1); 
  if(blocked1(e,pos))return seguinte;
  else{
    seguinte+=(-1,-1);
  }
  return segunite;
}
POSICAO altera4(ESTADO e, POSICAO seguinte){
  POSICAO pos;
  pos=seguinte+(1,-1); 
  if(blocked1(e,pos))return seguinte;
  else{
    seguinte+=(1,-1);
  }
  return segunite;
}
void corrige (ESTADO e,POSICAO caminho[],POSICAO q,POSICAO intersect){
   for(i=0;caminho[i]!= intersect;i++){
    if (caminho[0]==q) break;
    i++;
     while(caminho[i]!= q){
      if(q.y<caminho[i].y && q.x>caminho[i].x){
        if(caminho[i]!=caminho[i-1]+(1,-1)){
          caminho[i]=altera1(e,caminho[i-1],q);
        }
      }
       if(q.y>caminho[i].y && q.x>caminho[i].x){
        if(caminho[i]!=caminho[i-1]+(1,1)){
          caminho[i]=altera2(e,caminho[i-1],q);
        }
      }
        if(q.y<caminho[i].y && q.x<caminho[i].x){
        if(caminho[i]!=caminho[i-1]+(-1,-1)){
          caminho[i]=altera3(e,caminho[i-1],q);
        }
      }
        if(q.y<caminho[i].y && q.x>caminho[i].x){
        if(caminho[i]!=caminho[i-1]+(1,-1)){
          caminho[i]=altera4(e,caminho[i-1],q);
        }
      }
      i++;
    }
    while(caminho[i]!=intersect){
      if(intersect.y<caminho[i].y){
        if(caminho[i]!=caminho[i-1]+(1,-1)){
          caminho[i]=altera1(e,caminho[i-1],q);
        }
      }
       if(intersect.y>caminho[i].y){
        if(caminho[i]!=caminho[i-1]+(1,1)){
          caminho[i]=altera2(e,caminho[i-1],q);
        }
      }
        if(q.y<caminho[i].y && q.x<caminho[i].x){
        if(caminho[i]!=caminho[i-1]+(-1,-1)){
          caminho[i]=altera3(e,caminho[i-1],q);
        }
      }
        if(q.y<caminho[i].y && q.x>caminho[i].x){
        if(caminho[i]!=caminho[i-1]+(1,-1)){
          caminho[i]=altera4(e,caminho[i-1],q);
        }
      }
      i++;
    }
  }

}
void vertical(ESTADO e,int caminho[],int i){
  int diferenca,q,lat;
  lat=0;
  diferenca=primeira_livre(e,caminho[i]); // soma/subtrai posições ao y;
  q=caminho[i]+(0,diferenca);
  if (diferença >0) caminho[i]=caminho[i]+(0,1);
  if (diferença >0) caminho[i]=caminho[i]+(0,-1);
}
POSICAO tracker(ESTADO e,POSICAO p, POSICAO intersect){
  int i,k,flag1,diferenca;
  POSICAO caminho[25],q;
  flag1=1;
  /*caminho1(caminho,intersect,p);
  k=contacaminho(caminho,intersect);*/
  caminho[0]=p;
  for(i=1;caminho[i]!=intersect;i++){// a paragem esta mal pode passar de uma posição para o intersect
    /*if(blocked1(e,caminho[i])){
      flag1=0;
      }*/
      if(caminho[i-1].y<=intersect.y-1 && caminho[i-1].x<=intersect.x-1){ // pega no pos ant. e muda em direcao a intersect o valor seguinte
        if(possivel(e,(caminho[i-1]+(1,1)))){
          caminho[i]=caminho[i-1]+(1,1);
        }
        if(!possivel(e,caminho[i]) && !flag1){ // encontrar lugar mais proximo vago em filas de pedras 
           vertical(e,caminho,i);
           q=caminho[i];
           corrige(e,caminho[],q,intersect);
           k=contacaminho(caminho);
        } 
      }
      if(caminho[i].y>=intersect.y+1 && caminho[i].x<=intersect.x-1){ 
        if(possivel(e,(caminho[i-1]+(1,-1)))){
          caminho[i]=caminho[i-1]+(1,-1);
        }
        if(!possivel(e,caminho[i]) && !flag1){  
           vertical(e,caminho,i);
           q=caminho[i];
           corrige(e,caminho[],q,intersect);
        }  
      }  
      if(caminho[i].y<=intersect.y-1 && caminho[i].x>=intersect.x+1){ 
        if(possivel(e,(caminho[i-1]+(-1,1)))){
          caminho[i]=caminho[i-1]+(-1,1);
        }
        if(!possivel(e,caminho[i]) && !flag1){  
           vertical(e,caminho,i);
           q=caminho[i];
           corrige(e,caminho[],q,intersect);
        } 
      }
      if(caminho[i].y>=intersect.y+1 && caminho[i].x>=intersect.x+1){ 
        if(possivel(e,(caminho[i-1]+(-1,-1)))){
          caminho[i]=caminho[i-1]+(-1,-1);
        }
        if(!possivel(e,caminho[i]) && !flag1){  
           vertical(e,caminho,i);
           q=caminho[i];
           corrige(e,caminho[],q,intersect);
        }  
      }
      // fazer aqui para caminho[i].y==intersect.y e para x o mesmo
  } 
 return caminho[1];
}








































POSICAO buscaW1 (ESTADO mov){
  int x,y,flag;
  POSICAO intersect;
  flag=1;
  for(y=0;y<10;y++){
    for(x=9;x>=0;x--){
       if(mov[x][y] == 0 && livre1(e,x,y) && flag){
         intersec=(x,y);
         flag=0;
       }
    }
  }
 return intersect;
}
POSICAO buscaW2 (ESTADO mov){
  int x,y,flag;
  POSICAO intersect;
  flag=1;
  for(y=9;y>=0;y--){
    for(x=0;x<10;x++){
      if(mov[x][y] == 0 && livre1(e,x,y) && flag){
         intersec=(x,y);
         flag=0;
       }
    }
  }
  return intersect;
}
POSICAO buscaW3 (ESTADO mov){
   int x,y,flag;
  POSICAO intersect;
  flag=1;
  for(y=0;y<10;y--){
    for(x=0;x<10;x++){
      if(mov[x][y] == 0 && livre1(e,x,y) && flag){
         intersec=(x,y);
         flag=0;
       }
    }
  }
  return intersect;
}
POSICAO buscaW4 (ESTADO mov){
   int x,y,flag;
  POSICAO intersect;
  flag=1;
  for(y=9;y>=0;y--){
    for(x=9;x>=0;x+--){
      if(mov[x][y] == 0 && livre1(e,x,y) && flag){
         intersec=(x,y);
         flag=0;
       }
    }
  }
  return intersect;
}
POSICAO mapa3 (Estado e,int i,POSICAO p,int q){
  int d,x,y,flag;
  int a[10][10];
  POSICAO intersect;
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
  if(q==1) intersect=buscaW1(a);
  if(q==2) intersect=buscaW2(a);
  if(q==3) intersect=buscaW3(a);
  if(q==4) intersect=buscaW4(a);
  return intersect;
}

ESTADO defB1 (ESTADO e, int i,POSICAO p){
  POSICAO intersect,nova_pos;
  intersect= mapa3(e,i,p,1);
  nova_pos=tracker(e,p,intersect);
  e.monstros[i]=nova_pos;
  return e;
}
ESTADO defB2 (ESTADO e, int i,POSICAO p){
  POSICAO intersect;
  intersect= mapa3(e,i,p,2);
  novapos=tracker(e,p,intersect);
  e.monstros[i]=nova_pos;
  return e;
}
ESTADO defB3 (ESTADO e, int i,POSICAO p){
  POSICAO intersect;
  intersect= mapa3(e,i,p,3);
  novapos=tracker(e,p,intersect);
  e.monstros[i]=nova_pos;
  return e;
}
ESTADO defB4 (ESTADO e, int i,POSICAO p){
  POSICAO intersect;
  intersect= mapa3(e,i,p,4);
  novapos=tracker(e,p,intersect);
  e.monstros[i]=nova_pos;
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
