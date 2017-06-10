#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "IA.h"


ESTADO persegue_NO(ESTADO e,int a[SIZE][SIZE],int i,POSICAO p){
	int x,y,flag;
	flag=1;
	y=p.y-1;
	x=p.x-1;
	if(a[p.x][y]!=50 && a[p.x][y]<= a[p.x][p.y] && y>=0){
		e.monstros[i].y-=1;
		flag=0;
	}
	if(flag && a[x][p.y]!=50 && a[x][p.y]<=a[p.x][p.y] && x>=0){
		e.monstros[i].x-=1;
		flag=0;
	}
	y=p.y+1;
	x=p.x+1;
	if(flag && a[x][p.y]!=50 && a[x][p.y]<=a[p.x][p.y] && x<10){
		e.monstros[i].x+=1;
		flag=0;
	}
	if(flag && a[p.x][y]!=50 && a[p.x][y]<= a[p.x][p.y] && y<10){
		e.monstros[i].y+=1;
	}
	return e;
}
ESTADO persegue_SO(ESTADO e,int a[SIZE][SIZE],int i,POSICAO p){
	int x,y,flag;
	flag=1;
	y=p.y+1;
	x=p.x-1;
	if(a[p.x][y]!=50 && a[p.x][y]<= a[p.x][p.y] && y<10){
		e.monstros[i].y+=1;
		flag=0;
	}
	if(flag && a[x][p.y]!=50 && a[x][p.y]<=a[p.x][p.y] && x>=0){
		e.monstros[i].x-=1;
		flag=0;
	}
	y=p.y-1;
	x=p.x+1;
	if(flag && a[x][p.y]!=50 && a[x][p.y]<=a[p.x][p.y] && x<10){
		e.monstros[i].x+=1;
		flag=0;
	}
	if(flag && a[p.x][y]!=50 && a[p.x][y]<= a[p.x][p.y] && y>=0){
		e.monstros[i].y-=1;
	}
	return e;
}
ESTADO persegue_NE(ESTADO e,int a[SIZE][SIZE],int i,POSICAO p){
	int x,y,flag;
	flag=1;
	y=p.y-1;
	x=p.x+1;
	if(a[p.x][y]!=50 && a[p.x][y]<= a[p.x][p.y] && y>=0){
		e.monstros[i].y-=1;
		flag=0;
	}
	if(flag && a[x][p.y]!=50 && a[x][p.y]<=a[p.x][p.y] && x<10){
		e.monstros[i].x+=1;
		flag=0;
	}
	y=p.y+1;
	x=p.x-1;
	if(flag && a[x][p.y]!=50 && a[x][p.y]<=a[p.x][p.y] && x>=0){
		e.monstros[i].x-=1;
		flag=0;
	}
	if(flag && a[p.x][y]!=50 && a[p.x][y]<= a[p.x][p.y] && y<10){
		e.monstros[i].y+=1;
	}
	return e;
}
ESTADO persegue_SE(ESTADO e,int a[SIZE][SIZE],int i,POSICAO p){
	int x,y,flag;
	flag=1;
	y=p.y+1;
	x=p.x+1;
	if(a[p.x][y]!=50 && a[p.x][y]<= a[p.x][p.y] && y<10){
		e.monstros[i].y+=1;
		flag=0;
	}
	if(flag && a[x][p.y]!=50 && a[x][p.y]<=a[p.x][p.y] && x<10){
		e.monstros[i].x+=1;
		flag=0;
	}
	y=p.y-1;
	x=p.x-1;
	if(flag && a[x][p.y]!=50 && a[x][p.y]<=a[p.x][p.y] && x>=0){
		e.monstros[i].x-=1;
		flag=0;
	}
	if(flag && a[p.x][y]!=50 && a[p.x][y]<= a[p.x][p.y] && y>=0){
		e.monstros[i].y-=1;
	}
	return e;
}
ESTADO persegue_arch(ESTADO e,int a[SIZE][SIZE],int i,POSICAO p){
	int flag=1;
	if (p.x>=e.jog.x && p.y>=e.jog.y){
		e=persegue_NO(e,a,i,p);
		flag=0;
	}
	if (p.x>=e.jog.x && p.y<=e.jog.y && flag){
		e=persegue_SO(e,a,i,p);
		flag=0;
	}
	if(p.x<=e.jog.x && p.y>=e.jog.y && flag){
		e=persegue_NE(e,a,i,p);
		flag=0;
	}
	if(p.x<=e.jog.x && p.y<=e.jog.y && flag){
		e=persegue_SE(e,a,i,p);
	}
	return e;
}
ESTADO desvia_right(int a[SIZE][SIZE],ESTADO e,int i,POSICAO p){
	int flag=1;
	if(a[p.x+1][p.y] != 50 && (p.x+1)<10){
		e.monstros[i].x+=1;
		flag=0;
	}
	if(a[p.x][p.y+1] != 50 && (p.y+1)<10 && flag){
		e.monstros[i].y+=1;
		flag=0;
	}
	if(a[p.x][p.y-1] != 50 && (p.y-1)>=0 && flag){
		e.monstros[i].y-=1;
	}
	return e;
}
ESTADO desvia_left(int a[SIZE][SIZE],ESTADO e,int i,POSICAO p){
	int flag=1;
	if(a[p.x-1][p.y] != 50 && (p.x-1)>=0){
		e.monstros[i].x-=1;
		flag=0;
	}
	if(a[p.x][p.y+1] != 50 && (p.y+1)<10 && flag){
		e.monstros[i].y+=1;
		flag=0;
	}
	if(a[p.x][p.y-1] != 50 && (p.y-1)>=0 && flag){
		e.monstros[i].y-=1;
	}
	return e;
}
ESTADO desvia_down(int a[SIZE][SIZE],ESTADO e,int i,POSICAO p){
	int flag=1;
	if(a[p.x][p.y+1] != 50 && (p.y+1)<10){
		e.monstros[i].y+=1;
		flag=0;
	}
	if(a[p.x+1][p.y] != 50 && (p.x+1)<10 && flag){
		e.monstros[i].x+=1;
		flag=0;
	}
	if(a[p.x-1][p.y] != 50 && (p.x-1)>=0 && flag){
		e.monstros[i].x-=1;
	}
	return e;
}
ESTADO desvia_up(int a[SIZE][SIZE],ESTADO e,int i,POSICAO p){
	int flag=1;
	if(a[p.x][p.y-1] != 50 && (p.y-1)>=0){
		e.monstros[i].y-=1;
		flag=0;
	}
	if(a[p.x+1][p.y] != 50 && (p.x+1)<10 && flag){
		e.monstros[i].x+=1;
		flag=0;
	}
	if(a[p.x-1][p.y] != 50 && (p.x-1)>=0 && flag){
		e.monstros[i].x-=1;
	}
	return e;
}
ESTADO desvia(ESTADO e,int a[SIZE][SIZE],int i,POSICAO p){
	if(p.x>e.jog.x){
		e=desvia_right(a,e,i,p);
	}
	if(p.x<e.jog.x){
		e=desvia_left(a,e,i,p);
	}
	if(p.y>e.jog.y){
		e=desvia_down(a,e,i,p);
	}
	if(p.y<e.jog.y){
		e=desvia_up(a,e,i,p);
	}
	return e;
}
int in_range(ESTADO e,POSICAO p){
	int flag=0;
	if(abs(p.x-e.jog.x)+abs(p.y-e.jog.y)<=3) flag=2;
	if(abs(p.x-e.jog.x)+abs(p.y-e.jog.y)==1) flag=1;
	return flag;
}
ESTADO defArcher_NO (ESTADO e,int a[SIZE][SIZE], int i, POSICAO p){
	int x,y,flag;
	flag=1;
	y=p.y+1;
	x=p.x+1;
	if(a[p.x][y]!=50 && a[p.x][y]<= a[p.x][p.y] && y<10){
		e.monstros[i].y+=1;
		flag=0;
	}
	if(flag && a[x][p.y]!=50 && a[x][p.y]<=a[p.x][p.y] && x<10){
		e.monstros[i].x+=1;
		flag=0;
	}
	y=p.y-1;
	x=p.x-1;
	if(flag && a[x][p.y]!=50 && a[x][p.y]<=a[p.x][p.y] && x>=0){
		e.monstros[i].x-=1;
		flag=0;
	}
	if(flag && a[p.x][y]!=50 && a[p.x][y]<= a[p.x][p.y] && y>=0){
		e.monstros[i].y-=1;
	}
	return e;
}
ESTADO defArcher_NE (ESTADO e,int a[SIZE][SIZE],int i, POSICAO p){
	int x,y,flag;
	flag=1;
	y=p.y+1;
	x=p.x-1;
	if(a[p.x][y]!=50 && a[p.x][y]<= a[p.x][p.y] && y<10){
		e.monstros[i].y+=1;
		flag=0;
	}
	if(flag && a[x][p.y]!=50 && a[x][p.y]<=a[p.x][p.y] && x>=0){
		e.monstros[i].x-=1;
		flag=0;
	}
	y=p.y-1;
	x=p.x+1;
	if(flag && a[x][p.y]!=50 && a[x][p.y]<=a[p.x][p.y] && x<10){
		e.monstros[i].x+=1;
		flag=0;
	}
	if(flag && a[p.x][y]!=50 && a[p.x][y]<= a[p.x][p.y] && y>=0){
		e.monstros[i].y-=1;
	}
	return e;
}
ESTADO defArcher_SO (ESTADO e,int a[SIZE][SIZE],int i, POSICAO p){
	int x,y,flag;
	flag=1;
	y=p.y-1;
	x=p.x+1;
	if(a[p.x][y]!=50 && a[p.x][y]<= a[p.x][p.y] && y>=0){
		e.monstros[i].y-=1;
		flag=0;
	}
	if(flag && a[x][p.y]!=50 && a[x][p.y]<=a[p.x][p.y] && x<10){
		e.monstros[i].x+=1;
		flag=0;
	}
	y=p.y+1;
	x=p.x-1;
	if(flag && a[x][p.y]!=50 && a[x][p.y]<=a[p.x][p.y] && x>=0){
		e.monstros[i].x-=1;
		flag=0;
	}
	if(flag && a[p.x][y]!=50 && a[p.x][y]<= a[p.x][p.y] && y<10){
		e.monstros[i].y+=1;
	}
	return e;
}
ESTADO defArcher_SE (ESTADO e,int a[SIZE][SIZE],int i, POSICAO p){
	int x,y,flag;
	flag=1;
	y=p.y-1;
	x=p.x-1;
	if(a[p.x][y]!=50 && a[p.x][y]<= a[p.x][p.y] && x>=0){
		e.monstros[i].y-=1;
		flag=0;
	}
	if(flag && a[x][p.y]!=50 && a[x][p.y]<=a[p.x][p.y] && y>=0){
		e.monstros[i].x-=1;
		flag=0;
	}
	y=p.y+1;
	x=p.x+1;
	if(flag && a[x][p.y]!=50 && a[x][p.y]<=a[p.x][p.y] && x<10){
		e.monstros[i].x+=1;
		flag=0;
	}
	if(flag && a[p.x][y]!=50 && a[p.x][y]<= a[p.x][p.y] && y<10){
		e.monstros[i].y+=1;
	}
	return e;
}
// i-> valor da prox casa
void distancia_ARCHER (ESTADO e,int a[SIZE][SIZE],int x,int y,int i){
	int a1,a2;
	POSICAO pos;
	if(x>=0 && x<10 && y<10 && y>=0){
		pos.x=x;
		pos.y=y;
		if(!com_pedras(e,pos) && i<a[x][y] && !com_monstros(e,pos)){
			a[x][y]=i;
			i++;
			for(a1=x-1;a1<=x+1;a1++){
					if(a1!=x){
						distancia_ARCHER(e,a,a1,y,i);
					}
			}
			for(a2=y-1;a2<=y+1;a2++){
					if(a2!=y){
						distancia_ARCHER(e,a,x,a2,i);
					}
			}
		}
	}
}
ESTADO estrat_archer (ESTADO e,int i,POSICAO p){
	int flag=1;
	int a[SIZE][SIZE];
	preenche_matriz(a);
	distancia_ARCHER(e,a,e.jog.x,e.jog.y,0);
	if(in_range(e,p)==1){
		e=desvia(e,a,i,p);
		if(p.x!=e.monstros[i].x || p.y!=e.monstros[i].y) flag=0;
	}
	if(in_range(e,p)==2){
		e.hp-=ARCHER_DMG;
		flag=0;
	}
	// J M →ŧ
	if(flag && BLOQUEAVEL_NO){
		e=defArcher_NO(e,a,i,p);
		flag=0;
	} // J M←ŧ
	if(flag && BLOQUEAVEL_NE){
		e=defArcher_NE(e,a,i,p);
		flag=0;
	} // J M←↓
	if(flag && BLOQUEAVEL_SE){
		e=defArcher_SE(e,a,i,p);
		flag=0;
	} // J M→↓
	if(flag &&  BLOQUEAVEL_SO){
		e=defArcher_SO(e,a,i,p);
		flag=0;
	}
	if(flag) e=persegue_arch(e,a,i,p);
		return e;
}
