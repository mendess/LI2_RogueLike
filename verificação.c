int com_jogador (ESTADO e,POSICAO p){
	int com_jogador (ESTADO e,POSICAO p){
    int flag=0;
	if((e.jog.x == p.x) && (e.jog.y == p.y)) flag=1;
    return flag;
}
}
int com_monstros (ESTADO e, POSICAO p){
	int i,flag;
	flag=0;
	for (i=0;i<MAX_MONSTROS && !flag;i++){
		if (e.monstros[i].x == p.x && e.monstros[i].y == p.y){
			flag=1;
		}
	}
	return flag;
}
int com_pedras (ESTADO e, POSICAO p){
	int i,flag;
	flag=0;
	for(i=0;i<MAX_PEDRAS && !flag;i++){
		if (e.pedras[i].x == p.x && e.pedras[i].y == p.y){
			flag=1;
		}
	}
    return flag;
}

int pos_ocupada (ESTADO e, POSICAO p){
	return (com_jogador(e,p) || com_pedras(e,p) || com_monstros(e,p));
}


ESTADO criaestado(ESTADO e){
  int i,q,w;
  srandom(time(NULL));
  for (i=0;i<MAX_MONSTROS;i++){
    q=rand () % 10;
    w=rand () % 10;
    e.monstros[i].x=q;
    e.monstros[i].y=w;
    e.monstros[i].monType=3;
    e.monstros[i].hp=30;
  }
  e.jog.x=7;
  e.jog.y=7;
  return e;
}

int main (){
  ESTADO e,n;
  int i,m;
  e=criaestado (e);
  for (i=0;i<MAX_MONSTROS;i++){
      printf("(%d,%d)",e.monstros[i].x,e.monstros[i].y);
   }
  printf("  hp:%d\n",e.hp);
  n=move_monstros(e);
  for (i=0;i<MAX_MONSTROS;i++){
     printf("(%d,%d)",n.monstros[i].x,n.monstros[i].y);
   }
  printf("   hp:%d",e.hp);
  return 0;
}

 
