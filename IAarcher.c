ESTADO persegue_arch(e,i,p){
  int flag=1;
  if(p.x>e.jog.x && abs(e.jog.y-p.y)<3 && possivel(e,p+(-1,0))){
    e.monstros[i].x+=(-1);
    flag=0;
  }
   if(flag && p.x<e.jog.x && abs(e.jog.y-p.y)<2 && possivel(e,p+(1,0))){
    e.monstros[i].x+=(-1);
    flag=0;
  }
  if(flag && p.y<e.jog.y && abs(e.jog.x-p.x)<2 && possivel(e,p+(0,1))){
    e.monstros[i].y+=1;
    flag=0;
  }
  if(flag && p.y>e.jog.y && abs(e.jog.x-p.x)<2 && possivel(e,p+(0,-1))){
    e.monstros[i].y+=(-1);
    flag=0;
  }
  return e;
}
POSICAO busca1(int a[][]){
   int i,x,y,flag;
  POSICAO intersect;
  flag=1;i=0;
  for(y=0;y<10;y++){
    for(x=0;x<10;x++){
       if(a[x][y] == 0 && i!=3){
         i++;
       }
       if(i==3 && livre1(e,x,y)){
        intersect=(x,y);
        x=10;
        y=10;
       }
    }
  }
 return intersect;
}
POSICAO busca2(int a[][]){
   int i,x,y,flag;
  POSICAO intersect;
  flag=1;i=0;
  for(y=0;y<10;y++){
    for(x=9;x>=0;x--){
       if(a[x][y] == 0 && i!=3){
         i++;
       }
       if(i==3 && livre1(e,x,y)){
        intersect=(x,y);
        x=-1;
        y=10;
       }
    }
  }
 return intersect;
}
POSICAO busca3(int a[][]){
   int i,x,y,flag;
  POSICAO intersect;
  flag=1;i=0;
  for(y=9;y>=0;y--){
    for(x=9;x>=0;x--){
       if(a[x][y] == 0 && i!=3){
         i++;
       }
       if(i==3 && livre1(e,x,y)){
        intersect=(x,y);
        x=-1;
        y=-1;
       }
    }
  }
 return intersect;
}
POSICAO busca4(int a[][]){
   int i,x,y,flag;
  POSICAO intersect;
  flag=1;i=0;
  for(y=0;y<10;y++){
    for(x=0;x<10;x++){
       if(a[x][y] == 0 && i!=3){
         i++;
       }
       if(i==3 && livre1(e,x,y)){
        intersect=(x,y);
        x=-1;
        y=10;
       }
    }
  }
 return intersect;
}
POSICAO mapa1 (Estado e,int i,POSICAO p,q){
  int d,x,y,flag;
  int a[10][10];
  POSICAO intersect;
  flag=1;
  for(y=0;y<10;y++){
    for(x=0;x<10;x++){
       if (abs(x-e.jog.x)>abs(y-e.jog.y){
          a[y][x]=abs(x-e.jog.x)-2;
       }
       if (abs(y-e.jog.y)>abs(x-e.jog.x){
          a[y][x]=abs(y-e.jog.y)-2;
       } 
    }
  }
  if(q==1) intersect=busca1(a);
  if(q==2) intersect=busca2(a);
  if(q==3) intersect=busca3(a);
  if(q==4) intersect=busca4(a);
  return intersect;
}
// pensar em condições dos 2 if das def

ESTADO decide(ESTADO e,int i, POSICAO intersect){
  int flag=1;
  if (intersect.x>e.monstros[i].x && possivel(e,e.monstros[i]+(1,0))){
      e.monstros[i].x+1;
      flag=0;
   }
   if (flag && intersect.x<e.monstros[i].x && possivel(e,e.monstros[i]+(-1,0))){
      e.monstros[i].x-1;
      flag=0;
   }
  if (flag && intersect.y>e.monstros[i].y && possivel(e,e.monstros[i]+(0,1))){
      e.monstros[i].y+1;
      flag=0;
   }
   if (flag && intersect.y<e.monstros[i].y && possivel(e,e.monstros[i]+(0,-1))){
      e.monstros[i].y-1;
      flag=0;
   }
}
ESTADO defA1 (ESTADO e, int i, POSICAO p){
   POSICAO intersect,nova_pos;
   intersect= mapa(e,i,p,1);
   e=decide(e,i,intersect);
   return e;
}
ESTADO defA2 (ESTADO e, int i, POSICAO p){
   POSICAO intersect,nova_pos;
   intersect= mapa(e,i,p,2);
   e=decide(e,i,intersect);
   return e;
}
ESTADO defA3 (ESTADO e, int i, POSICAO p){
   POSICAO intersect,nova_pos;
   intersect= mapa(e,i,p,3);
   e=decide(e,i,intersect);
   return e;
}
ESTADO defA4 (ESTADO e, int i, POSICAO p){
   POSICAO intersect,nova_pos;
   intersect= mapa(e,i,p,4);
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
     e=defA1(e,i,p);
     flag=0;
   } // J M←ŧ
   if(flag && e.jog.x>=p.x && e.jog.y>=p.y && e.saida.x<=e.jog.x && e.saida.y<=e.jog.y){
     e=defA2(e,i,p);
     flag=0;
   } // J M←↓
   if(flag && e.jog.x>=p.x && e.jog.y<=p.y && e.saida.x<=e.jog.x && e.saida.y>=e.jog.y){
     e=defA3(e,i,p);
     flag=0;
   } // J M→↓
   if(flag && e.jog.x<=p.x && e.jog.y<=p.y && e.saida.x>=e.jog.x && e.saida.y>=e.jog.y){
     e=defA4(e,i,p);
     flag=0;
   }
   // na persegue dá-se primasia as diagonais
   if(flag) e=persegue_arch(e,i,p);
   return e;
}