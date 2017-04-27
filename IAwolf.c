// falta persegue,busca3/4


int blocked1 (ESTADO e,POSICAO p){
  int i,flag;
  flag=0;
  for(i=0;i<num_pedras;i++){
    if(e.pedras[i].x==p.x && e.pedras[i].y==p.y) flag=1;
  }
  return flag;
}
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
/*
POSICAO desce (ESTADO e,POSICAO p){
  int flag;
  if (!blocked2(e,p+(1,1))){
   p.x++;
   p.y++;
   flag=0;
 }
 if (!blocked2(e,p+(0,1)) && flag){
   p.y++;
   flag=0;
 }
  if (!blocked2(e,p+(1,0)) && flag){
   p.x++;
 }
 return p;
}
POSICAO sobe (ESTADO e,POSICAO p){
  int flag;
  if (!blocked2(e,p+(1,-1))){
   p.x++;
   p.y--;
   flag=0;
 }
 if (!blocked2(e,p+(0,-1)) && flag){
   p.y--;
   flag=0;
 }
  if (!blocked2(e,p+(1,0)) && flag){
   p.x++;
 }
 return p;
}
*/
POSICAO altera1(ESTADO e, POSICAO seguinte){
  if(blocked1(e,seguinte+(1,-1)))return seguinte;
  else{
    seguinte+=(1,-1);
  }
  return segunite;
}
POSICAO altera2(ESTADO e, POSICAO seguinte){
  if(blocked1(e,seguinte+(1,1)))return seguinte;
  else{
    seguinte+=(1,1);
  }
  return segunite;
}
void corrige (ESTADO e,POSICAO caminho[],POSICAO q,POSICAO intersect){
   for(i=0;caminho[i]!= intersect;i++){
    if (caminho[0]==q) break;
    i++;
     while(caminho[i]!= q){
      if(q.y<caminho[i].y){
        if(caminho[i]!=caminho[i-1]+(1,-1)){
          caminho[i]=altera1(e,caminho[i-1],q);
        }
      }
       if(q.y>caminho[i].y){
        if(caminho[i]!=caminho[i-1]+(1,1)){
          caminho[i]=altera2(e,caminho[i-1],q);
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
      i++;
    }
    }
   }

}
POSICAO tracker(ESTADO e,POSICAO p, POSICAO intersect){
  int i,k,x,y,flag1,diferenca,w;
  POSICAO caminho[25],q;
  x=p.x+1;
  flag1=flag2=flag3=1;
  for(i=0;x!=intersect.x;i++){
     caminho[i]=(x,y);
     x++;
     k=i++;
  }
  for(i=k;y!=intersect.y;i++){
    caminho[i]=(x,y);
    y--;
    k=i++;
  } // por este processo noutra função
  q=caminho[0];
  if(p.x=<intersect.x && p.y>=intersect.y){ // constroi caminho
     for(i=0;i<k;i++){
        if(blocked1(e,caminho[i])){
          flag1=0;
        }
        if(caminho[i].y<intersect.y){
          if(possivel(e,(caminho[i]+(1,-1))){
            caminho[i].x++;
            caminho[i].y--;
            for(u=i;caminho[u]!=intersect;u++){
              caminho.[u].y--;
            }
          }
          if(!possivel(e,caminho[i]) && !flag1){ // encontrar lugar mais proximo vago 
             diferenca=primeira_livre(e,caminho[i]);
             q=caminho[i]+(0,diferenca);
             if (diferença >0) caminho[i]=caminho[i]+(0,1);
             if (diferença >0) caminho[i]=caminho[i]+(0,-1);
           }
           
          }
     }
  }
   corrige(caminho[],q,intersect);

}
ESTADO mapa1 (Estado e,int i,POSICAO p){
  int d,x,y,flag;
  int a[10][10];
  d=abs(e.jog.x-p.x)+abs(e.jog.y-p.y);
  flag=1;
  for(y=0;y<10;y++){
    for(x=0;x<10;x++){
       if (abs(x-e.jog.x)>abs(y-e.jog.y){
          a[y][x]=abs(x-e.jog.x)-d;
       }
       if (abs(y-e.jog.y)>abs(x-e.jog.x){
          a[y][x]=abs(y-e.jog.y)-d;
       } 
    }
  }
  return a;
}
POSICAO busca1 (ESTADO mov){
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
POSICAO busca2 (ESTADO mov){
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
POSICAO busca3 (ESTADO mov){
}
POSICAO busca4 (ESTADO mov){
}
ESTADO defB1 (ESTADO e, int i,POSICAO p){
  POSICAO intersect,nova_pos;
  ESTADO mov;
  mov= mapa1(ESTADO e,int i,POSICAO p);
  intersect=busca1 (mov);
  nova_pos=tracker(e,p,intersect);
  e.monstros[i].x=nova_pos.x;
  e.monstros[i].y=nova_pos.y;
  return e;
}
ESTADO defB2 (ESTADO e, int i,POSICAO p){
  POSICAO intersect;
  ESTADO mov;
  mov= mapa1(ESTADO e,int i,POSICAO p);
  intersect=busca2 (mov);
  novapos=tracker(e,p,intersect);
  e.monstros[i].x=nova_pos.x;
  e.monstros[i].y=nova_pos.y;
  return e;
}
ESTADO defB3 (ESTADO e, int i,POSICAO p){
  POSICAO intersect;
  ESTADO mov;
  mov= mapa1(ESTADO e,int i,POSICAO p);
  intersect=busca3 (mov);
  novapos=tracker(e,p,intersect);
  e.monstros[i].x=nova_pos.x;
  e.monstros[i].y=nova_pos.y;
  return e;
}
ESTADO defB4 (ESTADO e, int i,POSICAO p){
  POSICAO intersect;
  ESTADO mov;
  mov= mapa1(ESTADO e,int i,POSICAO p);
  intersect=busca4 (mov);
  novapos=tracker(e,p,intersect);
  e.monstros[i].x=nova_pos.x;
  e.monstros[i].y=nova_pos.y;
  return e;
}

ESTADO estrat_wolf (ESTADO e,int i,POSICAO p){
   int flag=1;;
   if (existe_jogador(e,p)){
      e.hp-=OGRE_DMG;
   		flag=0;
   } // J M →ŧ
   if(flag && e.jog.x<=p.x && e.jog.y>=p.y && e.saida.x>=e.jog.x && e.saida.y<=e.jog.y){
     e=defO1(e,i,p);
     flag=0;
   } // J M←ŧ
   if(flag && e.jog.x>=p.x && e.jog.y>=p.y && e.saida.x<=e.jog.x && e.saida.y<=e.jog.y){
     e= defO2(e,i,p);
     flag=0;
   } // J M←↓
   if(flag && e.jog.x>=p.x && e.jog.y<=p.y && e.saida.x<=e.jog.x && e.saida.y>=e.jog.y){
     e=defO3(e,i,p);
     flag=0;
   } // J M→↓
   if(flag && e.jog.x<=p.x && e.jog.y<=p.y && e.saida.x>=e.jog.x && e.saida.y>=e.jog.y){
     e=defO4(e,i,p);
     flag=0;
   }
   // na persegue dá-se primasia as diagonais
   if(flag) e=persegue2(e,i,p);
   return e;
}




  /*
             caminho[i].y+=diferenca;
             q=caminho[i];
             for(w=1;caminho[w]!=q;w++){
               if(q.y>caminho[0].y){
                 caminho[w]=desce(e,caminho[w-1]);
               }
               if(q.y<caminho[0].y){
                 caminho[w]=sobe(e,caminho[w-1]);
               }
             }
             for(i=w;x!=intersect.x;i++){
               caminho[i]=(x,y);
               x++;
               k=i++;
             }
             for(i=k;y!=intersect.y;i++){
               caminho[i]=(x,y);
               y--;
               k=i++;
             }
             */
           /*  if(diferenca<0){
               for(u=i;(caminho[u].y)-(caminho[u-1].y)>1;u++){ // altera caminho anterior para ligar tudo
                 if(possivel(e,(caminho[i]+(-1,1))){
                    caminho[i].x--;
                    caminho[i].y++;
                 }
                 if(possivel(e,(caminho[i]+(0,1)) && flag){
                   caminho[i].y++;
                   flag3=0;
                 }
                  if(possivel(e,(caminho[i]+(-1,0)) && flag){
                   caminho[i].x--;
                   flag3=0;
                 }
                 flag3=1;
               }
             }
             if(diferenca>0){
               for(u=i;(caminho[u].y)-(caminho[u-1].y)>1;u++){
                 if(possivel(e,(caminho[i]+(-1,-1))){
                   caminho[i].x--;
                   caminho[i].y--;
                   flag3=0;
                 }
                 if(possivel(e,(caminho[i]+(0,-1)) && flag){
                   caminho[i].y--;
                   flag3=0;
                 }
                  if(possivel(e,(caminho[i]+(-1,0)) && flag){
                   caminho[i].x--;
                   flag3=0;
                 }
                 flag3=1;
               }
             }*/