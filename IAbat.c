// falta persegue,busca3/4


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

int livre (ESTADO e,int x,int y){
  int i,flag;
  flag=1;
  for(i=0;i<num_monstros;i++){
     if (e.monstros[i].x==x && e.monstros[i].y==y) flag=0;
  }
  return flag;
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
ESTADO estrat_bat1 (ESTADO e, int i, POSICAO intersect){
   POSICAO p;
   p.x=e.monstros[i].x;
   p.y=e.monstros[i].y;
   if (p.x > intersect.x && livre1(e,p.x+1,p.y)) e.monstros[i].x+1;
   if (p.y < intersect.y && livre1(e,p.x,p.y-1)) e.monstros[i].y-1;
   if (p.x < intersect.x && livre1(e,p.x-1,p.y)) e.monstros[i].x-1;
   if (p.y > intersect.y && livre1(e,p.x,p.y-1)) e.monstros[i].y+1;
   return e;
}

ESTADO defB1 (ESTADO e, int i,POSICAO p){
  POSICAO intersect;
  ESTADO mov;
  mov= mapa1(ESTADO e,int i,POSICAO p);
  intersect=busca1 (mov);
  e=estrat_bat1(e,i,intersect);
  return e;
}
ESTADO defB2 (ESTADO e, int i,POSICAO p){
  POSICAO intersect;
  ESTADO mov;
  mov= mapa1(ESTADO e,int i,POSICAO p);
  intersect=busca2 (mov);
  e=estrat_bat1(e,i,intersect);
  return e;
}
ESTADO defB3 (ESTADO e, int i,POSICAO p){
  POSICAO intersect;
  ESTADO mov;
  mov= mapa1(ESTADO e,int i,POSICAO p);
  intersect=busca3 (mov);
  e=estrat_bat1(e,i,intersect);
  return e;
}
ESTADO defB4 (ESTADO e, int i,POSICAO p){
  POSICAO intersect;
  ESTADO mov;
  mov= mapa1(ESTADO e,int i,POSICAO p);
  intersect=busca4 (mov);
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
   if(flag) e=persegue1(e,i,p);
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

